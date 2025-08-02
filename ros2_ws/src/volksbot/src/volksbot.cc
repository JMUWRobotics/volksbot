/////////////////////////////////////////////////////////////////////////////
// @file    volksbot.cc
// @brief   broadcasting automatic detection and selection of rover configuration
// @author  Nico Schubert
// @date    26.06.2025
/////////////////////////////////////////////////////////////////////////////

#include "volksface/volksbot.h"


//-----------------------------------------------------------------------------
// LIBRARIES
//-----------------------------------------------------------------------------

// backend libraries
#include <unistd.h>
#define ACCESS_PERMITTED 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

// internet libraries
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#include "yaml-cpp/yaml.h"

// ros libraries
#include <chrono>
using namespace std::chrono_literals;

#include <rclcpp/rclcpp.hpp>



//-----------------------------------------------------------------------------
// PRECOMPILER FOR FORMAT HIGHLIGHTING
//-----------------------------------------------------------------------------

#define STR(s) #s
#define XSTR(s) STR(s)
#define COL(c, s) "\x1b[" STR(c) "m" s "\x1b[0m"

#define S_AVAIL COL(32, "AVAILABLE")
#define S_NOT_AVAIL COL(31, "NOT AVAILABLE")

#define SIZE_STATUS 13
#define SIZE_FORMAT_OFFSET ((int)sizeof( COL(31, "") )-1)
#define SIZE_FORMAT ( SIZE_STATUS + SIZE_FORMAT_OFFSET )



using namespace VB;

//-----------------------------------------------------------------------------
// STATIC STATE VARIABLES FOR BACKEND
//-----------------------------------------------------------------------------

static std::string PATH_YAML_ROVERS = "src/volksbot/cfg/rovers.yaml";

static constexpr int COUNT_PING_TRIES = 5;
static constexpr auto TIME_PUB_PERIOD_TICKS = 1min;

static rclcpp::Node::SharedPtr node;
static rclcpp::Publisher<msg::Rover>::SharedPtr pub_rover;
static rclcpp::TimerBase::SharedPtr timer;


//-----------------------------------------------------------------------------
// ROVER PARSING AND IMPLEMENTATION
//-----------------------------------------------------------------------------

// fallback dummy when no rover could be detected
static const Rover ROVER_DUMMY {
    "Dummy",
    1.00,   // non zero to avoid divide-by-zero exceptions
    1.00,   // non zero to avoid divide-by-zero exceptions
    MCD::ERROR,
    "",
    "",
    ip_t( 0xff, 0xff, 0xff, 0xff )
};

static std::vector<Rover> rovers;
static const Rover* active_rover = &ROVER_DUMMY;


bool parse_rover( const YAML::Node rover_map, Rover& out_rover ) {
    if( !rover_map.IsMap() ) {
        printf( COL(31, "could not parse rover: invalide yaml input\n") );
        return false;
    }

    if( !rover_map["name"]                   ||
        !rover_map["wheel_diameter"]         ||
        !rover_map["wheel_base"]             ||
        !rover_map["motor_controller"]       ||
        !rover_map["motor_controller_port"]  ||
        !rover_map["udev_symlink"]           ||
        !rover_map["ip_lms"]                 
    ) {
        printf( COL(31, "could not parse rover: not all parameters supplied\n") );
        return false;
    }

    std::string name, motor_controller, motor_controller_port, udev_symlink, ip_lms;
    float wheel_diameter, wheel_base;

    name                  = rover_map["name"]                 .as<std::string>();
    wheel_diameter        = rover_map["wheel_diameter"]       .as<float>();
    wheel_base            = rover_map["wheel_base"]           .as<float>();
    motor_controller      = rover_map["motor_controller"]     .as<std::string>();
    motor_controller_port = rover_map["motor_controller_port"].as<std::string>();
    udev_symlink          = rover_map["udev_symlink"]         .as<std::string>();
    ip_lms                = rover_map["ip_lms"]               .as<std::string>();

    MCD::MCD mcd = MCD::from_string( motor_controller );
    
    ip_t ip;
    if( !ip_t::from_string( ip_lms, ip ) ) { // invalide ipv4
        return false;
    }

    out_rover.name                  = name;
    out_rover.wheel_diameter        = wheel_diameter;
    out_rover.wheel_base            = wheel_base;
    out_rover.motor_controller      = mcd;
    out_rover.motor_controller_port = motor_controller_port;
    out_rover.udev_symlink          = udev_symlink;
    out_rover.ip_lms                = ip;

    return true;
}

