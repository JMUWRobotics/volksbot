/////////////////////////////////////////////////////////////////////////////
// @file    volksbot.cc
// @brief   broadcasting automatic detection and selection of rover configuration
// @author  Nico Schubert
// @date    25.08.2025
/////////////////////////////////////////////////////////////////////////////

#include "volksface/volksbot.h"


#ifdef USE_LOGGING_VOLKSBOT
    #undef USE_LOGGING
    #define USE_LOGGING USE_LOGGING_VOLKSBOT
#endif

#define LOGGING_NAME "Volksbot"
#include "volksface/logging.h"

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

#define _STR_AVAIL " AVAILABLE "
#define _STR_NOT_AVAIL " NOT AVAILABLE "
#define S_AVAIL COL(FG_GREEN, _STR_AVAIL)
#define S_NOT_AVAIL COL(FG_RED, _STR_NOT_AVAIL)

#define SIZE_STATUS (int)MAX( sizeof(_STR_AVAIL)-1, sizeof(_STR_NOT_AVAIL)-1 )
#define SIZE_FORMAT (int)MAX( sizeof(S_AVAIL)-1, sizeof(S_NOT_AVAIL)-1 )


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
        LOG_LN_WARN( COL(FG_RED, "could not parse rover: invalide yaml input") );
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
        LOG_LN_WARN( COL(FG_RED, "could not parse rover: not all parameters supplied") );
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
        LOG_LN_INFO( "ping_tries         = " COL(FG_GREEN, "%d"), config.count_ping_tries );
    }

    if( auto n = cfg_map["publish_period_sec"] ) {
        config.pub_period = std::chrono::seconds( n.as<int>( config.pub_period.count() ) );
        LOG_LN_INFO( "publish_period_sec = " COL(FG_GREEN, "%lds"), config.pub_period.count() );
    }

    if( auto n = cfg_map["always_publish"] ) {
        config.always_publish = n.as<bool>( config.always_publish );
        LOG_LN_INFO( "always_publish     = " COL(FG_GREEN, "%s"), config.always_publish ? "true" : "false" );
    }

    LOG_LN_INFO(" ");
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
        LOG_LN_INFO( "> parsed Rover: " COL(FG_GREEN, "%*s") " (" COL(FG_GREEN, "%s") ", " COL(FG_GREEN, "%s") ")",
            max_name_len, rov.name.c_str(),
            rov.ip_lms.to_string(3).c_str(),
            MCD::to_string( rov.motor_controller ).c_str()
        );
    }

    LOG_LN_INFO(" ");
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
        LOG_ERROR("Failed creating a socket");
        return 1;
    }
    if ( setsockopt(sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0) {
        LOG_ERROR("Failed setting TTL socket option");
        return 1;
    }
    if ( fcntl(sd, F_SETFL, O_NONBLOCK) != 0 ) {
        LOG_ERROR("Failed requesting nonblocking I/O");
        return 1;
    }
    

    // move cursor right of the status output
    LOG_ANSI( CUF(%d) " ", SIZE_STATUS );

    packet pckt;
    sockaddr_in r_addr;
    for( int loop=0; loop < pings; loop++ ) {
        socklen_t len = sizeof(r_addr);

        LOG_INFO( "ping: %2d / %2d" CUB(13), loop+1, pings );
        fflush( stdout );

        if ( recvfrom(sd, &pckt, sizeof(pckt), 0, (sockaddr*)&r_addr, &len) > 0 ) {
            LOG_ANSI( CUB(%d) "%*s%*s\n", SIZE_STATUS+1, SIZE_FORMAT, S_AVAIL, 14, "" );
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
            LOG_ERROR("Failed to call sendto");
        }

        usleep(300000);
    }
    
    LOG_LN_ANSI( CUB(%d) "%*s%*s", SIZE_STATUS+1, SIZE_FORMAT, S_NOT_AVAIL, 14, "" );
    return 1;
}
[[maybe_unused]] static int ping( const char *adress, const int pings ) {
    return ping( ip_t( *(long*)gethostbyname(adress)->h_addr ), pings );
}
#define PING_SUCCESSFUL 0


//-----------------------------------------------------------------------------
// ROS SPECIFIC IMPLEMENTATIONS
//-----------------------------------------------------------------------------

static inline std::string to_lower( const std::string str ) {
    std::string data = str;
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
    return data;
}

