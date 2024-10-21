// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/Encoder.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__ENCODER__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__ENCODER__STRUCT_H_

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

/// Struct defined in msg/Encoder in the package sick_scan_xd.
/**
  * This message contains the counter reading of the encoder at the datagram time (timestamp in header).
 */
typedef struct sick_scan_xd__msg__Encoder
{
  ///  ROS-1:
  /// Header header           # same information as in laserscan and Pointcloud2 message
  ///  ROS-2:
  ///  same information as in laserscan and Pointcloud2 message
  std_msgs__msg__Header header;
  /// number of ticks
  int32_t enc_position;
  /// number of ticks per millimeter
  int16_t enc_speed;
} sick_scan_xd__msg__Encoder;

// Struct for a sequence of sick_scan_xd__msg__Encoder.
typedef struct sick_scan_xd__msg__Encoder__Sequence
{
  sick_scan_xd__msg__Encoder * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__Encoder__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__ENCODER__STRUCT_H_
