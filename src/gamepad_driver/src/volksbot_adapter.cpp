/////////////////////////////////////////////////////////////////////////////
// @file    volksbot_adapter.h
// @brief   Middle layer to manage the publishes and services of Gamepad data for the Volksbots project
// @author  Nico Schubert
// @date    31.03.2025
/////////////////////////////////////////////////////////////////////////////

/*
    TODOs:
    // create simple automatic game pad detection and selection
    // create autonomous rumble event handling (via Threading?)
    //- add disconnection detector with reconnect ability
    - integrate ROS2 (Services & Publishers) 
    
    => Integrate into Volksbot package
*/



#ifndef __VOLKSBOT_ADAPTER__
#define __VOLKSBOT_ADAPTER__

#include <sysexits.h>
#include <chrono>
using namespace std::chrono_literals;

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "device_utils.h"


class Volks_gamepad : public rclcpp::Node {
    public:
        // ros
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub;
        
        // data
        Gamepad* active_gamepad;

        Volks_gamepad()
        : Node( "Volks_gamepad" )
        {
            run();
        }

        void run() {
            Gamepad* gp = device_util::select_and_connect_gamepad();

            if( gp == nullptr )
                rclcpp::shutdown(nullptr, "Could not connect to any gamepad device");

            gp->print_evio();
            
            while( rclcpp::ok() ) {
                while ( gp->has_connection() ) {
                    if( !rclcpp::ok() ) {
                        return;
                    }
                    
                    gp->wait_for_event();
                    
                    gp->print_state();
                    // gp->print_event();
                    
                    // custom
                    if( gp->get_state().buttons.A ) {
                        gp->set_rumble( gp->get_state().throttle.left, gp->get_state().throttle.right );
                    }
                }

                // try to reconnect
                printf( COL(91, "Gamepad got disconnected!") " Trying to reconnect to " COL(1;94, "%s") "\n", gp->get_name().c_str() );

                if( device_util::try_reconnect( gp) ) {
                    printf( COL(92, "Successfully reconnected to %s\n"), gp->get_name().c_str() );
                } else {
                    rclcpp::sleep_for( std::chrono::nanoseconds( 1000ms ) );
                }
            }

            rclcpp::shutdown();
        }
};


int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    
    rclcpp::init(argc, argv);

    Volks_gamepad vgp;
    rclcpp::spin( std::shared_ptr<Volks_gamepad>( &vgp ) );

    rclcpp::shutdown();

    return EX_OK;
}










#endif