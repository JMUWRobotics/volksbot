/////////////////////////////////////////////////////////////////////////////
// @file    volksbot.cc
// @brief   broadcasting automatic detection and selection of rover configuration
// @author  Nico Schubert
// @date    25.08.2025
/////////////////////////////////////////////////////////////////////////////

/**
 * If a specific rover should be manually selected, call:
 *      ros2 run volksbot volksbot ${rover_name}
 * with the specified rover name to force select that rover.
 * 
 * Otherwise leave blank and automatic search will be used for rover detection
 */


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

using namespace VB;


//-----------------------------------------------------------------------------
// STATIC STATE VARIABLES FOR BACKEND
//-----------------------------------------------------------------------------

static const std::string PATH_YAML_ROVERS = "src/volksbot/config/rovers.yaml";

static rclcpp::Node::SharedPtr node;
static rclcpp::Publisher<msg::Rover>::SharedPtr pub_rover;
static rclcpp::TimerBase::SharedPtr timer;

static struct config_t {
    static constexpr int max_possible_ping_tries = 9;

    int count_ping_tries = 1;
    int ping_timeout_ms = 100;
    std::chrono::seconds pub_period = 60s;
    bool always_publish = true;
    bool use_full_rover_table_output = false;
} config;

struct DetailedRoverInfo : public Rover {
    std::string description;
    std::string controller_color;
};

// fallback dummy when no rover could be detected
static const Rover ROVER_DUMMY {
    "Dummy",
    1.00,   // non zero to avoid divide-by-zero exceptions
    1.00,   // non zero to avoid divide-by-zero exceptions
    { { { 1.0f, 0.0f },
        { 0.0f, 1.0f } } },
    MCD::ERROR,
    "",
    "",
    ip_t( 0xff, 0xff, 0xff, 0xff ),
    false
};

static std::vector<DetailedRoverInfo> rovers;
static const Rover* active_rover = &ROVER_DUMMY;
static int active_rover_index = -1;


//-----------------------------------------------------------------------------
// ROVER PARSING AND IMPLEMENTATION
//-----------------------------------------------------------------------------

static bool parse_rover( const YAML::Node& rover_map, DetailedRoverInfo& out_rover ) {
    if( !rover_map.IsMap() ) {
        LOG_LN_WARN( COL(FG_RED, "could not parse rover: invalide yaml input") );
        return false;
    }

    if( !rover_map["name"]                   ||
        !rover_map["wheel_diameter"]         ||
        !rover_map["wheel_base"]             ||
        !rover_map["motor_controller"]       ||
        !rover_map["udev_symlink"]           ||
        !rover_map["ip_lms"]                 
    ) {
        LOG_LN_WARN( COL(FG_RED, "could not parse rover: not all parameters supplied") );
        return false;
    }

    // mandatory parameters
    std::string name, motor_controller, udev_symlink, ip_lms;
    float wheel_diameter, wheel_base;

    name                  = rover_map["name"]            .as<std::string>();
    wheel_diameter        = rover_map["wheel_diameter"]  .as<float>();
    wheel_base            = rover_map["wheel_base"]      .as<float>();
    motor_controller      = rover_map["motor_controller"].as<std::string>();
    udev_symlink          = rover_map["udev_symlink"]    .as<std::string>();
    ip_lms                = rover_map["ip_lms"]          .as<std::string>();
    
    // optional parameters
    std::string motor_controller_port="", description="", controller_color="";
    ip_t livox{}; // default: invalid ip
    
    if ( rover_map["description"] )
        description = rover_map["description"].as<std::string>();
    
    if ( rover_map["controller_color"] )
        controller_color = rover_map["controller_color"].as<std::string>();
    
    if ( rover_map["motor_controller_port"] )
        motor_controller_port = rover_map["motor_controller_port"].as<std::string>();
    
    if ( rover_map["ip_livox"] ) {
        std::string ip_livox = rover_map["ip_livox"].as<std::string>();
        if( !ip_t::from_string( ip_livox, livox ) ) { // invalide ipv4
            LOG_LN_ERROR( COL(FG_RED, "ip_livox was supplied but could not be parsed for rover %s: ip_livox = %s"), name.c_str(), ip_livox.c_str() );
            return false;
        }
    }

    float wheel_map[4] = { 1.0f, 0.0f, 0.0f, 1.0f }; // default: direct mapping
    if( rover_map["wheel_mapping"] ) {
        YAML::Node wm_node = rover_map["wheel_mapping"];
        if( wm_node.IsSequence() && wm_node.size() == 4 ) {
            for( uint i=0; i < 4; i++ ) {
                wheel_map[i] = wm_node[i].as<float>();
            }
        } else {
            LOG_LN_WARN( COL(FG_YELLOW, "could not parse wheel_mapping for rover %s: invalide format, using default"), name.c_str() );
        }
    }

    MCD::MCD mcd = MCD::from_string( motor_controller );
    
    ip_t lms;
    if( !ip_t::from_string( ip_lms, lms ) ) { // invalide ipv4
        LOG_LN_ERROR( COL(FG_RED, "ip_lms could not be parsed for rover %s: ip_lms = %s"), name.c_str(), ip_lms.c_str() );
        return false;
    }

    out_rover.name                  = name;
    out_rover.wheel_diameter        = wheel_diameter;
    out_rover.wheel_base            = wheel_base;
    out_rover.motor_controller      = mcd;
    out_rover.motor_controller_port = motor_controller_port;
    out_rover.udev_symlink          = udev_symlink;
    out_rover.ip_lms                = lms;
    out_rover.ip_livox              = livox;
    out_rover.description           = description;
    out_rover.controller_color      = controller_color;
    out_rover.wheel_mapping         = { { { wheel_map[0], wheel_map[1] },
                                          { wheel_map[2], wheel_map[3] } } };

    return true;
}
static void parse_config( const YAML::Node& cfg_map ) {
    if( auto n = cfg_map["ping_tries"] ) {
        config.count_ping_tries = std::max( 0, std::min( n.as<int>( config.count_ping_tries ), config_t::max_possible_ping_tries ) );
        LOG_LN_INFO( "ping_tries                  = " COL(FG_GREEN, "%d"), config.count_ping_tries );
    }

    if( auto n = cfg_map["ping_timeout_ms"] ) {
        config.ping_timeout_ms = std::max( 0, n.as<int>( config.ping_timeout_ms ) );
        LOG_LN_INFO( "ping_timeout_ms             = " COL(FG_GREEN, "%dms"), config.ping_timeout_ms );
    }

    if( auto n = cfg_map["publish_period_sec"] ) {
        config.pub_period = std::chrono::seconds( std::max(0, n.as<int>( config.pub_period.count() )) );
        LOG_LN_INFO( "publish_period_sec          = " COL(FG_GREEN, "%lds"), config.pub_period.count() );
    }

    if( auto n = cfg_map["always_publish"] ) {
        config.always_publish = n.as<bool>( config.always_publish );
        LOG_LN_INFO( "always_publish              = " COL(FG_GREEN, "%s"), config.always_publish ? "true" : "false" );
    }

    if( auto n = cfg_map["use_full_rover_table_output"] ) {
        config.use_full_rover_table_output = n.as<bool>( config.use_full_rover_table_output );
        // TODO?: does this really need a dedicated console output?
        LOG_LN_INFO( "use_full_rover_table_output = " COL(FG_GREEN, "%s"), config.use_full_rover_table_output ? "true" : "false" );
    }

    LOG_LN_INFO(" ");
}
static void parse_yaml( const std::string& file_path ) {
    std::vector<YAML::Node> rovs = YAML::LoadAllFromFile( file_path );

    auto it = rovs.begin();
    parse_config( *it );

    while( ++it != rovs.end() ) {
        DetailedRoverInfo out;
        if( parse_rover( *it, out ) ) {
            rovers.push_back( std::move(out) );
        }
    }
    
    if (rovers.empty()) {
        LOG_LN_WARN( COL(FG_YELLOW, "No rover configurations found in %s"), file_path.c_str() );
    }
}


