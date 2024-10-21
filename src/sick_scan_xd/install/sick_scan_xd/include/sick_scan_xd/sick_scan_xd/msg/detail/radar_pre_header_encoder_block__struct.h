// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RadarPreHeaderEncoderBlock in the package sick_scan_xd.
/**
  *  Array with connected encoder sensors
  *  ROS-1:
  * uint32 udiEncoderPos  # encoder position [inc]
  * int16 iEncoderSpeed   # encoder speed [inc/mm]
  *  ROS-2:
 */
typedef struct sick_scan_xd__msg__RadarPreHeaderEncoderBlock
{
  /// encoder position
  uint32_t udiencoderpos;
  /// encoder speed
  int16_t iencoderspeed;
} sick_scan_xd__msg__RadarPreHeaderEncoderBlock;

// Struct for a sequence of sick_scan_xd__msg__RadarPreHeaderEncoderBlock.
typedef struct sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence
{
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__STRUCT_H_
