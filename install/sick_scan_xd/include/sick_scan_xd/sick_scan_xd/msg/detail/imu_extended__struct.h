// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/ImuExtended.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__struct.h"

/// Struct defined in msg/ImuExtended in the package sick_scan_xd.
/**
  * This message contains the IMU data of a Sick laser scanner as an IMU message.
  * The ticks correspond to the internal time stamps of the laser scanner and increase linearly with time, the tickcounter overflows.
  * The quaternion_accuracy has the unit rad.
  * The accuracy measures for Lienar acceleration and angular velocity are abitre values, where higher values are better.
 */
typedef struct sick_scan_xd__msg__ImuExtended
{
  ///  ROS-1:
  /// Header header
  ///  ROS-2:
  std_msgs__msg__Header header;
  /// sensor_msgs/Imu Imu # ROS1
  ///  ROS2
  sensor_msgs__msg__Imu imu;
  /// IMU Message
  uint32_t ticks;
  /// timestamp Ticks from laser scanner
  float quaternion_accuracy;
  /// quaternion accuracy in rad
  uint8_t angular_velocity_reliability;
  /// angular velocity reliability 0 low 255 high, value should be over 3
  uint8_t linear_acceleration_reliability;
} sick_scan_xd__msg__ImuExtended;

// Struct for a sequence of sick_scan_xd__msg__ImuExtended.
typedef struct sick_scan_xd__msg__ImuExtended__Sequence
{
  sick_scan_xd__msg__ImuExtended * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__ImuExtended__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__STRUCT_H_