//------------------------------------------------------------------------------
// VISUALIZATION
//------------------------------------------------------------------------------

#define CENTER_FMT "%*s%s%*s"
#define CENTER_PAD_LEFT(str_size, width) (int)((width - (str_size)) / 2)
#define CENTER_PAD_RIGHT(str_size, width) (int)(width - (str_size) - CENTER_PAD_LEFT(str_size, width))
// printf arguments to center a string as specified by CENTER_FMT; only for strlen(str) < width !!
#define CENTER_ARGS(str, width) CENTER_PAD_LEFT(slen(str), width), "", (str), CENTER_PAD_RIGHT(slen(str), width), ""
#define CENTER_XARGS(str, str_size, width) CENTER_PAD_LEFT(str_size, width), "", (str), CENTER_PAD_RIGHT(str_size, width), ""


static constexpr int slen(const char* str) { return std::char_traits<char>::length(str); }

template<typename T, typename... Ts>
static constexpr T max(T a, Ts... args) {
    T m = a;
    ((m = args > m ? args : m), ...);
    return m;
}

template<typename T>
static std::vector<std::string> extract_string_entries( const std::vector<DetailedRoverInfo>& rovers, T DetailedRoverInfo::*member, std::string (*to_string_func)(const T&) ) {
    std::vector<std::string> entries;
    for( const auto& r : rovers ) {
        entries.push_back( to_string_func( r.*member ) );
    }
    return entries;
}
static std::vector<std::string> extract_string_entries( const std::vector<DetailedRoverInfo>& rovers, std::string DetailedRoverInfo::*member ) {
    return extract_string_entries<std::string>( rovers, member, [](const std::string& s) { return s; } );
}

static int get_max_string_length( const std::vector<std::string>& elements, const int min_len=0 ) {
    int max_len = min_len;
    for( const auto& e : elements ) {
        int len = e.length();
        if( len > max_len )
            max_len = len;
    }
    return max_len;
}
template<typename T>
static int get_max_string_length( const std::vector<DetailedRoverInfo>& rovers, T DetailedRoverInfo::*member, std::string (*to_string_func)(const T&), const int min_len=0 ) {
    return get_max_string_length( extract_string_entries( rovers, member, to_string_func ), min_len );
}
static int get_max_string_member_length( const std::vector<DetailedRoverInfo>& rovers, std::string DetailedRoverInfo::*member, const int min_len=0 ) {
    return get_max_string_length( extract_string_entries( rovers, member ), min_len );
}


// To personalize the table output to full or minimal output the user can set the optional "use_full_rover_table_output" in the rover.yaml
struct TableVisualizer {
    #define LPAD "   "
    #define SEP  " | "

    #define DASH "-"
    #define DASH_CHR DASH[0]
    #define DDASH "="
    #define DDASH_CHR DDASH[0]
    
    #define CSEP DASH "+" DASH
    #define HSEP DASH "|" DASH
    static_assert( slen(CSEP) == slen(SEP) && slen(HSEP) == slen(SEP), "separator strings must be of equal length for proper table formatting" );

    static const std::map<std::string, std::string> color_string_map;
    static constexpr int lines_per_rover = 1;

    struct Titles {
        typedef const char* const cnst_str;

        // main headers
        static constexpr cnst_str main           = "Available Rovers";
        static constexpr cnst_str info           = "Rover Info";
        static constexpr cnst_str parameters     = "Rover Parameters";

        static constexpr cnst_str name           = "Name";
        static constexpr cnst_str desc           = "Description";
        static constexpr cnst_str color1         = "Gamepad";
        static constexpr cnst_str color2         = "Color";
        static constexpr cnst_str wheel          = "Wheel Parameters";
        static constexpr cnst_str wheel_diameter = "Diameter";
        static constexpr cnst_str wheel_base     = "Base";

        static constexpr cnst_str ip_title       = "IP Address";
        static constexpr cnst_str ip_lms         = "SICK LMS-100";
        static constexpr cnst_str ip_livox       = "DJI Livox 360";
        static constexpr cnst_str port1          = "Motor Driver";
        static constexpr cnst_str port2          = "Port";

        // status strings
        static constexpr cnst_str status_column_1 = "SICK LMS";
        static constexpr cnst_str status_column_2 = "DJI Livox";
        static constexpr cnst_str status_column_3 = "Motor Port";

        static constexpr cnst_str status_title         = "Connection Status";
        static constexpr cnst_str status_waiting       = "  awaiting";
        static constexpr cnst_str status_available     = "     AVAIL";
        static constexpr cnst_str status_not_available = " NOT AVAIL";

        // when printed must be exactly 1 character long, otherwise the table will be misaligned
        // static constexpr cnst_str status_icon_waiting       = COL(BG_GRAY, "⏳");
        static constexpr cnst_str status_icon_waiting       = COL(FG_GRAY,  "○");
        static constexpr cnst_str status_icon_available     = COL(FG_GREEN, "✔");
        static constexpr cnst_str status_icon_not_available = COL(FG_RED,   "✖");

        static constexpr cnst_str selection_status_validating  = "  validating ";
        static constexpr cnst_str selection_status_validated   = "  validated  ";
        static constexpr cnst_str selection_status_searching   = "  searching  ";
        static constexpr cnst_str selection_status_new_rover   = "  NEW ROVER  ";
        static constexpr cnst_str selection_status_not_changed = " not changed ";
    };

    enum class Status {
        NOT_AVAILABLE = 0,
        AVAILABLE = 1,
        WAITING = 2
    };

