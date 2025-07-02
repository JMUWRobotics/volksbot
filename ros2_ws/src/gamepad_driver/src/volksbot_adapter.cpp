/////////////////////////////////////////////////////////////////////////////
// @file    volksbot_adapter.h
// @brief   Middle layer to manage the publishes and services of Gamepad data for the Volksbots project
// @author  Nico Schubert
// @date    31.03.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __VOLKSBOT_ADAPTER__
#define __VOLKSBOT_ADAPTER__

#include <sysexits.h>
#include <chrono>
#include <math.h>
using namespace std::chrono_literals;

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors.hpp"

#define VB_NO_GEOMETRY
#include "volksface/volksbot.h"

#include "device_utils.h"


#define SPIN_PERIOD    100ms
#define PUBLISH_PERIOD  10ms


#define PRINT_STATE
// #define PRINT_EVENT
// #define PRINT_VEL_CTRL
// #define ACCEL_FORCE_FEEDBACK


using std::placeholders::_1;
using std::placeholders::_2;


#define PI 3.14159265
#define DEG2RAD(x)  ((x) * PI / 180.0)
#define RAD2DEG(x)  ((x) * 180.0 / PI)

template<typename T>
int sgn(const T val) {
    return val > T(0) ? 1 : (val < T(0) ? -1 : 0);
}
float dist(const float x, const float y) {
    return sqrtf( x*x + y*y );
}
template<typename T> T max( const T a, const T b ) { return a >= b ? a : b; }
template<typename T> T min( const T a, const T b ) { return a <= b ? a : b; }


using namespace std::chrono;
using namespace VB;
struct vel_ctrl_t {

    /* cm/s */
    static constexpr int speed_min = 10, speed_max = 100, speed_step = 10;
    msg::VelGP vel; /* vel msg */

    void update( Gamepad* gp ) {
        this->gp = gp;

        if( gp == nullptr || !gp->has_connection() ) {
            vel.left = vel.right = 0;
            return;
        }

        auto now = system_clock::now();
        dt = now - last_update;
        last_update = now;

        if( last_event_id != gp->get_last_event_id() ) {
            last_event_id = gp->get_last_event_id();
            apply_event( gp->get_last_event() );
            apply_state( gp->get_state() );
        }
        
        if( stop_rumble != system_clock::time_point()) {
            if( system_clock::now() >= stop_rumble ) {
                gp->set_rumble( 0, 0 );
                stop_rumble = system_clock::time_point();
            }
        }
    }

    private:
        // Velocity calculation variables    
        int  speed = 20;            /* cm / s */
        bool is_stick_drive = true; /* stick or paddle */
        int  throttle_sign = 0;     /* last sign of throttle */

        // Constants
        const float throttle_sign_deadzone = tan( DEG2RAD(10) ); /* angle of deadzone for throttle sign */
        static constexpr float ff_feedback_max_accel = 2500.0f; /* cm/s /s */
        static constexpr float ff_feedback_min_accel = 500.0f; /* cm/s /s */

        // gamepad management variables
        Gamepad* gp;
        system_clock::time_point stop_rumble, last_update;
        system_clock::duration dt;
        uint32_t last_event_id = -1;
        
        void set_rumble( const uint16_t strong, const uint16_t weak, const milliseconds time ) {
            gp->set_rumble( strong, weak );
            stop_rumble = system_clock::now() + time;
        }

        #define EVENT_PRESSED(ev, c)  ( ((ev).code) == (c) && ((ev).value.btn) )
        void apply_event( const gp_event_t gpe ) {
            if( gpe.is_axis ) {
                return;
            }

            if( EVENT_PRESSED(gpe, gp_index::START) ) {
                is_stick_drive = !is_stick_drive;
                throttle_sign = 0;
                set_rumble( 0x7FFF, 0x7FFF, 100ms );
            }

            if( EVENT_PRESSED(gpe, gp_index::LB) ) {
                speed = max( speed_min, speed-10 );
            }
            
            if( EVENT_PRESSED(gpe, gp_index::RB) ) {
                speed = min( speed+10, speed_max );
            }
            
            if( EVENT_PRESSED(gpe, gp_index::LB) || EVENT_PRESSED(gpe, gp_index::RB) ) {
                if( speed == speed_min || speed == speed_max ) {
                    set_rumble( 0xFFFF, 0xFFFF, 100ms );
                }
            }
        }

