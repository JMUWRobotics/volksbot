#include <cstdlib>
#include <stdio.h>

#include <rclcpp/rclcpp.hpp>

#define VB_NO_GEOMETRY
#include "volksface/volksbot.h"
#include "volksface/ansi.h"

// #include "sick_scan/sick_generic_laser.h"

static constexpr const char* PATH_LAUNCH_LMS1XX = "./src/sick_scan_xd/launch/sick_lms_1xx.launch";



static rclcpp::Node::SharedPtr node;
static rclcpp::Subscription<VB::msg::Rover>::SharedPtr sub;
static VB::msg::Rover active_rover;
static FILE* sick_process = NULL;

static void call_launch_from_rover( VB::msg::Rover::ConstSharedPtr rov ) {
    if( VB::hash( rov ) == VB::hash( active_rover ) ) {
        // same rover as before => skip
        return;
    }
    
    // new rover
    printf( ED(2) "\n" ); // clear screen
    if( sick_process != NULL ) {
        printf( "ROVER %s [%s] was closed with code: %d\n",
            active_rover.name.c_str(),
            VB::ip_t( active_rover.ip_lms ).to_string().c_str(),
            pclose( sick_process )
        );
    }

    active_rover = *rov;
    printf( "ROVER %s [%s] was recognized and is %s\n",
        active_rover.name.c_str(),
        VB::ip_t( active_rover.ip_lms ).to_string().c_str(),
        active_rover.is_valid ? COL(32, "valid") : COL(31, "invalid")
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
        printf( COL(31, "Failed to call launch file for lms100\n") );
        return;
    }
    
    printf( COL(32, "successful launched lms100\n") );
}

int main( int argc, char* argv[] ) {
    rclcpp::init(argc, argv);

    node = rclcpp::Node::make_shared( "lms_starter" );

    printf( ">>> lms_starter: started\n" COL(BLINK, ">>> waiting for rover to be published\n") );
    
    sub = node->create_subscription<VB::msg::Rover>( VB::TOPIC_NAME_ROVER, 1, call_launch_from_rover );

    rclcpp::spin( node );
    rclcpp::shutdown();

    return 0;
}