static bool manual_select_rover( std::string rover_name ) {
    LOG_LN_INFO( "Trying to find and select the rover named \"" COL(FG_GREEN, "%s") "\"", rover_name.c_str() );

    for( size_t i=0; i < rovers.size(); i++ ) {
        if( to_lower(rovers[i].name) == to_lower(rover_name) ) {
            active_rover = &rovers[i];
            active_rover_index = i;

            LOG_LN_INFO( "Search was " COL(FG_BRIGHT_GREEN, "SUCCESSFUL") " and " COL(FG_BRIGHT_GREEN, "%s") " is now the selected Rover",
                active_rover->name.c_str()
            );

            return true;
        }
    }

    LOG_LN_WARN( "\"" COL(FG_GREEN, "%s" ) "\" was " COL(FG_BRIGHT_RED, "not found") " in the volksbot/config/rovers.yaml", rover_name.c_str() );
    LOG_LN_WARN( "Search was " COL(FG_BRIGHT_RED, "NOT successful") " and automatic Rover search will now commence\n" );

    return false;
}

static void publish_rover() {
    VB::msg::Rover rov = to_message( *active_rover, hash( active_rover ) != hash( &ROVER_DUMMY ) );
    pub_rover->publish( rov );
}

/**
 * @brief finds best matching rover configuration by regarding the mapped udev ports and static lms ips
 * 
 * @return true if a new rover configuration was selected
 * @return false if the rover configuration is unchanged
 */