    struct sizes_t {
        static constexpr int str_len_status_ping = slen( "ping: X / X" );
        static constexpr int str_len_wheel_values = slen( "XXX.XX cm" );
        static constexpr int str_len_ip = slen( "xxx.xxx.xxx.xxx" );

        int table_width;
        int info_width;
        int parameters_width;

        int max_name_len;
        int max_desc_len;
        int max_color_len;
        int wheel_title_width;
        int max_wheel_diameter_len;
        int max_wheel_base_len;
        
        static constexpr int max_ip_lms_len = max(sizes_t::str_len_ip, slen(Titles::ip_lms));
        static constexpr int max_ip_livox_len = max(sizes_t::str_len_ip, slen(Titles::ip_livox));
        static constexpr int ip_title_width_len = max_ip_lms_len +slen(SEP)+ max_ip_livox_len;
        static_assert( slen(Titles::ip_title) <= ip_title_width_len, "Titles::ip_title is too long for the ip columns" );
        
        int max_port_len;
        
        static constexpr int minimum_status_width = max( 
            str_len_status_ping, 
            slen(Titles::status_waiting), 
            slen(Titles::status_available), 
            slen(Titles::status_not_available) 
        ) + 2; // +2 for the leading Icon+space
        static constexpr int status_column_1_width = max( minimum_status_width, slen(Titles::status_column_1) );
        static constexpr int status_column_2_width = max( minimum_status_width, slen(Titles::status_column_2) );
        static constexpr int status_column_3_width = max( minimum_status_width, slen(Titles::status_column_3) );
        static constexpr int status_title_width = status_column_1_width +slen(SEP)+ status_column_2_width +slen(SEP)+ status_column_3_width;
        static_assert( slen(Titles::status_title) <= status_title_width, "Titles::status_title is too long for the status columns" );
        
        int pos_status_column_1;
        int pos_status_column_2;
        int pos_status_column_3;

        static constexpr int selection_status_width = max( 
            slen(Titles::selection_status_validating), 
            slen(Titles::selection_status_validated), 
            slen(Titles::selection_status_searching), 
            slen(Titles::selection_status_new_rover), 
            slen(Titles::selection_status_not_changed)
        );
        int selection_width;
    } sizes;

    void set_sizes() {
        // width and sizes ----------------------------------------------------------------------------
        sizes.max_name_len  = get_max_string_member_length( rovers, &DetailedRoverInfo::name, slen(Titles::name) );
        sizes.max_port_len  = get_max_string_member_length( rovers, &DetailedRoverInfo::udev_symlink, max( slen(Titles::port1), slen(Titles::port2) ) );
        sizes.max_desc_len  = get_max_string_member_length( rovers, &DetailedRoverInfo::description, slen(Titles::desc) );
        sizes.max_color_len = max( get_max_string_member_length( rovers, &DetailedRoverInfo::controller_color)+2, slen(Titles::color1), slen(Titles::color2) ); // 2 for the color box

        constexpr int raw_max_wheel_diameter_len = max(slen(Titles::wheel_diameter), sizes_t::str_len_wheel_values);
        constexpr int raw_max_wheel_base_len     = max(slen(Titles::wheel_base), sizes_t::str_len_wheel_values);
        
        constexpr bool use_centered_wheel_columns = slen(Titles::wheel) > raw_max_wheel_diameter_len + slen(SEP) + raw_max_wheel_base_len;
        sizes.max_wheel_diameter_len = use_centered_wheel_columns
            ? CENTER_PAD_LEFT(slen(SEP), slen(Titles::wheel))
            : raw_max_wheel_diameter_len;
        sizes.max_wheel_base_len = use_centered_wheel_columns
            ? CENTER_PAD_RIGHT(slen(SEP), slen(Titles::wheel))
            : raw_max_wheel_base_len;
        sizes.wheel_title_width = sizes.max_wheel_diameter_len + slen(SEP) + sizes.max_wheel_base_len;

        // Calculate the total width of the table
        sizes.table_width =   slen(LPAD) + sizes.max_name_len
                            + (config.use_full_rover_table_output ? slen(SEP) + sizes.max_desc_len : 0)
                            + slen(SEP)  + sizes.max_color_len
                            + (config.use_full_rover_table_output ? slen(SEP) + sizes.wheel_title_width : 0)
                            + slen(SEP)  + sizes.ip_title_width_len
                            + slen(SEP)  + sizes.max_port_len
                            + slen(SEP)  + sizes.status_title_width;
        
        sizes.info_width =   slen(LPAD) + sizes.max_name_len
                            + (config.use_full_rover_table_output ? slen(SEP) + sizes.max_desc_len : 0)
                            + slen(SEP)  + sizes.max_color_len;
        sizes.parameters_width = sizes.table_width - sizes.info_width - slen(SEP);

        sizes.pos_status_column_1 = sizes.table_width - sizes.status_title_width;
        sizes.pos_status_column_2 = sizes.pos_status_column_1 + slen(SEP) + sizes.status_column_1_width;

        sizes.selection_width = slen("Rover:   ") + sizes.selection_status_width + slen("   ") + sizes.max_name_len;
    }

    //-------------------//
    //  Print Functions  //
    //-------------------//
    // Headers ------------------------------------------------------------------------------------

