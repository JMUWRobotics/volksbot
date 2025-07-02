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

    // Rover configuration
    enum MCD : uint8_t {
        ERROR   = 0xff,
        VMC     = 0,
        EPOS2   = 1
    };

    union ip_t {
        uint32_t raw;
        struct { uint8_t hh, hl, lh, ll; } ip;
        constexpr ip_t( uint32_t raw ) : raw(raw) {}
        constexpr ip_t( uint8_t hh, uint8_t hl, uint8_t lh, uint8_t ll ) : ip({hh, hl, lh, ll}) {}
    };

    struct Rover {
        // rover name
        const char* name;
        
        // wheels
        const float wheel_diameter;         // cm
        const float wheel_base;             // cm // distance between wheel center points

        // motor controller
        const MCD motor_controller;         // id of motor controller
        const char* motor_controller_port;  // port to be passed to the specified motor controller 
        
        const char* udev_symlink;           // device port mapping (usually: /dev/xyz) as noted in 42-usb-serial-volksbot.rules
        
        // lms
        const ip_t ip_lms;                  // static ip of laserscanner
    };
}


#endif