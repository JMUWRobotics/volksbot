/////////////////////////////////////////////////////////////////////////////
// @file    volksbot.h
// @brief   static definitions of global volksbot topics & services and rover configuration
// @author  Nico Schubert
// @date    26.06.2025
/////////////////////////////////////////////////////////////////////////////


// can be included in source files with
// #include "volksface/volksbot.h"

// if no geometry messages are needed one can disable it by defining:
// #define VB_NO_GEOMETRY

#ifndef __VOLKSBOT_H__
#define __VOLKSBOT_H__

#include <stdint.h>
#include <string.h>

// interface messages and services
#include "volksface/msg/gamepad.hpp"
#include "volksface/msg/mc_ticks.hpp"
#include "volksface/msg/pose2d.hpp"
#include "volksface/msg/rover.hpp"
#include "volksface/msg/vel_gp.hpp"

#include "volksface/srv/rumble.hpp"
#include "volksface/srv/vel_cmd.hpp"

#ifndef VB_NO_GEOMETRY
#include <geometry_msgs/msg/twist.hpp>
#endif

namespace VB {
    typedef const char* topic_id_t;
    typedef const char* service_id_t;

    // Topic names
    static constexpr topic_id_t TOPIC_NAME_GAMEPAD      = "Gamepad";
    static constexpr topic_id_t TOPIC_NAME_POSE2D       = "Pose2d";
    static constexpr topic_id_t TOPIC_NAME_ROVER        = "Rover";
    static constexpr topic_id_t TOPIC_NAME_TICKS        = "MC_ticks";
	static constexpr topic_id_t TOPIC_NAME_VEL_GP       = "Vel_gp";
	static constexpr topic_id_t TOPIC_NAME_VEL_TWIST    = "Vel_twist";
    static constexpr topic_id_t TOPIC_NAME_ODOMETRY     = "odom";
    
    // Service names
    static constexpr service_id_t SERVICE_NAME_COMMAND  = "Vel_cmd";
    static constexpr service_id_t SERVICE_NAME_RUMBLE   = "Rumble";

    // namespace simplification
    using namespace volksface;

    #ifndef VB_NO_GEOMETRY
    using msg__Twist = geometry_msgs::msg::Twist;
	#endif

    namespace MCD {
        enum MCD : uint8_t {
            ERROR   = 0xff,
            VMC     = 0,
            EPOS2   = 1,
            EPOS4   = 2
        };
        static inline MCD from_int( const int mcd_code ) {
            switch( mcd_code ) {
                case VMC: return VMC;
                case EPOS2: return EPOS2;
                case EPOS4: return EPOS4;
                case ERROR:
                default:
                    return ERROR;
            }
        }
        static inline MCD from_string( const std::string& mcd_name ) {
            return  mcd_name.compare( "VMC" ) == 0 ? VMC :
                    mcd_name.compare( "EPOS2" ) == 0 ? EPOS2 :
                    mcd_name.compare( "EPOS4" ) == 0 ? EPOS4 :
                    ERROR;
        }
        static inline std::string to_string( const MCD mcd ) {
        // Rover configuration
            switch( mcd ) {
                case VMC: return "VMC";
                case EPOS2: return "EPOS2";
                case ERROR:
                default:
                    return "ERROR";
            }
        }
    }

    union ip_t {
        uint32_t raw;
        struct { uint8_t hh, hl, lh, ll; } ip;
        constexpr ip_t( uint32_t raw ) : raw(raw) {}
        constexpr ip_t( uint8_t hh, uint8_t hl, uint8_t lh, uint8_t ll ) : ip({hh, hl, lh, ll}) {}
        constexpr ip_t() : ip_t(0) {}
        
        inline std::string to_string( const int padding=0 ) const {
            char ip_char[ sizeof( "xxx.xxx.xxx.xxx" ) ];

            int n = padding >= 0 ? (padding <= 3 ? padding : 3) : 0;

            snprintf(
                ip_char,
                sizeof(ip_char)/sizeof(char),
                "%*d.%*d.%*d.%*d",
                n, ip.hh,
                n, ip.hl,
                n, ip.lh,
                n, ip.ll
            );

            return std::string( ip_char );
        }
        static inline bool from_string( const std::string& ip_str, ip_t& out_ip ) {
            int ip_ints[4];

            int sepL, sepR=-1;

            for( int i=0; i < 3; i++ ) {
                sepL = sepR;
                sepR = ip_str.find( '.', sepL+1 );
                
                if( sepR == ip_str.npos ) { // no separator found
                    return false;
                }
                
                ip_ints[i] = std::stoi( ip_str.substr( sepL+1, sepR-(sepL+1) ) );

                if( ip_ints[i] < 0 || ip_ints[i] > 0xff ) { // out of bounds
                    return false;
                }
            }

            // last int
            ip_ints[3] = std::stoi( ip_str.substr( sepR+1, ip_str.length()-(sepR+1) ) );
            
            if( ip_ints[3] < 0 || ip_ints[3] > 0xff ) { // out of bounds
                return false;
            }

            out_ip.ip.hh = (uint8_t)( ip_ints[0] );
            out_ip.ip.hl = (uint8_t)( ip_ints[1] );
            out_ip.ip.lh = (uint8_t)( ip_ints[2] );
            out_ip.ip.ll = (uint8_t)( ip_ints[3] );

            return true;
        }
    };

