// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/NAVPoseData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__STRUCT_H_

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

/// Struct defined in msg/NAVPoseData in the package sick_scan_xd.
/**
  * ROS message of NAV350PoseData, see sick_nav_scandata_parser.h and NAV-350 telegram listing for details.
 */
typedef struct sick_scan_xd__msg__NAVPoseData
{
  std_msgs__msg__Header header;
  /// pose in lidar coordinates in mm and mdeg
  int32_t x;
  int32_t y;
  uint32_t phi;
  /// optional pose data
  uint16_t opt_pose_data_valid;
  uint8_t output_mode;
  uint32_t timestamp;
  int32_t mean_dev;
  uint8_t nav_mode;
  uint32_t info_state;
  uint8_t quant_used_reflectors;
  /// pose in ros units
  /// pose_x, pose_y and pose_yaw are valid if pose_valid > 0
  int8_t pose_valid;
  /// x position in ros units in m
  float pose_x;
  /// y position in ros units in m
  float pose_y;
  /// yaw angle in radians
  float pose_yaw;
} sick_scan_xd__msg__NAVPoseData;

// Struct for a sequence of sick_scan_xd__msg__NAVPoseData.
typedef struct sick_scan_xd__msg__NAVPoseData__Sequence
{
  sick_scan_xd__msg__NAVPoseData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__NAVPoseData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__STRUCT_H_
