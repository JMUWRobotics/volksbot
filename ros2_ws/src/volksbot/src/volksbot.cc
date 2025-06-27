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

// internet libraries
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

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
// GLOBAL ROVER CONFIGURATIONS
//-----------------------------------------------------------------------------

static constexpr Rover ROVER_DUMMY {
    "Dummy",
    1.00,   // non zero to avoid divide-by-zero exceptions
    1.00,   // non zero to avoid divide-by-zero exceptions
    MCD::ERROR,
    "",
    "",
    ip_t( 0xff, 0xff, 0xff, 0xff )
};

static constexpr Rover ROVER_UTE {
    "Ute",
    26.0,
    50.0,
    MCD::EPOS2,
    "USB0",
    "/dev/EPOS2L",
    ip_t( 192, 168, 0, 14 )
};

static constexpr Rover ROVER_LARS {
    "Lars",
    25.0,
    44.0,
    MCD::VMC,
    "/dev/VMC",
    "/dev/VMC",
    ip_t( 192, 168, 0, 51 )
};

static constexpr Rover ROVER_IRMA {
    "Irma",
    25.0,
    44.0,
    MCD::VMC,
    "/dev/VMC",
    "/dev/VMC",
    ip_t( 192, 168, 0, 0 )
};

static constexpr Rover ROVER_DUMMY2 {
    "Dummy 2",
    99.0,
    99.0,
    MCD::ERROR,
    "/dev/tty0",
    "/dev/tty0",
    ip_t( 192, 168, 0, 0 )
};

static constexpr Rover ROVER_DUMMY3 {
    "Dummy 2",
    99.0,
    99.0,
    MCD::VMC,
    "/dev/tty1",
    "/dev/ttyUSB0",
    ip_t( 8, 8, 8, 8 )
};

static constexpr Rover ROVERS[] = { ROVER_UTE, ROVER_LARS, ROVER_IRMA, /*REMOVE AFTER TESTING*/ ROVER_DUMMY2, ROVER_DUMMY3 };
static constexpr unsigned int rover_count = sizeof(ROVERS) / sizeof(Rover);


//-----------------------------------------------------------------------------
// STATIC STATE VARIABLES FOR BACKEND
//-----------------------------------------------------------------------------

static constexpr auto TIME_PUB_PERIOD_TICKS = 1min;

static rclcpp::Node::SharedPtr node;
static rclcpp::Publisher<msg::Rover>::SharedPtr pub_rover;
static rclcpp::TimerBase::SharedPtr timer;