static bool find_rover() {
    #define CVAR FG_MAGENTA
    #define CPREFILL ITALIC;FG_GRAY
    static constexpr int max_matches = 2;

    uint64_t current_hash = hash(active_rover);
    bool check_already_connected = active_rover_index != -1;

    std::vector<int> matches;
    for( uint i=0; i < rovers.size(); i++ )
        // -1 is used to signal uninitialized values, used in the print below to know validity of value
        matches.emplace_back( -1 ); 

    // setup local helper functions -------------------------------------------
    constexpr int str_len_ip = sizeof( "xxx.xxx.xxx.xxx" )-1;
    auto [max_name_len, max_port_len] = get_max_len_name_port( rovers, 0, str_len_ip );

    auto print_port = [&](const int i, const char* text) {
        LOG_LN_INFO( "[" COL(CVAR, "%*s") "] udev port (" COL(CVAR, "%-*s") "): %*s",
            max_name_len, rovers[i].name.c_str(),
            max_port_len, rovers[i].udev_symlink.c_str(),
            SIZE_FORMAT, text
        );
    };
    auto print_ip = [&](const int i, const int text_width, const char* text) {
        LOG_INFO( "[" COL(CVAR, "%*s") "]        ip (" COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "." COL(CVAR, "%3d") "%*s): %*s",
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
        matches[i] = 0; // initialize match value

        bool port = access( rovers[i].udev_symlink.c_str(), F_OK ) == ACCESS_PERMITTED;
        if( port ) {
            matches[i]++;
        }
        print_port( i, port ? S_AVAIL : S_NOT_AVAIL );

        // search ips
        print_ip( i, 0, "" );
        if( ping( rovers[i].ip_lms, config.count_ping_tries ) == PING_SUCCESSFUL ) {
            matches[i]++;
        }
    };
    
    
    // preprint table ---------------------------------------------------------
    static bool first_execution = true;
    if( !first_execution ) {
        // jump back up, so that we overwrite the table on the next look up round
        LOG_ANSI( CPL(%ld), 1 + max_matches*rovers.size() + 1 + 1+rovers.size()+1 + 1 );
        LOG_ANSI( ED(0) ); // clear from cursor to end of screen
    }
    first_execution = false;

    LOG_LN_INFO( "============================================================" );

    for( uint i=0; i < rovers.size(); i++ ) {
        print_port( i, check_already_connected ? COL(CPREFILL, "      ...     ") : COL(CPREFILL, " ...waiting... ") );
        print_ip( i, SIZE_FORMAT, check_already_connected ? COL(CPREFILL, "      ...     \n") : COL(CPREFILL, " ...waiting... \n") );
    }

    LOG_LN_INFO( "\n------------------------------------------------------------" );
    for( uint i=0; i < rovers.size(); i++) {
        LOG_LN_INFO( "[" COL(CVAR, "%*s") "] matches: " COL(CPREFILL, " - "), max_name_len, rovers[i].name.c_str() );
    }
    
    LOG_LN_INFO( "\nRover:   %s   " COL(%s, "%*s"),
        check_already_connected ? COL(BLINK;CPREFILL;CVAR, "  validating ") : COL(BLINK;CPREFILL;FG_WHITE, "  searching  "),
        IF_PRINT( check_already_connected ? XSTR(CPREFILL;CVAR) : XSTR(CPREFILL), )
        max_name_len, check_already_connected ? rovers[active_rover_index].name.c_str() : "---"
    );

    LOG_ANSI( SCO ); // save cursor position SCO
    LOG_ANSI( CPL(%ld), max_matches*rovers.size() + 1 + 1+rovers.size()+1 + 1 ); // jump back up
    
    // artificially delay execution so that the user has enough time to "comprehend" what is happening
    IF_PRINT( sleep( 1 ) );


    // main search ------------------------------------------------------------
    // test for valid connection if already connected
    if( check_already_connected ) {
        if( active_rover_index > 0 ) {
            LOG_ANSI( CNL(%d), max_matches*active_rover_index ); // jump to rover position in table
        }

        search_body( active_rover_index );

        LOG_ANSI( CPL(%d), max_matches*(active_rover_index+1) ); // jump back up to top rover position in table

        if( matches[active_rover_index] == max_matches ) {
            // we are still connected and therefor skip testing for other rovers
            LOG_ANSI( CNL(%ld), max_matches*rovers.size() ); // jump to bottom of table
            
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
            LOG_ANSI( CNL(%d), max_matches ); // jump to next rover position in table
            continue;
        }

        search_body( i );
    }
    

    // select best fit
best_fit:
    LOG_LN_INFO( "\n------------------------------------------------------------" );
    
    active_rover_index = -1;
    int best_match = 0;

    static constexpr int color_match_lut[max_matches+1] = { 
        FG_GRAY,    // match == 0
        FG_YELLOW,  // match == 1
        FG_GREEN    // match == 2
    };
    for( uint i=0; i < rovers.size(); i++) {
        if( matches[i] == -1 ) {
            // skip print if value was not initialized since we already preprinted the table
            LOG_ANSI( CNL(1) );
            continue;
        }

        LOG_LN_INFO( "[" COL(CVAR, "%*s") "] matches:  " COL(%d, "%d"), 
            max_name_len, rovers[i].name.c_str(),
            IF_PRINT( color_match_lut[matches[i]], ) matches[i]
        );

        if( matches[i] > best_match ) {
            active_rover_index = i;
            best_match = matches[i];
        }
    }

    // manage selected
    active_rover = active_rover_index == -1 ? &ROVER_DUMMY : &rovers[active_rover_index];
    bool changed = hash(active_rover) != current_hash;

    LOG_LN_INFO( "\nRover:   %s   " COL(%s, "%*s"),
        changed
        ? COL(BG_BRIGHT_YELLOW;FG_BLACK, "  NEW ROVER  ")
        : active_rover_index == -1
            ? COL(FG_GRAY, " not changed ")
            : COL(FG_BRIGHT_GREEN, "  validated  "),
        IF_PRINT( active_rover_index == -1 ? XSTR(BG_BRIGHT_RED;FG_BLACK) : XSTR(FG_BRIGHT_GREEN), )
        max_name_len, active_rover_index == -1 ? " NO ROVER CONNECTED " : rovers[active_rover_index].name.c_str()
    );

    return changed;
}

static void find_and_publish() {
    bool found = find_rover();
    if( found || config.always_publish ) {
        publish_rover();
    }
}


/**
 * If a specific rover should be manually selected, call:
 *      ros2 run volksbot volksbot ${rover_name}
 * with the specified rover name to force select that rover.
 * 
 * Otherwise leave blank and automatic search will be used for rover detection
 */

int main(int argc, char* argv[]) {
    signal(SIGINT, [](int sig){
        (void)sig;
        LOG_LN_ANSI( RCP ); // restore cursor position (last SCO) // new line to flush the buffer
        rclcpp::shutdown();
        exit(0);
    });
    
    LOG_ANSI( ED(2) CUP(1,1) ); // clear screen // and move cursor home
    parse_yaml( PATH_YAML_ROVERS );

    rclcpp::init(argc, argv);
    
    node = std::make_shared<rclcpp::Node>("volksbot_rover");
    
    pub_rover = node->create_publisher<msg::Rover>( TOPIC_NAME_ROVER, 1 );
    
    bool is_manually_set = false;
    if( argc == 2 ) {
        LOG_LN_INFO( "Volksbot called with argument: " COL(FG_GREEN, "%s\n"), argv[1] );
        
        is_manually_set = manual_select_rover( argv[1] );
    }
    
    if( is_manually_set ) {
        publish_rover();
        timer = node->create_wall_timer( config.pub_period, publish_rover );
    } else {
        find_and_publish();
        timer = node->create_wall_timer( config.pub_period, find_and_publish );
    }

    rclcpp::spin( node );
    rclcpp::shutdown();

    return 0;
}