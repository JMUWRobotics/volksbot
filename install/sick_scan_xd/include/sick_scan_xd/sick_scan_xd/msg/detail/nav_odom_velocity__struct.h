// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/NAVOdomVelocity.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NAVOdomVelocity in the package sick_scan_xd.
/**
  * ROS message for NAV350 velocity/odometry data, see sick_nav_scandata_parser.h and NAV-350 telegram listing for details ("sMN mNPOSSetSpeed").
 */
typedef struct sick_scan_xd__msg__NAVOdomVelocity
{
  /// x-component of velocity in the coordinate system defined by coordbase (i.e. in lidar coordinate for coordbase=0) in m/s, -32.0 ... +32.0 m/s
  float vel_x;
  /// y-component of velocity in the coordinate system defined by coordbase (i.e. in lidar coordinate for coordbase=0) in m/s, -32.0 ... +32.0 m/s
  float vel_y;
  /// angular velocity of the NAV350 in radians/s, -2*PI ... +2*PI rad/s
  float omega;
  /// Timestamp of the Velocity vector related to the NAV350 clock
  uint32_t timestamp;
  /// Coordinate system of the velocity vector (local or global), 0 = local coordinate system of the NAV350, 1 = absolute coordinate system
  uint8_t coordbase;
} sick_scan_xd__msg__NAVOdomVelocity;

// Struct for a sequence of sick_scan_xd__msg__NAVOdomVelocity.
typedef struct sick_scan_xd__msg__NAVOdomVelocity__Sequence
{
  sick_scan_xd__msg__NAVOdomVelocity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__NAVOdomVelocity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__STRUCT_H_