    void print_headers() const {
        // Top-Line Header
        LOG_LN_INFO( "%s " COL(FG_BRIGHT_GREEN;BOLD, "%s") " %s" DDASH,
            std::string(CENTER_PAD_LEFT(slen(Titles::main), sizes.table_width)-1, DDASH_CHR).c_str(),
            Titles::main,
            std::string(CENTER_PAD_RIGHT(slen(Titles::main), sizes.table_width)-1, DDASH_CHR).c_str()
        );

        // Sub Header
        LOG_LN_INFO( COL(FG_CYAN, CENTER_FMT) SEP COL(FG_CYAN, CENTER_FMT),
            CENTER_ARGS(Titles::info, sizes.info_width),
            CENTER_ARGS(Titles::parameters, sizes.parameters_width)
        );
        
        // Sub Header: Separator
        LOG_LN_INFO( "%s" HSEP "%s" DASH, 
            std::string(sizes.info_width, DASH_CHR).c_str(), 
            std::string(sizes.parameters_width, DASH_CHR).c_str()
        );

        // Sub Sub Header 1
        if ( config.use_full_rover_table_output ) {
            LOG_LN_INFO( 
                LPAD "%*s"                      // name
                SEP  "%*s"                      // desc
                SEP  COL(FG_CYAN, CENTER_FMT)   // color
                SEP  COL(FG_CYAN, CENTER_FMT)   // wheel
                SEP  COL(FG_CYAN, CENTER_FMT)   // IPs
                SEP  COL(FG_CYAN, CENTER_FMT)   // port
                SEP  COL(FG_CYAN, CENTER_FMT),  // status
    
                sizes.max_name_len, "",
                sizes.max_desc_len, "",
                CENTER_ARGS( Titles::color1      , sizes.max_color_len      ),
                CENTER_ARGS( Titles::wheel       , sizes.wheel_title_width  ),
                CENTER_ARGS( Titles::ip_title    , sizes.ip_title_width_len ),
                CENTER_ARGS( Titles::port1       , sizes.max_port_len       ),
                CENTER_ARGS( Titles::status_title, sizes.status_title_width )
            );
        } else {
            LOG_LN_INFO( 
                LPAD "%*s"                      // name
                SEP  COL(FG_CYAN, CENTER_FMT)   // color
                SEP  COL(FG_CYAN, CENTER_FMT)   // IPs
                SEP  COL(FG_CYAN, CENTER_FMT)   // port
                SEP  COL(FG_CYAN, CENTER_FMT),  // status
    
                sizes.max_name_len, "",
                CENTER_ARGS( Titles::color1      , sizes.max_color_len      ),
                CENTER_ARGS( Titles::ip_title    , sizes.ip_title_width_len ),
                CENTER_ARGS( Titles::port1       , sizes.max_port_len       ),
                CENTER_ARGS( Titles::status_title, sizes.status_title_width )
            );
        }

        // Sub Sub Header 2
        if ( config.use_full_rover_table_output ) {
            LOG_LN_INFO( 
                LPAD COL(FG_CYAN, CENTER_FMT)   // name
                SEP  COL(FG_CYAN, CENTER_FMT)   // desc
                SEP  COL(FG_CYAN, CENTER_FMT)   // color
                SEP  COL(FG_CYAN, CENTER_FMT)   // diameter
                SEP  COL(FG_CYAN, CENTER_FMT)   // base
                SEP  COL(FG_CYAN, CENTER_FMT)   // lms
                SEP  COL(FG_CYAN, CENTER_FMT)   // livox
                SEP  COL(FG_CYAN, CENTER_FMT)   // port
                
                // status columns
                SEP  COL(FG_CYAN, CENTER_FMT)   // status lms
                SEP  COL(FG_CYAN, CENTER_FMT)   // status livox
                SEP  COL(FG_CYAN, CENTER_FMT),  // status port
                
                CENTER_ARGS( Titles::name           , sizes.max_name_len           ),
                CENTER_ARGS( Titles::desc           , sizes.max_desc_len           ),
                CENTER_ARGS( Titles::color2         , sizes.max_color_len          ),
                CENTER_ARGS( Titles::wheel_diameter , sizes.max_wheel_diameter_len ),
                CENTER_ARGS( Titles::wheel_base     , sizes.max_wheel_base_len     ),
                CENTER_ARGS( Titles::ip_lms         , sizes.max_ip_lms_len         ),
                CENTER_ARGS( Titles::ip_livox       , sizes.max_ip_livox_len       ),
                CENTER_ARGS( Titles::port2          , sizes.max_port_len           ),
                CENTER_ARGS( Titles::status_column_1, sizes.status_column_1_width  ),
                CENTER_ARGS( Titles::status_column_2, sizes.status_column_2_width  ),
                CENTER_ARGS( Titles::status_column_3, sizes.status_column_3_width  )
            );
        } else {
            LOG_LN_INFO( 
                LPAD COL(FG_CYAN, CENTER_FMT)   // name
                SEP  COL(FG_CYAN, CENTER_FMT)   // color
                SEP  COL(FG_CYAN, CENTER_FMT)   // lms
                SEP  COL(FG_CYAN, CENTER_FMT)   // livox
                SEP  COL(FG_CYAN, CENTER_FMT)   // port
                
                // status columns
                SEP  COL(FG_CYAN, CENTER_FMT)   // status lms
                SEP  COL(FG_CYAN, CENTER_FMT)   // status livox
                SEP  COL(FG_CYAN, CENTER_FMT),  // status port
                
                CENTER_ARGS( Titles::name           , sizes.max_name_len           ),
                CENTER_ARGS( Titles::color2         , sizes.max_color_len          ),
                CENTER_ARGS( Titles::ip_lms         , sizes.max_ip_lms_len         ),
                CENTER_ARGS( Titles::ip_livox       , sizes.max_ip_livox_len       ),
                CENTER_ARGS( Titles::port2          , sizes.max_port_len           ),
                CENTER_ARGS( Titles::status_column_1, sizes.status_column_1_width  ),
                CENTER_ARGS( Titles::status_column_2, sizes.status_column_2_width  ),
                CENTER_ARGS( Titles::status_column_3, sizes.status_column_3_width  )
            );
        }

        // Sub Header 2: Separator
        if ( config.use_full_rover_table_output ) {
            LOG_LN_INFO( "%s%s" CSEP "%s" CSEP "%s" HSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" DASH
                , std::string( slen(LPAD)                  , DASH_CHR ).c_str()
                , std::string( sizes.max_name_len          , DASH_CHR ).c_str()
                , std::string( sizes.max_desc_len          , DASH_CHR ).c_str()
                , std::string( sizes.max_color_len         , DASH_CHR ).c_str()
                , std::string( sizes.max_wheel_diameter_len, DASH_CHR ).c_str()
                , std::string( sizes.max_wheel_base_len    , DASH_CHR ).c_str()
                , std::string( sizes.max_ip_lms_len        , DASH_CHR ).c_str()
                , std::string( sizes.max_ip_livox_len      , DASH_CHR ).c_str()
                , std::string( sizes.max_port_len          , DASH_CHR ).c_str()
                , std::string( sizes.status_column_1_width , DASH_CHR ).c_str()
                , std::string( sizes.status_column_2_width , DASH_CHR ).c_str()
                , std::string( sizes.status_column_3_width , DASH_CHR ).c_str()
            );
        } else {
            LOG_LN_INFO( "%s%s" CSEP "%s" HSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" CSEP "%s" DASH
                , std::string( slen(LPAD)                  , DASH_CHR ).c_str()
                , std::string( sizes.max_name_len          , DASH_CHR ).c_str()
                , std::string( sizes.max_color_len         , DASH_CHR ).c_str()
                , std::string( sizes.max_ip_lms_len        , DASH_CHR ).c_str()
                , std::string( sizes.max_ip_livox_len      , DASH_CHR ).c_str()
                , std::string( sizes.max_port_len          , DASH_CHR ).c_str()
                , std::string( sizes.status_column_1_width , DASH_CHR ).c_str()
                , std::string( sizes.status_column_2_width , DASH_CHR ).c_str()
                , std::string( sizes.status_column_3_width , DASH_CHR ).c_str()
            );
        }
    }


    // Status prints ------------------------------------------------------------------------------
    // prints the status with leading separator, with the supplied width in place

    enum class LineState { NORMAL, SELECTED, ACTIVATED };