        void apply_state( const gp_state gps ) {
            float abs_throttle, throttle;
            float factor_left, factor_right, rot_factor;
            bool throttle_non_deadzone = false;

            if( is_stick_drive ) {
                /**
                 * main movement is controlled with the left thumbstick
                 * where:
                 *      - up:   (throttle-)forward
                 *      - down: (throttle-)backwards
                 *      - left:  turning left
                 *      - right: turning right
                 */
                abs_throttle = dist(gps.thumb_stick_left.up_down, gps.thumb_stick_left.left_right) / (float)AXIS_VALUE_MAX;

                throttle_non_deadzone = abs( gps.thumb_stick_left.up_down / (float)gps.thumb_stick_left.left_right ) > throttle_sign_deadzone;
                if( throttle_non_deadzone ) {
                    throttle_sign = sgn(gps.thumb_stick_left.up_down);
                }

                throttle = abs_throttle * throttle_sign;            
            } else {
                /**
                 * main movement is controlled with the left thumbstick and the throttle paddles
                 * where:
                 *      - paddle-right: (throttle-)forward
                 *      - paddle-left:  (throttle-)backwards
                 *      - left:  turning left
                 *      - right: turning right
                 */
                throttle = ( gps.throttle.right - gps.throttle.left ) / (float)AXIS_VALUE_MAX;
                
                // not required (i.e. just for debug printout)
                abs_throttle = abs(throttle);
            }

            factor_left  = throttle * min( 1.0 - gps.thumb_stick_left.left_right / (float)AXIS_VALUE_MAX, 1.0 );
            factor_right = throttle * min( 1.0 - gps.thumb_stick_left.left_right / (float)AXIS_VALUE_MIN, 1.0 );
            
            /**
             * right thumbstick can be used to turn on the spot, i.e. rotate with out lateral movement
             *      - left:  rotate counterclockwise (ccw)
             *      - right: rotate clockwise (cw)
             */
            rot_factor = gps.thumb_stick_right.left_right / (float)AXIS_VALUE_MAX;

            factor_left  -= rot_factor;
            factor_right += rot_factor;

            factor_left  = max( -1.0f, min(factor_left , 1.0f) );
            factor_right = max( -1.0f, min(factor_right, 1.0f) );

            float new_vel_left  = speed * factor_left;
            float new_vel_right = speed * factor_right;
            
            #ifdef ACCEL_FORCE_FEEDBACK
                float accel_left  = abs( new_vel_left  - vel.left  ) / ( duration_cast<nanoseconds>(dt).count() / 1e9 );
                float accel_right = abs( new_vel_right - vel.right ) / ( duration_cast<nanoseconds>(dt).count() / 1e9 );

                float max_accel = max( accel_left, accel_right );
                
                if( max_accel > ff_feedback_min_accel ) {
                    float factor = (max_accel-ff_feedback_min_accel) / (ff_feedback_max_accel-ff_feedback_min_accel);
                    uint16_t val = (uint16_t)(0xFFFF * min( factor, 1.0f));
                    set_rumble( val, val, 50ms );
                }
            #endif

            vel.left  = new_vel_left;
            vel.right = new_vel_right;

            // Debuging
            #ifdef PRINT_VEL_CTRL
                printf( "DRIVE MODE: " COL(94, "%-9s") "\n", is_stick_drive ? "stick" : "paddle" );        
                printf( "throttle-abs:  " COL(94, "%4.0f") "%%\n", abs_throttle*100 );
                printf( "throttle-sign: " COL(94, "%4d")   "\n", throttle_sign );
                printf( "throttle-dead: " COL(94, "%5s")   "\n", throttle_non_deadzone ? "false" : "true" );
                printf( "throttle:      " COL(94, "%4.0f") "%%\n", throttle*100 );
                printf( "\n" );
                printf( "factor-left: " COL(94, "%6.1f") "%% factor-right: " COL(94, "%6.1f") "%%\n", factor_left*100, factor_right*100 );
                printf( "rot_factor:  " COL(94, "%6.1f") "%%\n", rot_factor*100 );
                printf( "\n" );
                printf( "speed: " COL(94, "%4d") " cm/s\n", speed );
                printf( "dt: " COL(94, "%8.3f") " ms            \n", duration_cast<nanoseconds>(dt).count()/1e6 );
                printf( "dv-left: " COL(94, "%6.3f") " dv-right: " COL(94, "%6.3f") "\n", accel_left*duration_cast<nanoseconds>(dt).count()/1e9, accel_right*duration_cast<nanoseconds>(dt).count()/1e9 );
                printf( "accel-left: " COL(94, "%8.2f") " accel-right: " COL(94, "%8.2f") "\n", accel_left, accel_right);
                printf( "vel-left: " COL(94, "%7.2f") " vel-right: " COL(94, "%7.2f") "\n", vel.left, vel.right );
                printf("\x1b[14F");
            #endif
        }
} vel_ctrl;

