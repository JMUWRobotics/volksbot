#ifndef __DRIVER_INTERFACE_H__
#define __DRIVER_INTERFACE_H__

#include <cmath>

#include "ros2_logger.h"

// Motor Controller Driver
namespace mcd {

    namespace util {
        /**
         * @brief calculate the ticks per cm value for a given wheel 
         * 
         * @param tick_per_rev ticks per revolution [tick/rev]
         * @param wheel_diameter_cm diameter in cm of the wheel [cm]
         * @return double ticks per cm [tick/cm]
         */
        float inline tick_per_cm( float tick_per_rev, float wheel_diameter_cm ) {
            float cm_per_rev = M_PI * wheel_diameter_cm;
            return tick_per_rev / cm_per_rev;
        }

        /**
         * @brief calculate the linear and angular twist values like used in the geometry messages
         * @note when looking from above: positive angles are ccw and negatives are cw
         * 
         * @param wheel_base_cm distance between the left and right wheel in [cm]
         * @param left_vel      speed of left wheel in [cm/s]
         * @param right_vel     speed of right wheel in [cm/s]
         * @param linear        [out] linear speed of the robot in [cm/s]
         * @param angular       [out] angular speed of the robot in [rad/s]
         */
        void inline linear_twist(
            float wheel_base_cm,
            float left_vel,    // cm / s
            float right_vel,   // cm / s
            float& linear,     // cm / s
            float& angular     // rad / s
        ) {
            angular = (right_vel - left_vel) / wheel_base_cm; // radian / s
            linear  = (right_vel + left_vel) / 2.0;           // cm / s
        }
    }

    /**
     * @brief Common interface for Motor Controller Drivers
     */
    class I_MCD {
    public:
        virtual ~I_MCD() = default;

        virtual float ticks_per_revolution() = 0;

        /**
         * @brief connect the motor controller via a port 
         * 
         * @param port port descriptor
         * @return true if successful connected, false otherwise
         */
        virtual bool connect( const char* port ) = 0;
        virtual void disconnect() = 0;
        virtual bool is_connected() = 0;

        virtual void reset_ticks() = 0;
        virtual void set_max_RPM( int maxRPM ) = 0;
        virtual int  get_max_RPM() = 0;

        /**
         * @brief Set the speed of each wheel. The Front is where the Laser scanner is mounted.
         * 
         * @param left  left wheel speed from  [-100%; +100%]
         * @param right right wheel speed from  [-100%; +100%]
         */
        virtual void set_speeds( float left, float right ) = 0;
        virtual void get_ticks( int& left, int& right ) = 0;
    };


}

#endif