    #define CACTIVATED FG_BRIGHT_GREEN;BOLD
    static const char* status_to_ansi(Status status, LineState lState = LineState::SELECTED) {
        static constexpr LineState SEL = LineState::SELECTED;
        static constexpr LineState ACT = LineState::ACTIVATED;
        switch( status ) {
            case Status::WAITING:       return lState == SEL ? XSTR(FG_BRIGHT_YELLOW;BOLD) : lState == ACT ? XSTR(CACTIVATED;FG_GRAY ) : XSTR(FG_GRAY)  ;
            case Status::AVAILABLE:     return lState == SEL ? XSTR(FG_BRIGHT_GREEN;BOLD)  : lState == ACT ? XSTR(CACTIVATED;FG_GREEN) : XSTR(FG_GREEN) ;
            case Status::NOT_AVAILABLE: return lState == SEL ? XSTR(FG_BRIGHT_RED;BOLD)    : lState == ACT ? XSTR(CACTIVATED;FG_RED  ) : XSTR(FG_RED)   ;
        }
        return XSTR(FG_MAGENTA);
    };
    static const char* status_to_str(Status status) {
        switch( status ) {
            case Status::WAITING:       return Titles::status_waiting;
            case Status::AVAILABLE:     return Titles::status_available;
            case Status::NOT_AVAILABLE: return Titles::status_not_available;
        }
        return Titles::status_waiting;
    };
    static const char* status_to_icon(Status status) {
        switch( status ) {
            case Status::WAITING:       return Titles::status_icon_waiting;
            case Status::AVAILABLE:     return Titles::status_icon_available;
            case Status::NOT_AVAILABLE: return Titles::status_icon_not_available;
        }
        return Titles::status_icon_waiting;
    };
    static void print_status( const Status status, int width, LineState lState = LineState::SELECTED ) {
        if ( lState == LineState::ACTIVATED ) {
            LOG_INFO( SGR(CACTIVATED) SEP "%s" COL(%s, " %-*s"), 
                status_to_icon(status),
                status_to_ansi(status, lState),
                width - 2, status_to_str(status)
            );
        } else {
            LOG_INFO( SEP "%s " COL(%s, "%-*s"), 
                status_to_icon(status),
                status_to_ansi(status, lState),
                width - 2, status_to_str(status)
            );
        }
    }

    static void status_ping_print_callback(int ping_try, int status_pos) {
        LOG_ANSI( CHA(%d), status_pos + 1 );
        LOG_INFO( COL(FG_BLUE;BOLD, "● ping: %d / %d"), ping_try, config.count_ping_tries);
        LOG_ANSI( CHA(1) ); // reset/move cursor to the beginning of the line
        fflush( stdout );   // flush output buffer for immediate printing, else nothing gets printed to the console
    };

    struct RoverLineArgumentProcessing {
        std::string str_description  = "N/A";
        std::string ansi_description = XSTR(FG_GRAY);
        
        std::string str_controller_color  = "N/A";
        std::string ansi_controller_color = XSTR(BG_DEFAULT);
        std::string ansi_controller_font  = XSTR(FG_GRAY);

        std::string str_ip_livox  = "N/A";
        std::string ansi_ip_livox = XSTR(FG_GRAY);
    };
    RoverLineArgumentProcessing preprocesses_rover_line_arguments( 
        const DetailedRoverInfo& rov, 
        const std::string& ansi_desc,
        const std::string& ansi_ip
    ) const {
        RoverLineArgumentProcessing out;

        if ( rov.description != "" ) {
            out.str_description = rov.description;
            out.ansi_description = ansi_desc;
        }

        if ( rov.controller_color != "" ) {
            out.str_controller_color = rov.controller_color;

            if ( color_string_map.find( rov.controller_color ) != color_string_map.end() ) {
                const std::string& color_index = color_string_map.at( rov.controller_color );
                out.ansi_controller_color = XSTR(PREFIX_BG) + color_index;
                out.ansi_controller_font  = XSTR(PREFIX_FG) + color_index;
            }
        }

        if ( rov.ip_livox.raw != 0 /* uninitialized or invalid */ ) {
            out.str_ip_livox = rov.ip_livox.to_string(3);
            out.ansi_ip_livox = ansi_ip;
        }

        return out;
    }


    // Line Prints --------------------------------------------------------------------------------
    
