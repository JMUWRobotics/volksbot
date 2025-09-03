/////////////////////////////////////////////////////////////////////////////
// @file    volksbot.cc
// @brief   broadcasting automatic detection and selection of rover configuration
// @author  Nico Schubert
// @date    25.08.2025
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

#define FG_BLACK   30
#define FG_RED     31
#define FG_GREEN   32
#define FG_YELLOW  33
#define FG_BLUE    34
#define FG_MAGENTA 35
#define FG_CYAN    36
#define FG_WHITE   37

#define BG_BLACK   40
#define BG_RED     41
#define BG_GREEN   42
#define BG_YELLOW  43
#define BG_BLUE    44
#define BG_MAGENTA 45
#define BG_CYAN    46
#define BG_WHITE   47

#define FG_BRIGHT_BLACK   90
#define FG_BRIGHT_RED     91
#define FG_BRIGHT_GREEN   92
#define FG_BRIGHT_YELLOW  93
#define FG_BRIGHT_BLUE    94
#define FG_BRIGHT_MAGENTA 95
#define FG_BRIGHT_CYAN    96
#define FG_BRIGHT_WHITE   97

#define BG_BRIGHT_BLACK   100
#define BG_BRIGHT_RED     101
#define BG_BRIGHT_GREEN   102
#define BG_BRIGHT_YELLOW  103
#define BG_BRIGHT_BLUE    104
#define BG_BRIGHT_MAGENTA 105
#define BG_BRIGHT_CYAN    106
#define BG_BRIGHT_WHITE   107

#define FG_GRAY FG_BRIGHT_BLACK

#define STR(s) #s
#define XSTR(s) STR(s)
#define COL(c, s) "\x1b[" STR(c) "m" s "\x1b[0m"


#define SIZE_STATUS 13
#define SIZE_FORMAT_OFFSET ((int)sizeof( COL(FG_RED, "") )-1)
#define SIZE_FORMAT ( SIZE_STATUS + SIZE_FORMAT_OFFSET )



using namespace VB;

//-----------------------------------------------------------------------------
// STATIC STATE VARIABLES FOR BACKEND
//-----------------------------------------------------------------------------

static const std::string PATH_YAML_ROVERS = "src/volksbot/config/rovers.yaml";

static rclcpp::Node::SharedPtr node;
static rclcpp::Publisher<msg::Rover>::SharedPtr pub_rover;
static rclcpp::TimerBase::SharedPtr timer;

static struct config_t {
    int count_ping_tries = 1;
    std::chrono::seconds pub_period = 60s;
    bool always_publish = true;
} config;


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
static int active_rover_index = -1;

static std::pair<int, int> get_max_len_name_port( std::vector<Rover>& rovers, int init_name_len = 0, int init_port_len = 0 ) {
    int max_name_len = init_name_len, max_port_len = init_port_len;
    
    for( uint i=0; i < rovers.size(); i++ ) {
        int name_len = rovers[i].name.length();
        if( name_len > max_name_len )
            max_name_len = name_len;

        int port_len = rovers[i].udev_symlink.length();
        if( port_len > max_port_len )
            max_port_len = port_len;
    }

    return std::make_pair( max_name_len, max_port_len );
}

