#include <cstdlib>
#include <stdio.h>

#include <rclcpp/rclcpp.hpp>

#define VB_NO_GEOMETRY
#include "volksface/volksbot.h"

#ifdef USE_LOGGING_LMS_STARTER
    #undef USE_LOGGING
    #define USE_LOGGING USE_LOGGING_LMS_STARTER
#endif

#define LOGGING_NAME "lms_starter"
#include "volksface/logging.h"


// #include "sick_scan/sick_generic_laser.h"

static constexpr const char* PATH_LAUNCH_LMS1XX = "./src/sick_scan_xd/launch/sick_lms_1xx.launch";



static rclcpp::Node::SharedPtr node;
static rclcpp::Subscription<VB::msg::Rover>::SharedPtr sub;
static VB::Rover active_rover;
static FILE* sick_process = NULL;

static void call_launch_from_rover( VB::msg::Rover::ConstSharedPtr rov ) {
    if( active_rover == rov ) {
        // same rover as before => skip
        return;
    }
    
    // new rover
    LOG_LN_ANSI( ED(2) ); // clear screen
    if( sick_process != NULL ) {
        LOG_LN_INFO( "ROVER %s [%s] was closed with code: %d",
            active_rover.name.c_str(),
            VB::ip_t( active_rover.ip_lms ).to_string().c_str(),
            pclose( sick_process )
        );
    }

    active_rover.from_message( rov );
    LOG_LN_INFO( "ROVER %s [%s] was recognized and is %s",
        active_rover.name.c_str(),
        VB::ip_t( active_rover.ip_lms ).to_string().c_str(),
        active_rover.is_valid ? COL(FG_GREEN, "valid") : COL(FG_RED, "invalid")
    );

    if( !active_rover.is_valid ) {
        // invalide rovers will not invoke sick backend
        return;
    }

    
    std::string cmd =
        ". ./install/setup.bash & "
        "ros2 run sick_scan_xd sick_generic_caller " + std::string(PATH_LAUNCH_LMS1XX) +
        " hostname:=" + VB::ip_t( active_rover.ip_lms ).to_string();
    
    sick_process = popen( cmd.c_str(), "r" );

    if( sick_process == NULL ) {
        LOG_LN_WARN( COL(FG_RED, "Failed to call launch file for lms100") );
        return;
    }
    
    LOG_LN_INFO( COL(FG_GREEN, "successful launched lms100") );
}

int main( int argc, char* argv[] ) {
    rclcpp::init(argc, argv);

    node = rclcpp::Node::make_shared( "lms_starter" );

    LOG_LN_INFO( ">>> lms_starter: started" );
    LOG_LN_INFO( COL(BLINK;FG_BLUE, ">>> waiting for rover to be published") );
    
    sub = node->create_subscription<VB::msg::Rover>( VB::TOPIC_NAME_ROVER, 1, call_launch_from_rover );

    rclcpp::spin( node );
    rclcpp::shutdown();

    return 0;
}