void parse_yaml( const std::string& file_path ) {
    std::vector<YAML::Node> rovs = YAML::LoadAllFromFile( file_path );

    size_t max_name_len = 0;
    for( const YAML::Node& rov : rovs ) {
        Rover out;
        if( parse_rover( rov, out ) ) {
            max_name_len = out.name.length() > max_name_len ? out.name.length() : max_name_len;
            rovers.push_back( std::move(out) );
        }
    }
    
    for( const Rover& rov : rovers ) {
        printf( "> parsed Rover: " COL(32, "%*s") " (" COL(32, "%s") ", " COL(32, "%s") ")\n",
            (int)max_name_len, rov.name.c_str(),
            rov.ip_lms.to_string(3).c_str(),
            MCD::to_string( rov.motor_controller ).c_str()
        );
    }

    printf("\n");
}

//-----------------------------------------------------------------------------
// PINGING IMPLEMENTATION
//-----------------------------------------------------------------------------

#define PACKETSIZE  64
struct packet {
    struct icmphdr hdr;
    char msg[PACKETSIZE-sizeof(icmphdr)];
};

/**
 * @brief ones complement checksum for icmp pings
 * 
 * @param b package as byte array
 * @param len length in bytes of package
 * @return unsigned short ones complement of checksum
 */
unsigned short checksum(const void *b, int len) {
    unsigned short *buf = (unsigned short*)b;
    
    unsigned int sum=0;
    for ( ; len > 1; len -= 2 )
        sum += *buf++;

    if ( len == 1 )
        sum += *buf;
    
    sum  = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    return ~sum;
}

/**
 * @brief pinging an ip address
 * 
 * @param ip static ipv4 ip address to ping
 * @return int 0 if ping OK else 1 if ping not OK
 */