    void print_rover_line_default( 
        const DetailedRoverInfo& rov, 
        const Status status_column_1, 
        const Status status_column_2, 
        const Status status_column_3 
    ) const {
        #define CVAR FG_MAGENTA
        RoverLineArgumentProcessing args = preprocesses_rover_line_arguments( rov, XSTR(CVAR), XSTR(CVAR) );

        const size_t str_desc_len = slen(SEP CSI) + args.ansi_description.length() + slen("m") + sizes.max_desc_len + slen(SGR(0)) + 1;
        char* str_desc = new char[ str_desc_len ];
        snprintf( str_desc, str_desc_len, 
                  SEP COL(%s, CENTER_FMT), 
                  args.ansi_description.c_str(), CENTER_ARGS(args.str_description.c_str(), sizes.max_desc_len) 
        );
        
        const size_t str_wheels_len = slen(SEP) + slen(SGR(CVAR)) + sizes.max_wheel_diameter_len + slen(SGR(0)) + slen(COL(FG_GRAY, " cm"))
                                    + slen(SEP) + slen(SGR(CVAR)) + sizes.max_wheel_base_len     + slen(SGR(0)) + slen(COL(FG_GRAY, " cm"))+1;
        char* str_wheels = new char[ str_wheels_len ];
        snprintf( str_wheels, str_wheels_len, 
                  SEP COL(CVAR, "%*.2f") COL(FG_GRAY, " cm") 
                  SEP COL(CVAR, "%*.2f") COL(FG_GRAY, " cm"), 
                  sizes.max_wheel_diameter_len-3, rov.wheel_diameter,
                  sizes.max_wheel_base_len-3, rov.wheel_base 
        );

        LOG_INFO(
            LPAD COL(CVAR, CENTER_FMT)          // name
            "%s"                                // desc
            SEP  COL(%s, " ") COL(%s, " %-*s")  // color
            "%s"                                // wheels
            SEP  COL(CVAR, CENTER_FMT)          // ip
            SEP  COL(%s,   CENTER_FMT)          // ip_livox
            SEP  COL(CVAR, "%-*s"),             // udev_symlink

            CENTER_ARGS(rov.name.c_str(), sizes.max_name_len),
            config.use_full_rover_table_output ? str_desc : "",
            args.ansi_controller_color.c_str(), args.ansi_controller_font.c_str(), sizes.max_color_len-2, args.str_controller_color.c_str(),
            config.use_full_rover_table_output ? str_wheels : "",
            CENTER_ARGS(rov.ip_lms.to_string(3).c_str(), sizes.max_ip_lms_len),
            args.ansi_ip_livox.c_str(), CENTER_ARGS(args.str_ip_livox.c_str(), sizes.max_ip_livox_len),
            sizes.max_port_len, rov.udev_symlink.c_str()
        );

        delete[] str_desc;
        delete[] str_wheels;

        // printing the status columns
        print_status(status_column_1, sizes.status_column_1_width, LineState::NORMAL);
        print_status(status_column_2, sizes.status_column_2_width, LineState::NORMAL);
        print_status(status_column_3, sizes.status_column_3_width, LineState::NORMAL);

        LOG_INFO("\n");
        #undef CVAR
    }
    void print_rover_line_selected( 
        const DetailedRoverInfo& rov,
        const Status status_column_1,
        const Status status_column_2,
        const Status status_column_3
    ) const {
        #define CVAR FG_BRIGHT_YELLOW;BOLD
        RoverLineArgumentProcessing args = preprocesses_rover_line_arguments( rov, XSTR(CVAR), XSTR(CVAR) );

        const size_t str_desc_len = slen(SEP SGR(CVAR)) + sizes.max_desc_len + slen(SGR(0)) + 1;
        char* str_desc = new char[ str_desc_len ];
        snprintf( str_desc, str_desc_len, 
                  SEP COL(CVAR, CENTER_FMT), 
                  CENTER_ARGS(args.str_description.c_str(), sizes.max_desc_len)
        );
        
        const size_t str_wheels_len = slen(SEP) + slen(SGR(CVAR)) + sizes.max_wheel_diameter_len + slen(SGR(0)) + slen(COL(CVAR, " cm"))
                                    + slen(SEP) + slen(SGR(CVAR)) + sizes.max_wheel_base_len     + slen(SGR(0)) + slen(COL(CVAR, " cm"))+1;
        char* str_wheels = new char[ str_wheels_len ];
        snprintf( str_wheels, str_wheels_len, 
                  SEP COL(CVAR, "%*.2f") COL(CVAR, " cm") 
                  SEP COL(CVAR, "%*.2f") COL(CVAR, " cm"), 
                  sizes.max_wheel_diameter_len-3, rov.wheel_diameter,
                  sizes.max_wheel_base_len-3, rov.wheel_base 
        );

        LOG_INFO(
            LPAD COL(CVAR, CENTER_FMT)                  // name
            "%s"                                        // desc
            SEP  COL(%s, " ") COL(CVAR, " %-*s")        // color
            "%s"                                        // wheels
            SEP  COL(CVAR, CENTER_FMT)                  // ip
            SEP  COL(CVAR, CENTER_FMT)                  // ip_livox
            SEP  COL(CVAR, "%-*s"),                     // udev_symlink

            CENTER_ARGS(rov.name.c_str(), sizes.max_name_len),
            config.use_full_rover_table_output ? str_desc : "",
            args.ansi_controller_color.c_str(), sizes.max_color_len-2, args.str_controller_color.c_str(),
            config.use_full_rover_table_output ? str_wheels : "",
            CENTER_ARGS(rov.ip_lms.to_string(3).c_str(), sizes.max_ip_lms_len),
            CENTER_ARGS(args.str_ip_livox.c_str(), sizes.max_ip_livox_len),
            sizes.max_port_len, rov.udev_symlink.c_str()
        );

        delete[] str_desc;
        delete[] str_wheels;

        // printing the status columns
        print_status(status_column_1, sizes.status_column_1_width, LineState::SELECTED);
        print_status(status_column_2, sizes.status_column_2_width, LineState::SELECTED);
        print_status(status_column_3, sizes.status_column_3_width, LineState::SELECTED);

        print_row_brackets();

        LOG_INFO("\n");
        #undef CVAR
    }
    void print_rover_line_activated( 
        const DetailedRoverInfo& rov,
        const Status status_column_1,
        const Status status_column_2,
        const Status status_column_3
    ) const {
        RoverLineArgumentProcessing args = preprocesses_rover_line_arguments( rov, XSTR(CACTIVATED), XSTR(CACTIVATED) );

        const size_t str_desc_len = slen(SEP) + sizes.max_desc_len + 1;
        char* str_desc = new char[ str_desc_len ];
        snprintf( str_desc, str_desc_len, 
                  SEP CENTER_FMT, 
                  CENTER_ARGS(args.str_description.c_str(), sizes.max_desc_len)
        );
        
        const size_t str_wheels_len = slen(SEP) + sizes.max_wheel_diameter_len + slen(" cm")
                                    + slen(SEP) + sizes.max_wheel_base_len     + slen(" cm")+1;
        char* str_wheels = new char[ str_wheels_len ];
        snprintf( str_wheels, str_wheels_len, 
                  SEP "%*.2f cm" 
                  SEP "%*.2f cm", 
                  sizes.max_wheel_diameter_len-3, rov.wheel_diameter,
                  sizes.max_wheel_base_len-3, rov.wheel_base 
        );

        LOG_INFO( 
            SGR(CACTIVATED)
            LPAD CENTER_FMT                             // name
            "%s"                                        // desc
            SEP  COL(%s, " ") SGR(CACTIVATED) " %-*s"   // color
            "%s"                                        // wheels
            SEP  CENTER_FMT                             // ip
            SEP  CENTER_FMT                             // ip_livox
            SEP  "%-*s"                                 // udev_symlink
            SGR(0),

            CENTER_ARGS(rov.name.c_str(), sizes.max_name_len),
            config.use_full_rover_table_output ? str_desc : "",
            args.ansi_controller_color.c_str(), sizes.max_color_len-2, args.str_controller_color.c_str(),
            config.use_full_rover_table_output ? str_wheels : "",
            CENTER_ARGS(rov.ip_lms.to_string(3).c_str(), sizes.max_ip_lms_len),
            CENTER_ARGS(args.str_ip_livox.c_str(), sizes.max_ip_livox_len),
            sizes.max_port_len, rov.udev_symlink.c_str()
        );

        delete[] str_desc;
        delete[] str_wheels;

        // printing the status columns
        print_status(status_column_1, sizes.status_column_1_width, LineState::ACTIVATED);
        print_status(status_column_2, sizes.status_column_2_width, LineState::ACTIVATED);
        print_status(status_column_3, sizes.status_column_3_width, LineState::ACTIVATED);

        print_row_brackets( XSTR(CACTIVATED) );

        LOG_INFO("\n");
    }
    void print_rover_line( 
        const DetailedRoverInfo& rov, 
        const Status status_column_1, 
        const Status status_column_2, 
        const Status status_column_3,
        LineState state 
    ) const {
        switch( state ) {
            case LineState::NORMAL:    print_rover_line_default(   rov, status_column_1, status_column_2, status_column_3 ); break;
            case LineState::SELECTED:  print_rover_line_selected(  rov, status_column_1, status_column_2, status_column_3 ); break;
            case LineState::ACTIVATED: print_rover_line_activated( rov, status_column_1, status_column_2, status_column_3 ); break;
        }
    }
    #undef CACTIVATED