static bool parse_rover( const YAML::Node& rover_map, Rover& out_rover ) {
    if( !rover_map.IsMap() ) {
        printf( COL(FG_RED, "could not parse rover: invalide yaml input\n") );
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
        printf( COL(FG_RED, "could not parse rover: not all parameters supplied\n") );
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
static void parse_config( const YAML::Node& cfg_map ) {
    if( auto n = cfg_map["ping_tries"] ) {
        config.count_ping_tries = n.as<int>( config.count_ping_tries );
        printf( "ping_tries         = %d\n", config.count_ping_tries );
    }

    if( auto n = cfg_map["publish_period_sec"] ) {
        config.pub_period = std::chrono::seconds( n.as<int>( config.pub_period.count() ) );
        printf( "publish_period_sec = %lds\n", config.pub_period.count() );
    }

    if( auto n = cfg_map["always_publish"] ) {
        config.always_publish = n.as<bool>( config.always_publish );
        printf( "always_publish     = %s\n", config.always_publish ? "true" : "false" );
    }
}
static void parse_yaml( const std::string& file_path ) {
    std::vector<YAML::Node> rovs = YAML::LoadAllFromFile( file_path );

    auto it = rovs.begin();
    parse_config( *it );

    while( ++it != rovs.end() ) {
        Rover out;
        if( parse_rover( *it, out ) ) {
            rovers.push_back( std::move(out) );
        }
    }
    
    int max_name_len = get_max_len_name_port( rovers ).first;

    for( const Rover& rov : rovers ) {
        printf( "> parsed Rover: " COL(FG_GREEN, "%*s") " (" COL(FG_GREEN, "%s") ", " COL(FG_GREEN, "%s") ")\n",
            max_name_len, rov.name.c_str(),
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
static unsigned short checksum(const void *b, int len) {
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
static int ping( const ip_t ip, const int pings ) {
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
    for( int loop=0; loop < pings; loop++ ) {
        socklen_t len = sizeof(r_addr);

        printf( "ping: %2d / %2d\x1b[13D", loop+1, pings );
        fflush( stdout );

        if ( recvfrom(sd, &pckt, sizeof(pckt), 0, (sockaddr*)&r_addr, &len) > 0 ) {
            printf( "\x1b[%dD%*s%*s\n", SIZE_STATUS+1, SIZE_FORMAT, COL(FG_GREEN, "AVAILABLE"), 14, "" );
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
    
    printf( "\x1b[%dD%*s%*s\n", SIZE_STATUS+1, SIZE_FORMAT, COL(FG_RED, "NOT AVAILABLE"), 14, "" );
    return 1;
}
[[maybe_unused]] static int ping( const char *adress, const int pings ) {
    return ping( ip_t( *(long*)gethostbyname(adress)->h_addr ), pings );
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
static bool find_rover() {
    #define CVAR FG_MAGENTA
    static constexpr int max_matches = 2;

    uint64_t current_hash = hash(active_rover);
    bool check_already_connected = active_rover_index != -1;

    std::vector<uint> matches;
    for( uint i=0; i < rovers.size(); i++ )
        matches.emplace_back( 0 );

    // setup local helper functions -------------------------------------------
    constexpr int str_len_ip = sizeof( "xxx.xxx.xxx.xxx" )-1;
    auto [max_name_len, max_port_len] = get_max_len_name_port( rovers, 0, str_len_ip );

    auto print_port = [&](const int i, const char* text) {
        printf( "[" COL(CVAR, "%*s") "] udev port (" COL(CVAR, "%-*s") "): %*s\n",
            max_name_len, rovers[i].name.c_str(),
            max_port_len, rovers[i].udev_symlink.c_str(),
            SIZE_FORMAT, text
        );
    };
    auto print_ip = [&](const int i, const int text_width, const char* text) {
        printf( "[" COL(CVAR, "%*s") "]        ip (" COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "%*s): %*s",
            max_name_len, rovers[i].name.c_str(),
            rovers[i].ip_lms.ip.hh, 
            rovers[i].ip_lms.ip.hl, 
            rovers[i].ip_lms.ip.lh, 
            rovers[i].ip_lms.ip.ll,
            MAX(0, max_port_len - str_len_ip),
            "",
            text_width, text
        );
    };

    auto search_body = [&](int i) {
        bool port = access( rovers[i].udev_symlink.c_str(), F_OK ) == ACCESS_PERMITTED;
        if( port ) {
            matches[i]++;
        }
        print_port( i, port ? COL(FG_GREEN, "AVAILABLE") : COL(FG_RED, "NOT AVAILABLE") );

        // search ips
        print_ip( i, 0, "" );
        if( ping( rovers[i].ip_lms, config.count_ping_tries ) == PING_SUCCESSFUL ) {
            matches[i]++;
        }
    };
    
    
    // preprint table ---------------------------------------------------------
    printf( "============================================================\n" );

    for( uint i=0; i < rovers.size(); i++ ) {
        print_port( i, check_already_connected ? COL(FG_GRAY, "      ...     ") : COL(FG_GRAY, "...unknown...") );
        print_ip( i, SIZE_FORMAT, check_already_connected ? COL(FG_GRAY, "      ...     \n") : COL(FG_GRAY, "...unknown...\n") );
    }

    printf( "\n------------------------------------------------------------\n" );
    for( uint i=0; i < rovers.size(); i++) {
        printf( "[" COL(CVAR, "%*s") "] matches: " COL(FG_GRAY, "-") "\n", max_name_len, rovers[i].name.c_str() );
    }

    printf( "\nRover:   %s   " COL(%d, "%*s") "\n",
        check_already_connected ? COL(CVAR, " validating") : COL(FG_GRAY, " searching "),
        check_already_connected ? CVAR : FG_GRAY,
        max_name_len, check_already_connected ? rovers[active_rover_index].name.c_str() : "---"
    );

    printf( "\x1b[%ldF", max_matches*rovers.size() + 1+rovers.size()+1 + 2 ); // jump back up
    
    // artificially delay execution so that the user has enough time to "comprehend" what is happening
    sleep( 1 );


    // main search ------------------------------------------------------------
    // test for valid connection if already connected
    if( check_already_connected ) {
        printf( "\x1b[%dE", max_matches*active_rover_index ); // jump to rover position in table

        search_body( active_rover_index );

        printf( "\x1b[%dF", max_matches*(active_rover_index+1) ); // jump back up to top rover position in table

        if( matches[active_rover_index] == max_matches ) {
            // we are still connected and therefor skip testing for other rovers
            printf( "\x1b[%ldE", max_matches*rovers.size() ); // jump to bottom of table
            
            // YESS, this is very dirty, but i think it is better for the readability
            // and also logic of the controlflow than having to indent for another if clause
            // since we actively want to skip over the for loop if we validated the active connection
            goto best_fit;
        }
    }

    // search for any available connection
    for( uint i=0; i < rovers.size(); i++ ) {
        // if an rover is connected and we already checked for it above we can skip it now
        // else i will never be -1 and active_rover_index is -1 so the if case does not execute
        if ( static_cast<int>(i) == active_rover_index ) {
            printf( "\x1b[" XSTR(max_matches) "E" ); // jump to next rover position in table
            continue;
        }

        search_body( i );
    }
    

    // select best fit
best_fit:
    printf( "\n----------------------------------------\n" );
    
    active_rover_index = -1;
    uint best_match = 0;

    static constexpr int color_match_lut[max_matches+1] = { FG_GRAY, FG_YELLOW, FG_GREEN };
    for( uint i=0; i < rovers.size(); i++) {
        printf( "[" COL(CVAR, "%*s") "] matches: " COL(%d, "%d") "\n", 
            max_name_len, rovers[i].name.c_str(),
            color_match_lut[matches[i]], matches[i]
        );
        if( matches[i] > best_match ) {
            active_rover_index = i;
            best_match = matches[i];
        }
    }

    // manage selected
    active_rover = active_rover_index == -1 ? &ROVER_DUMMY : &rovers[active_rover_index];
    bool changed = hash(active_rover) != current_hash;

    printf( "\nRover:   %s   " COL(%d, "%*s") "\n",
        changed
        ? COL(BG_BRIGHT_YELLOW;FG_BLACK, " NEW ROVER ")
        : active_rover_index == -1
            ? COL(FG_GRAY, "not changed")
            : COL(FG_BRIGHT_GREEN, " validated "),
        active_rover_index == -1 ? FG_RED : FG_GREEN,
        max_name_len, active_rover_index == -1 ? "NOT FOUND" : rovers[active_rover_index].name.c_str()
    );

    return changed;
}

static void find_and_publish() {
    bool found = find_rover();
    if( found || config.always_publish ) {
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
    
    printf( "\x1b[2J\x1b[1;1H" ); // clear screen // and move cursor home
    parse_yaml( PATH_YAML_ROVERS );

    rclcpp::init(argc, argv);
    
    node = std::make_shared<rclcpp::Node>("volksbot_rover");
    
    pub_rover = node->create_publisher<msg::Rover>( TOPIC_NAME_ROVER, 1 );
    
    timer = node->create_wall_timer( config.pub_period, find_and_publish );

    find_and_publish();

    rclcpp::spin( node );
    rclcpp::shutdown();

    return 0;
}