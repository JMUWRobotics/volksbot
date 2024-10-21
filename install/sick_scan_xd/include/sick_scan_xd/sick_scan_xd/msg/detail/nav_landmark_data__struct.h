// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/NAVLandmarkData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__STRUCT_H_

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
// Member 'reflectors'
#include "sick_scan_xd/msg/detail/nav_reflector_data__struct.h"

/// Struct defined in msg/NAVLandmarkData in the package sick_scan_xd.
/**
  * ROS message of NAV350LandmarkData, see sick_nav_scandata_parser.h and NAV-350 telegram listing for details.
 */
typedef struct sick_scan_xd__msg__NAVLandmarkData
{
  std_msgs__msg__Header header;
  uint8_t landmark_filter;
  uint16_t num_reflectors;
  sick_scan_xd__msg__NAVReflectorData__Sequence reflectors;
} sick_scan_xd__msg__NAVLandmarkData;

// Struct for a sequence of sick_scan_xd__msg__NAVLandmarkData.
typedef struct sick_scan_xd__msg__NAVLandmarkData__Sequence
{
  sick_scan_xd__msg__NAVLandmarkData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__NAVLandmarkData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__STRUCT_H_