static const Rover* active_rover = &ROVER_DUMMY;



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
    constexpr int max_loop = 10;
    for( int loop=0; loop < max_loop; loop++ ) {
        socklen_t len = sizeof(r_addr);

        printf( "ping: %2d / %2d\x1b[13D", loop+1, max_loop );
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
        
        if ( sendto(sd, &pckt, sizeof(pckt), 0, (sockaddr*)addr, sizeof(*addr)) <= 0 )
            perror("sendto");

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
 * @brief simple hash function for rovers
 */
static uint64_t hash( const Rover* rov ) {
    return (uint64_t)rov->name
        ^  (uint64_t)rov->wheel_diameter
        ^  (uint64_t)rov->wheel_base
        ^  (uint64_t)rov->motor_controller
        ^  (uint64_t)rov->motor_controller_port
        ^  (uint64_t)rov->ip_lms.raw;
}


/**
 * @brief publishes the active rover over the rover topic
 * 
 * @param rover rover to be published
 * @param pub publisher to publish on
 */
static void publish_rover( const Rover* rover, rclcpp::Publisher<msg::Rover>::SharedPtr pub ) {
    msg::Rover rov;

    rov.is_valid = hash( rover ) != hash( &ROVER_DUMMY );

    rov.name = rover->name;
    
    rov.wheel_diameter = rover->wheel_diameter;
    rov.wheel_base = rover->wheel_base;
    
    rov.motor_controller = rover->motor_controller;
    rov.motor_controller_port = rover->motor_controller_port;

    rov.udev_symlink = rover->udev_symlink;
    
    rov.ip_lms = rover->ip_lms.raw;

    pub->publish( rov );
}

/**
 * @brief finds best matching rover configuration by regarding the mapped udev ports and static lms ips
 * 
 * @return true if a new rover configuration was selected
 * @return false if the rover configuration is unchanged
 */
bool find_rover() {
    uint64_t current_hash = hash(active_rover);

    uint matches[rover_count];
    bzero( matches, sizeof(matches) );
    
    // setup formatting specifiers
    constexpr int str_len_ip = sizeof( "xxx.xxx.xxx.xxx" )-1;
    int max_name_len = 0, max_port_len = str_len_ip;
    for( uint i=0; i < rover_count; i++ ) {
        int name_len = strnlen( ROVERS[i].name, 64 );
        if( name_len > max_name_len )
            max_name_len = name_len;

        int port_len = strnlen( ROVERS[i].udev_symlink, 64 );
        if( port_len > max_port_len )
            max_port_len = port_len;
    }
    

    #define CVAR 35
    printf( "============================================================\n" );
    
    // preprint table
    for( uint i=0; i < rover_count; i++ ) {
        printf( "[" COL(CVAR, "%*s") "] udev port (" COL(CVAR, "%-*s") "): %*s\n",
            max_name_len, ROVERS[i].name,
            max_port_len, ROVERS[i].udev_symlink,
            SIZE_FORMAT,
            COL(90, "...unknown...")
        );

        printf( "[" COL(CVAR, "%*s") "]        ip (" COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "%*s): %*s\n",
            max_name_len, ROVERS[i].name,
            ROVERS[i].ip_lms.ip.hh, 
            ROVERS[i].ip_lms.ip.hl, 
            ROVERS[i].ip_lms.ip.lh, 
            ROVERS[i].ip_lms.ip.ll,
            MAX(0, max_port_len - str_len_ip),
            "",
            SIZE_FORMAT,
            COL(90, "...unknown...")
        );
    }
    printf( "\x1b[%dF", 2*rover_count ); // jump back up
    
    for( uint i=0; i < rover_count; i++ ) {
        // search ports
        bool port = access( ROVERS[i].udev_symlink, F_OK ) == ACCESS_PERMITTED;
        if( port ) {
            matches[i]++;
        }
        printf( "[" COL(CVAR, "%*s") "] udev port (" COL(CVAR, "%-*s") "): %*s\n",
            max_name_len, ROVERS[i].name,
            max_port_len, ROVERS[i].udev_symlink,
            SIZE_FORMAT,
            port ? S_AVAIL : S_NOT_AVAIL
        );

        // search ips
        printf( "[" COL(CVAR, "%*s") "]        ip (" COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "%*s): ",
            max_name_len, ROVERS[i].name,
            ROVERS[i].ip_lms.ip.hh, 
            ROVERS[i].ip_lms.ip.hl, 
            ROVERS[i].ip_lms.ip.lh, 
            ROVERS[i].ip_lms.ip.ll,
            MAX(0, max_port_len - str_len_ip),
            ""
        );
        if( ping( ROVERS[i].ip_lms ) == PING_SUCCESSFUL ) {
            matches[i]++;
        }
    }
    

    // select best fit
    printf( "\n----------------------------------------\n" );
    int best_index = -1;
    uint best_match = 0;
    for( uint i=0; i < rover_count; i++) {
        printf( "[" COL(CVAR, "%*s") "] matches: " COL(CVAR, "%d") "\n", max_name_len, ROVERS[i].name, matches[i] );
        if( matches[i] > best_match ) {
            best_index = i;
            best_match = matches[i];
        }
    }

    // manage selected
    printf( "\nRover:   \x1b[3%cm%s\x1b[0m\n",
        best_index == -1 ? '1' : '2',
        best_index == -1 ? "NOT FOUND" : ROVERS[best_index].name
    );

    active_rover = best_index == -1 ? &ROVER_DUMMY : &ROVERS[best_index];
    
    bool changed = hash(active_rover) != current_hash;
    printf( "Updated: %s\n\n", changed ? COL(103;30, "NEW ROVER") : "not changed" );

    return changed;
}

void find_and_publish() {
    if( find_rover() ) {
        publish_rover( active_rover, pub_rover );
    }
}



int main(int argc, char* argv[]) {
    signal(SIGINT, [](int sig){
        (void)sig;
        rclcpp::shutdown();
        exit(0);
    });
    
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