int ping( const ip_t ip ) {
    static int cnt=1;
    const int val=255;

    int pid = getpid();
    protoent *proto = getprotobyname("ICMP");
    
    sockaddr_in addr_ping;
    bzero(&addr_ping, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = ip.raw;
    
    sockaddr_in *addr = &addr_ping;
    
    int sd = socket(PF_INET, SOCK_DGRAM, proto->p_proto);
    if ( sd < 0 ) {
        perror("socket");
        return 1;
    }
    if ( setsockopt(sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0) {
        perror("Set TTL option");
        return 1;
    }
    if ( fcntl(sd, F_SETFL, O_NONBLOCK) != 0 ) {
        perror("Request nonblocking I/O");
        return 1;
    }
    

    // move cursor right of the status output
    printf( "\x1b[" XSTR(SIZE_STATUS) "C " );

    packet pckt;
    sockaddr_in r_addr;
    for( int loop=0; loop < COUNT_PING_TRIES; loop++ ) {
        socklen_t len = sizeof(r_addr);

        printf( "ping: %2d / %2d\x1b[13D", loop+1, COUNT_PING_TRIES );
        fflush( stdout );

        if ( recvfrom(sd, &pckt, sizeof(pckt), 0, (sockaddr*)&r_addr, &len) > 0 ) {
            printf( "\x1b[%dD%*s%*s\n", SIZE_STATUS+1, SIZE_FORMAT, S_AVAIL, 14, "" );
            return 0;
        }

        bzero(&pckt, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = pid;

        for ( unsigned long i = 0; i < sizeof(pckt.msg)-1; i++ )
            pckt.msg[i] = i+'0';
        
        pckt.msg[sizeof(pckt.msg)-1] = 0;
        pckt.hdr.un.echo.sequence = cnt++;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));
        
        if ( sendto(sd, &pckt, sizeof(pckt), 0, (sockaddr*)addr, sizeof(*addr)) <= 0 ) {
            // use logging instead
            // perror("sendto");
        }

        usleep(300000);
    }
    
    printf( "\x1b[%dD%*s%*s\n", SIZE_STATUS+1, SIZE_FORMAT, S_NOT_AVAIL, 14, "" );
    return 1;
}
int ping( const char *adress ) {
    return ping( ip_t( *(long*)gethostbyname(adress)->h_addr ) );
}
#define PING_SUCCESSFUL 0


//-----------------------------------------------------------------------------
// ROS SPECIFIC IMPLEMENTATIONS
//-----------------------------------------------------------------------------

/**
 * @brief finds best matching rover configuration by regarding the mapped udev ports and static lms ips
 * 
 * @return true if a new rover configuration was selected
 * @return false if the rover configuration is unchanged
 */
bool find_rover() {
    #define CVAR 35

    uint64_t current_hash = hash(active_rover);

    std::vector<uint> matches;
    matches.reserve( rovers.size() );
    

    // setup formatting specifiers --------------------------------------------
    constexpr int str_len_ip = sizeof( "xxx.xxx.xxx.xxx" )-1;
    int max_name_len = 0, max_port_len = str_len_ip;
    for( uint i=0; i < rovers.size(); i++ ) {
        int name_len = rovers[i].name.length();
        if( name_len > max_name_len )
            max_name_len = name_len;

        int port_len = rovers[i].udev_symlink.length();
        if( port_len > max_port_len )
            max_port_len = port_len;
    }
    
    static bool first_execution = true;
    if( !first_execution ) {
        // jump back up, so that we overwrite the table on the next look up round
        printf( "\x1b[%ldF", 1+2*rovers.size() + 1+rovers.size()+3 );
        printf( "\x1b[0J" ); // clear from cursor to end of screen
    }
    first_execution = false;

    printf( "============================================================\n" );
    

    // preprint table ---------------------------------------------------------
    for( uint i=0; i < rovers.size(); i++ ) {
        printf( "[" COL(CVAR, "%*s") "] udev port (" COL(CVAR, "%-*s") "): %*s\n",
            max_name_len, rovers[i].name.c_str(),
            max_port_len, rovers[i].udev_symlink.c_str(),
            SIZE_FORMAT,
            COL(90, "...unknown...")
        );

        printf( "[" COL(CVAR, "%*s") "]        ip (" COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "%*s): %*s\n",
            max_name_len, rovers[i].name.c_str(),
            rovers[i].ip_lms.ip.hh, 
            rovers[i].ip_lms.ip.hl, 
            rovers[i].ip_lms.ip.lh, 
            rovers[i].ip_lms.ip.ll,
            MAX(0, max_port_len - str_len_ip),
            "",
            SIZE_FORMAT,
            COL(90, "...unknown...")
        );
    }
    printf( "\x1b[%ldF", 2*rovers.size() ); // jump back up
    

    // main search ------------------------------------------------------------
    for( uint i=0; i < rovers.size(); i++ ) {
        matches[i] = 0;

        // search ports
        bool port = access( rovers[i].udev_symlink.c_str(), F_OK ) == ACCESS_PERMITTED;
        if( port ) {
            matches[i]++;
        }
        printf( "[" COL(CVAR, "%*s") "] udev port (" COL(CVAR, "%-*s") "): %*s\n",
            max_name_len, rovers[i].name.c_str(),
            max_port_len, rovers[i].udev_symlink.c_str(),
            SIZE_FORMAT,
            port ? S_AVAIL : S_NOT_AVAIL
        );

        // search ips
        printf( "[" COL(CVAR, "%*s") "]        ip (" COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "%*s): ",
            max_name_len, rovers[i].name.c_str(),
            rovers[i].ip_lms.ip.hh, 
            rovers[i].ip_lms.ip.hl, 
            rovers[i].ip_lms.ip.lh, 
            rovers[i].ip_lms.ip.ll,
            MAX(0, max_port_len - str_len_ip),
            ""
        );
        if( ping( rovers[i].ip_lms ) == PING_SUCCESSFUL ) {
            matches[i]++;
        }
    }
    

    // select best fit
    printf( "\n----------------------------------------\n" );
    int best_index = -1;
    uint best_match = 0;
    for( uint i=0; i < rovers.size(); i++) {
        printf( "[" COL(CVAR, "%*s") "] matches: " COL(CVAR, "%d") "\n", max_name_len, rovers[i].name.c_str(), matches[i] );
        if( matches[i] > best_match ) {
            best_index = i;
            best_match = matches[i];
        }
    }

    // manage selected
    active_rover = best_index == -1 ? &ROVER_DUMMY : &rovers[best_index];
    bool changed = hash(active_rover) != current_hash;

    printf( "\nRover:   \x1b[3%cm%*s\x1b[0m    %s\n",
        best_index == -1 ? '1' : '2',
        max_name_len, best_index == -1 ? "NOT FOUND" : rovers[best_index].name.c_str(),
        changed ? COL(103;30, " NEW ROVER ") : COL(90, "not changed")
    );

    return changed;
}

void find_and_publish() {
    if( find_rover() ) {
        VB::msg::Rover rov = to_message( *active_rover, hash( active_rover ) != hash( &ROVER_DUMMY ) );
        pub_rover->publish( rov );
    }
}



int main(int argc, char* argv[]) {
    signal(SIGINT, [](int sig){
        (void)sig;
        rclcpp::shutdown();
        exit(0);
    });
    
    printf( "\x1b[2J\x1b[1;1H" ); // clear screen
    parse_yaml( PATH_YAML_ROVERS );

    rclcpp::init(argc, argv);
    
    node = std::make_shared<rclcpp::Node>("volksbot_rover");
    
    pub_rover = node->create_publisher<msg::Rover>( TOPIC_NAME_ROVER, 1 );
    
    timer = node->create_wall_timer( TIME_PUB_PERIOD_TICKS, find_and_publish );

    find_and_publish();

    rclcpp::spin( node );
    rclcpp::shutdown();

    // if( argc >= 5 ) {
    //     auto ip = ip_t( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) );
    //     printf( "%d\n", ping( ip ) );
    //     printf( "ip: %x\n", ip.raw );
        
    //     return 0;
    // }

    return 0;
}