    void print_row_brackets(const char* ansi = XSTR(FG_BRIGHT_YELLOW;BOLD)) const {
        LOG_ANSI( CHA(1) ); // reset/move cursor to the beginning of the line (if not already there)
        LOG_INFO( COL(%s, ">>"), ansi );
        LOG_ANSI( CHA(%d), sizes.table_width + 1);
        LOG_INFO( COL(%s, "<<"), ansi );
        LOG_ANSI( CHA(1) ); // reset/move cursor to the beginning of the line
    }

    void print_line_with_status(
        const int rov_index, 
        const Status status_column_1, 
        const Status status_column_2, 
        const Status status_column_3,
        const bool is_selected=true
    ) const {
        LOG_ANSI( EL(2) ); // clear line

        // print line
        print_rover_line(
            rovers[rov_index], 
            status_column_1,
            status_column_2,
            status_column_3,
            is_selected ? TableVisualizer::LineState::SELECTED : TableVisualizer::LineState::NORMAL
        );

        LOG_ANSI( CPL(%d), lines_per_rover ); // move cursor back to begingen of this line/row
    };


    // Miscellaneous Prints -----------------------------------------------------------------------
    
    void print_table() const {
        print_headers();

        for( const DetailedRoverInfo& rov : rovers ) {
            print_rover_line_default( rov, Status::WAITING, Status::WAITING, Status::WAITING );
        }

        LOG_INFO("\n");
    }

    void print_rover_selection(
        const char* ansi_status,
        const char* status,
        const char* ansi_rover_name,
        const char* rover_name
    ) const {
        LOG_LN_INFO( "%*sRover:   " COL(%s, "%s") "   " COL(%s, "%*s"),
            CENTER_PAD_LEFT( sizes.selection_width, sizes.table_width), "",
            ansi_status, status,
            IF_PRINT( ansi_rover_name, )
            sizes.max_name_len, rover_name
        );
    }

    #undef LPAD
    #undef SEP
    #undef DASH
    #undef DASH_CHR
    #undef DDASH
    #undef DDASH_CHR
    #undef CSEP
    #undef HSEP
};

const std::map<std::string, std::string> TableVisualizer::color_string_map = {
    { "black",    XSTR(INDEX_BLACK)   },
    { "white",    XSTR(INDEX_WHITE)   },
    { "red",      XSTR(INDEX_RED)     },
    { "red tape", XSTR(INDEX_RED)     },
    { "green",    XSTR(INDEX_GREEN)   },
    { "blue",     XSTR(INDEX_BLUE)    },
    { "yellow",   XSTR(INDEX_YELLOW)  },
    { "magenta",  XSTR(INDEX_MAGENTA) },
    { "cyan",     XSTR(INDEX_CYAN)    }
};

