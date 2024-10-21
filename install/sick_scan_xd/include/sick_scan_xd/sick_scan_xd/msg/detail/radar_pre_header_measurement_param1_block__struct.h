// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/RadarPreHeaderMeasurementParam1Block.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RadarPreHeaderMeasurementParam1Block in the package sick_scan_xd.
/**
  *  ROS-1:
  * uint32 uiCycleDuration # Time in microseconds to detect this items
  * uint32 uiNoiseLevel #
  *  ROS-2:
 */
typedef struct sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block
{
  /// Time in microseconds to detect this items
  uint32_t uicycleduration;
  uint32_t uinoiselevel;
} sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block;

// Struct for a sequence of sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block.
typedef struct sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block__Sequence
{
  sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__STRUCT_H_
