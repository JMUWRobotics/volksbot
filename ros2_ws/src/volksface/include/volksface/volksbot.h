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
            EPOS2   = 1
        };
        static inline MCD from_int( const int mcd_code ) {
            switch( mcd_code ) {
                case VMC: return VMC;
                case EPOS2: return EPOS2;
                case ERROR:
                default:
                    return ERROR;
            }
        }
        static inline MCD from_string( const std::string& mcd_name ) {
            return  mcd_name.compare( "VMC" ) == 0 ? VMC :
                    mcd_name.compare( "EPOS2" ) == 0 ? EPOS2 :
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

    struct Rover {
        // rover name
        std::string name;                   // case insensitive
        
        // wheels
        float wheel_diameter;               // cm
        float wheel_base;                   // cm // distance between wheel center points

        // motor controller
        MCD::MCD motor_controller;          // id of motor controller
        std::string motor_controller_port;  // port to be passed to the specified motor controller 
        
        std::string udev_symlink;           // device port mapping (usually: /dev/xyz) as noted in 42-usb-serial-volksbot.rules
        
        // lms
        ip_t ip_lms;                        // static ip of laserscanner
    };

    /**
     * @brief simple hash function for strings, which creates an hash value for the first 64 characters
     */
    inline uint64_t hash( const std::string& str ) {
        const size_t length = str.length() < 64 ? str.length() : 64;

        uint64_t running_hash = 0;

        for( size_t i=0; i < length; i++ ) {
            running_hash += str[i] << i % 64;
        };

        return running_hash;
    }

    /**
     * @brief simple hash functionality for VB::Rover and VB::msg::Rover
     */
    inline uint64_t hash( const Rover* rov ) {
        return hash( rov->name )
            ^  (uint64_t)rov->wheel_diameter
            ^  (uint64_t)rov->wheel_base
            ^  (uint64_t)rov->motor_controller
            ^  hash( rov->motor_controller_port )
            ^  hash( rov->udev_symlink )
            ^  (uint64_t)rov->ip_lms.raw;
    }
    /**
     * @brief simple hash functionality for VB::Rover and VB::msg::Rover
     */
    inline uint64_t hash( const msg::Rover& rov ) {
        return hash( rov.name.c_str() )
            ^  (uint64_t)rov.wheel_diameter
            ^  (uint64_t)rov.wheel_base
            ^  (uint64_t)rov.motor_controller
            ^  hash( rov.motor_controller_port.c_str() )
            ^  hash( rov.udev_symlink.c_str() )
            ^  (uint64_t)rov.ip_lms;
    }
    /**
     * @brief simple hash functionality for VB::Rover and VB::msg::Rover
     */
    inline uint64_t hash( msg::Rover::ConstSharedPtr rov ) { return hash( *rov ); }

    inline msg::Rover to_message( const Rover& rov, bool is_valid = true ) {
        msg::Rover mrov;

        mrov.is_valid = is_valid;

        mrov.name = rov.name;
        
        mrov.wheel_diameter = rov.wheel_diameter;
        mrov.wheel_base = rov.wheel_base;
        
        mrov.motor_controller = rov.motor_controller;
        mrov.motor_controller_port = rov.motor_controller_port;

        mrov.udev_symlink = rov.udev_symlink;
        
        mrov.ip_lms = rov.ip_lms.raw;

        return mrov;
    }

}


#endif