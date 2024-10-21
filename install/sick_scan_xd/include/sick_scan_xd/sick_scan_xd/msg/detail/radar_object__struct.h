// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/RadarObject.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tracking_time'
// Member 'last_seen'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_with_covariance__struct.h"
// Member 'bounding_box_center'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'bounding_box_size'
// Member 'object_box_size'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'object_box_center'
#include "geometry_msgs/msg/detail/pose_with_covariance__struct.h"
// Member 'contour_points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/RadarObject in the package sick_scan_xd.
typedef struct sick_scan_xd__msg__RadarObject
{
  int32_t id;
  ///  ROS-1:
  /// time tracking_time                          # since when the object is tracked
  /// time last_seen
  ///  ROS-2:
  ///  since when the object is tracked
  builtin_interfaces__msg__Time tracking_time;
  builtin_interfaces__msg__Time last_seen;
  geometry_msgs__msg__TwistWithCovariance velocity;
  geometry_msgs__msg__Pose bounding_box_center;
  geometry_msgs__msg__Vector3 bounding_box_size;
  geometry_msgs__msg__PoseWithCovariance object_box_center;
  geometry_msgs__msg__Vector3 object_box_size;
  geometry_msgs__msg__Point__Sequence contour_points;
} sick_scan_xd__msg__RadarObject;

// Struct for a sequence of sick_scan_xd__msg__RadarObject.
typedef struct sick_scan_xd__msg__RadarObject__Sequence
{
  sick_scan_xd__msg__RadarObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__RadarObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__STRUCT_H_