static TableVisualizer visualizer;


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
static int ping( 
    const ip_t ip, 
    const int pings, 
    const int timeout_ms=100, 
    std::function<void(int)> draw_callback = nullptr
) {
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

    packet pckt;
    sockaddr_in r_addr;
    for( int loop=0; loop < pings; loop++ ) {
        socklen_t len = sizeof(r_addr);

        if (draw_callback) {
            draw_callback(loop);
        }

        if ( recvfrom(sd, &pckt, sizeof(pckt), 0, (sockaddr*)&r_addr, &len) > 0 ) {
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

        usleep(timeout_ms * 1000);
    }
    
    return 1;
}
[[maybe_unused]] static int ping( 
    const char *adress, 
    const int pings, 
    const int timeout_ms=100, 
    std::function<void(int)> draw_callback = nullptr
) {
    return ping( ip_t( *(long*)gethostbyname(adress)->h_addr ), pings, timeout_ms, draw_callback );
}
#define PING_SUCCESSFUL 0


//------------------------------------------------------------------------------
// ROVER SEARCHING / MATCHING ALGORIHM
//------------------------------------------------------------------------------

struct match_t {
    bool ip_lms, ip_livox, port;
    
    int count() const { return ip_lms + ip_livox + port; }
};
static match_t perform_rover_match(int rover_index) {
    match_t match{false, false, false};

    bool has_valid_ip_livox = rovers[rover_index].ip_livox.raw != 0;

    // search port
    match.port = access( rovers[rover_index].udev_symlink.c_str(), F_OK ) == ACCESS_PERMITTED;
    visualizer.print_line_with_status(
        rover_index, 
        TableVisualizer::Status::WAITING,
        has_valid_ip_livox ? TableVisualizer::Status::WAITING : TableVisualizer::Status::NOT_AVAILABLE,
        match.port ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE
    );
    
    // search ip lms
    match.ip_lms = ping( 
        rovers[rover_index].ip_lms, 
        config.count_ping_tries, 
        config.ping_timeout_ms, 
        [](int p){ 
            visualizer.status_ping_print_callback(p, visualizer.sizes.pos_status_column_1); 
        } 
    ) == PING_SUCCESSFUL;
    visualizer.print_line_with_status(
        rover_index, 
        match.ip_lms   ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE,
        has_valid_ip_livox ? TableVisualizer::Status::WAITING : TableVisualizer::Status::NOT_AVAILABLE,
        match.port     ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE,
        has_valid_ip_livox
    );
    
    // search ip livox
    if ( has_valid_ip_livox) {
        match.ip_livox = ping( 
            rovers[rover_index].ip_livox, 
            config.count_ping_tries, 
            config.ping_timeout_ms, 
            [](int p){ 
                visualizer.status_ping_print_callback(p, visualizer.sizes.pos_status_column_2); 
            } 
        ) == PING_SUCCESSFUL;
        visualizer.print_line_with_status(
            rover_index, 
            match.ip_lms   ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE,
            match.ip_livox ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE,
            match.port     ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE, 
            false
        );
    }
    
    LOG_ANSI( CNL(1) );

    return match;
}

/**
 * @brief finds best matching rover configuration by regarding the mapped udev ports and static lms ips
 * 
 * @return true if a new rover configuration was selected
 * @return false if the rover configuration is unchanged
 */
static bool find_rover() {
    static int previous_match_count = 0;
    bool check_already_connected = active_rover_index != -1;
    int best_rover_index = -1;
    int best_match = 0;
    bool changed = false;

    std::vector<match_t> matches;
    for( uint i=0; i < rovers.size(); i++ ) {
        matches.emplace_back( match_t{false, false, false} );
    }

    // Initialize rover table with default values
    // so that the user can see the table while the search is running
    for( const DetailedRoverInfo& rov : rovers ) {
        LOG_ANSI( EL(2) ); // clear line

        visualizer.print_rover_line_default( 
            rov, 
            TableVisualizer::Status::WAITING, 
            TableVisualizer::Status::WAITING,
            TableVisualizer::Status::WAITING
        );
    }
    
    // LOG_INFO("\n"); // +1
    LOG_INFO("%s\n", std::string(visualizer.sizes.table_width, '=').c_str() ); // +1
    LOG_INFO("\n"); // +1
    
    // Print rover selection status
    LOG_ANSI( EL(2) ); // clear line
    if ( check_already_connected ) {
        visualizer.print_rover_selection(
            XSTR(BLINK;ITALIC;FG_BRIGHT_BLUE), TableVisualizer::Titles::selection_status_validating,
            XSTR(ITALIC;FG_BRIGHT_BLUE), rovers[active_rover_index].name.c_str()
        );
    } else {
        visualizer.print_rover_selection(
            XSTR(BLINK;ITALIC;FG_WHITE), TableVisualizer::Titles::selection_status_searching,
            XSTR(ITALIC;FG_GRAY), "---"
        );
    }

    // save cursor position SCO and move back up to the first row of the table entries
    LOG_ANSI( SCO );
    LOG_ANSI( CPL(%ld), TableVisualizer::lines_per_rover * rovers.size() + 3);
    

    // artificially delay execution so that the user has enough time to "comprehend" what is happening
    IF_PRINT( sleep( 1 ) );


    // validate any previous connection -----------------------------------------------------------
    // greedily check if we are still connected to a previously connected rover
    if( check_already_connected ) {
        if( active_rover_index > 0 ) {
            // jump to rover position in table if not the first rover in the table
            LOG_ANSI( CNL(%d), TableVisualizer::lines_per_rover * active_rover_index );
        }

        matches[active_rover_index] = perform_rover_match( active_rover_index );
        LOG_ANSI( CPL(1) );

        if( matches[active_rover_index].count() >= previous_match_count ) {
            // we are still connected and therefore skip testing for other rovers
            
            // jump to bottom of table
            LOG_ANSI( CNL(%ld), TableVisualizer::lines_per_rover * (rovers.size() - active_rover_index) );
            
            // if active rover is still connected we skip testing for other rovers.
            // YESS, this is normally considered dirty, but this improves readability of the logic
            // and control flow over having to indent for another if clause
            // since we actively want to skip the whole best-matching search
            goto validated_connection;
        } else {
            if( active_rover_index > 0 ) {
                // jump back up to top rover position in table
                LOG_ANSI( CPL(%d), TableVisualizer::lines_per_rover * active_rover_index );
            }
        }
    }

    // search for best matching connection --------------------------------------------------------
    for( std::size_t i=0; i < rovers.size(); i++ ) {
        // if an rover is connected and we already checked for it above we can skip it now
        // else i will never be -1 and active_rover_index is -1 so the if case does not execute
        if ( i == static_cast<std::size_t>(active_rover_index) ) {
            LOG_ANSI( CNL(%d), TableVisualizer::lines_per_rover ); // jump to next rover position in table
            continue;
        }

        matches[i] = perform_rover_match( i );
    }
    
    best_rover_index = -1;
    best_match = 0;
    for( uint i=0; i < rovers.size(); i++) {
        if( matches[i].count() > best_match ) {
            best_rover_index = i;
            best_match = matches[i].count();
        }
    }

    changed = best_rover_index != active_rover_index;
    active_rover_index = best_rover_index;
    active_rover = active_rover_index == -1 ? &ROVER_DUMMY : &rovers[active_rover_index];    

    if ( changed ) {
        previous_match_count = best_match;
    }

    // print rover selection status ---------------------------------------------------------------
validated_connection:
    LOG_ANSI( CNL(2) ); // skip the separator lines between the table and selection status
    if ( active_rover_index == -1 ) {
        visualizer.print_rover_selection(
            changed
            ? XSTR(BG_BRIGHT_YELLOW;FG_BLACK)
            : XSTR(FG_GRAY),
            changed
            ? TableVisualizer::Titles::selection_status_new_rover
            : TableVisualizer::Titles::selection_status_not_changed,
            XSTR(BG_BRIGHT_RED;FG_BLACK),
            " NO ROVER CONNECTED "
        );
    } else {
        visualizer.print_rover_selection(
            changed
            ? XSTR(BG_BRIGHT_YELLOW;FG_BLACK)
            : XSTR(FG_BRIGHT_GREEN),
            changed
            ? TableVisualizer::Titles::selection_status_new_rover
            : TableVisualizer::Titles::selection_status_validated,
            XSTR(FG_BRIGHT_GREEN),
            rovers[active_rover_index].name.c_str()
        );
    }

    // reset the cursor to the first row of the table
    LOG_ANSI( CPL(%ld), TableVisualizer::lines_per_rover * rovers.size() + 3);

    // highlight the active rover in the table ----------------------------------------------------
    if( active_rover_index != -1 ) {
        if ( active_rover_index > 0 ) {
            LOG_ANSI( CNL(%d), TableVisualizer::lines_per_rover * active_rover_index ); // jump to rover position in table
        }
        
        visualizer.print_rover_line_activated(
            rovers[active_rover_index], 
            matches[active_rover_index].ip_lms   ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE, 
            matches[active_rover_index].ip_livox ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE, 
            matches[active_rover_index].port     ? TableVisualizer::Status::AVAILABLE : TableVisualizer::Status::NOT_AVAILABLE
        );
        LOG_ANSI( CPL(1) );

        if ( active_rover_index > 0 ) {
            LOG_ANSI( CPL(%d), TableVisualizer::lines_per_rover * active_rover_index ); // jump back up to first row
        }
    }   

    fflush( stdout ); // flush output buffer for any pending output to the console

    return changed;
}


//-----------------------------------------------------------------------------
// ROS SPECIFIC IMPLEMENTATIONS
//-----------------------------------------------------------------------------

static inline std::string to_lower( const std::string& str ) {
    std::string data = str;
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
    return data;
}

static bool manual_select_rover( const std::string& rover_name ) {
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
    VB::msg::Rover rov = active_rover->to_message();
    pub_rover->publish( rov );
}

static void find_and_publish() {
    bool found = find_rover();
    if( found || config.always_publish ) {
        publish_rover();
    }
}


int main(int argc, char* argv[]) {
    signal(SIGINT, [](int sig){
        (void)sig;
        LOG_LN_ANSI( RCP ); // restore cursor position (last SCO) // new line to flush the buffer
        rclcpp::shutdown();
        exit(0);
    });
    
    LOG_ANSI( ED(2) CUP(1,1) ); // clear screen // and move cursor home
    parse_yaml( PATH_YAML_ROVERS );

    visualizer.set_sizes();
    visualizer.print_table();


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
        // move cursor back up to first table row
        LOG_ANSI( CPL(%ld), TableVisualizer::lines_per_rover * rovers.size() + 1);
    
        find_and_publish();
        timer = node->create_wall_timer( config.pub_period, find_and_publish );
    }

    rclcpp::spin( node );
    rclcpp::shutdown();

    return 0;
}