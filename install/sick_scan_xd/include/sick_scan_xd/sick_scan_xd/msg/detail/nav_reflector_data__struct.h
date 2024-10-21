// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/NAVReflectorData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NAVReflectorData in the package sick_scan_xd.
/**
  * ROS message of NAV350ReflectorData, see sick_nav_scandata_parser.h and NAV-350 telegram listing for details.
 */
typedef struct sick_scan_xd__msg__NAVReflectorData
{
  /// cartesian data in lidar coordinates in mm
  uint16_t cartesian_data_valid;
  int32_t x;
  int32_t y;
  /// polar data in lidar coordinates in mm and mdeg
  uint16_t polar_data_valid;
  uint32_t dist;
  uint32_t phi;
  /// optional reflector data
  uint16_t opt_reflector_data_valid;
  uint16_t local_id;
  uint16_t global_id;
  uint8_t type;
  uint16_t sub_type;
  uint16_t quality;
  uint32_t timestamp;
  uint16_t size;
  uint16_t hit_count;
  uint16_t mean_echo;
  uint16_t start_index;
  uint16_t end_index;
  /// reflector position in ros coordinates
  /// pose_x, pose_y and pose_yaw are valid if pose_valid > 0
  int8_t pos_valid;
  /// x position in ros coordinates in m
  float pos_x;
  /// y position in ros coordinates in m
  float pos_y;
} sick_scan_xd__msg__NAVReflectorData;

// Struct for a sequence of sick_scan_xd__msg__NAVReflectorData.
typedef struct sick_scan_xd__msg__NAVReflectorData__Sequence
{
  sick_scan_xd__msg__NAVReflectorData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__NAVReflectorData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__STRUCT_H_