    struct WheelMapping {
        /**
         * @brief Mapping matrix from input wheel speeds (left, right) to physical wheel speed directions
         * wheel_out = M * speed_in
         * 
         * => M = [ M[0][0]  M[0][1] ]
         *        [ M[1][0]  M[1][1] ]
         */
        float M[2][2];

        void apply( float in_left, float in_right, float& out_left, float& out_right ) const {
            out_left  = M[0][0] * in_left  + M[0][1] * in_right;
            out_right = M[1][0] * in_left  + M[1][1] * in_right;
        }
        float determinant() const {
            return M[0][0] * M[1][1] - M[0][1] * M[1][0];
        }
        void reverse( float in_left, float in_right, float& out_left, float& out_right ) const {
            // calculate determinant
            const float det = determinant();

            if( det == 0.0f ) {
                out_left = std::numeric_limits<float>::infinity();
                out_right = std::numeric_limits<float>::infinity();
                return;
            }

            // calculate inverse matrix
            float invM[2][2] = {
                {  M[1][1] / det, -M[0][1] / det },
                { -M[1][0] / det,  M[0][0] / det }
            };

            out_left  = invM[0][0] * in_left  + invM[0][1] * in_right;
            out_right = invM[1][0] * in_left  + invM[1][1] * in_right;
        }
    };

    struct Rover {
        // rover name
        std::string name;                   // case insensitive
        
        // wheels
        float wheel_diameter;               // cm
        float wheel_base;                   // cm // distance between wheel center points
        WheelMapping wheel_mapping = { { { 1.0f,  0.0f },
                                         { 0.0f,  1.0f } } }; // default: direct mapping

        // motor controller
        MCD::MCD motor_controller;          // id of motor controller
        std::string motor_controller_port;  // port to be passed to the specified motor controller 
        
        std::string udev_symlink;           // device port mapping (usually: /dev/xyz) as noted in 42-usb-serial-volksbot.rules
        
        // lms
        ip_t ip_lms;                        // static ip of laserscanner

        bool is_valid = true;               // indicates if the rover configuration is valid

        // converts Rover to volksface::msg::Rover
        msg::Rover to_message() const {
            msg::Rover mrov;

            mrov.is_valid = is_valid;

            mrov.name = name;
            
            mrov.wheel_diameter = wheel_diameter;
            mrov.wheel_base = wheel_base;
            mrov.wheel_mapping.matrix[0] = wheel_mapping.M[0][0];
            mrov.wheel_mapping.matrix[1] = wheel_mapping.M[0][1];
            mrov.wheel_mapping.matrix[2] = wheel_mapping.M[1][0];
            mrov.wheel_mapping.matrix[3] = wheel_mapping.M[1][1];
            
            mrov.motor_controller = motor_controller;
            mrov.motor_controller_port = motor_controller_port;

            mrov.udev_symlink = udev_symlink;
            
            mrov.ip_lms = ip_lms.raw;

            return mrov;
        }
        // converts volksface::msg::Rover to Rover
        void from_message( msg::Rover::ConstSharedPtr mrov ) {
            name = mrov->name;
            
            wheel_diameter = mrov->wheel_diameter;
            wheel_base = mrov->wheel_base;
            wheel_mapping = { { { mrov->wheel_mapping.matrix[0], mrov->wheel_mapping.matrix[1] },
                                { mrov->wheel_mapping.matrix[2], mrov->wheel_mapping.matrix[3] } } };
            
            motor_controller = MCD::from_int( mrov->motor_controller );
            motor_controller_port = mrov->motor_controller_port;

            udev_symlink = mrov->udev_symlink;
            
            ip_lms.raw = mrov->ip_lms;
            is_valid = mrov->is_valid;
        }
        // creates Rover from volksface::msg::Rover
        static Rover from_message( const msg::Rover& mrov ) {
            Rover rov;
            rov.from_message( mrov );
            return rov;
        }

        bool operator==( const Rover& other ) const {
            return  name                  == other.name                  &&
                    wheel_diameter        == other.wheel_diameter        &&
                    wheel_base            == other.wheel_base            &&
                    motor_controller      == other.motor_controller      &&
                    motor_controller_port == other.motor_controller_port &&
                    udev_symlink          == other.udev_symlink          &&
                    ip_lms.raw            == other.ip_lms.raw;
        }
        bool operator==( msg::Rover::ConstSharedPtr other ) const {
            return  name                  == other->name                  &&
                    wheel_diameter        == other->wheel_diameter        &&
                    wheel_base            == other->wheel_base            &&
                    motor_controller      == MCD::from_int( other->motor_controller ) &&
                    motor_controller_port == other->motor_controller_port &&
                    udev_symlink          == other->udev_symlink          &&
                    ip_lms.raw            == other->ip_lms;
        }

        bool operator!=(auto x) const { return !(this->operator==(x)); }
    };
} // namespace VB


#endif