class Volks_gamepad : public rclcpp::Node {
    public:
        Volks_gamepad() : Node( "Volks_gamepad" ) {
            _pub_vel = create_publisher<msg::VelGP>( VB::TOPIC_NAME_VEL_GP, 10 );
            _pub_gp  = create_publisher<msg::Gamepad>( VB::TOPIC_NAME_GAMEPAD, 10 );
            _service_rumble = create_service<srv::Rumble>( VB::SERVICE_NAME_RUMBLE, std::bind( &Volks_gamepad::set_rumble, this, _1, _2) );


            while( rclcpp::ok() ) {
                active_gamepad = device_util::select_and_connect_gamepad();

                if( active_gamepad != nullptr )
                    break;
                
                rclcpp::sleep_for( nanoseconds( 1000ms ) );
            }
            active_gamepad->print_evio();
        }
        
        void run( rclcpp::Executor& executor ) {
            rclcpp::Time t1, t0 = get_clock()->now();

            while( rclcpp::ok() ) {
                while ( active_gamepad->has_connection() ) {
                    if( !rclcpp::ok() ) {
                        return;
                    }
                    
                    active_gamepad->wait_for_event();
                    
                    #ifdef PRINT_STATE
                        active_gamepad->print_state();
                    #endif
                    #ifdef PRINT_EVENT
                        active_gamepad->print_event();
                    #endif
                    
                    // custom
                    // if( active_gamepad->get_state().buttons.B ) {
                    //     active_gamepad->set_rumble( 2*active_gamepad->get_state().throttle.left, 2*active_gamepad->get_state().throttle.right );
                    // }
                    
                    // continue;
                    publish();

                    t1 = get_clock()->now();
                    if( t1 - t0 >= SPIN_PERIOD ) {
                        t0 = t1;
                        executor.spin_once( nanoseconds( 10ms ) );
                    }
                }

                // try to reconnect
                printf( COL(91, "Gamepad got disconnected!") " Trying to reconnect to " COL(1;94, "%s") "\n", active_gamepad->get_name().c_str() );

                if( device_util::try_reconnect( active_gamepad ) ) {
                    printf( COL(92, "Successfully reconnected to %s\n"), active_gamepad->get_name().c_str() );
                } else {
                    rclcpp::sleep_for( nanoseconds( 1000ms ) );
                }

                publish();
                executor.spin_once( nanoseconds( 10ms ) );
            }
        }

    private:
        // ros
        rclcpp::Publisher<msg::VelGP>::SharedPtr     _pub_vel;
        rclcpp::Publisher<msg::Gamepad>::SharedPtr _pub_gp;
        rclcpp::Service<srv::Rumble>::SharedPtr    _service_rumble;
        
        // data
        Gamepad* active_gamepad;

        void publish() {
            static rclcpp::Time t0 = get_clock()->now(), t1;

            t1 = get_clock()->now();
            if( t1 - t0 >= PUBLISH_PERIOD ) {
                t0 = t1;
                vel_ctrl.update( active_gamepad );
                publish_state();
                publish_vel();
            }
        }
        void publish_state() {
            if( active_gamepad == nullptr )
                return;

            msg::Gamepad msg_gp;
            msg_gp.connected = active_gamepad->has_connection();

            if( msg_gp.connected ) {
                gp_state state_gp = active_gamepad->get_state();
                memcpy( (void*)&msg_gp, (void*)&state_gp, sizeof(state_gp) );
            }

            _pub_gp->publish( msg_gp );
        }
        void publish_vel() {
            _pub_vel->publish( vel_ctrl.vel );
        }
        void set_rumble(
            srv::Rumble::Request::ConstSharedPtr request,
            srv::Rumble::Response::SharedPtr response
        ) {
            (void) response; // to surpress compiler warning

            if( active_gamepad == nullptr )
                return;
            
            active_gamepad->set_rumble( request->motor_strong, request->motor_weak );
        }
};


int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    rclcpp::init(argc, argv);

    rclcpp::executors::StaticSingleThreadedExecutor executor;
    std::shared_ptr<Volks_gamepad> vgp = std::make_shared<Volks_gamepad>();

    executor.add_node( vgp );
    vgp->run( executor );

    rclcpp::shutdown();

    return EX_OK;
}


#endif