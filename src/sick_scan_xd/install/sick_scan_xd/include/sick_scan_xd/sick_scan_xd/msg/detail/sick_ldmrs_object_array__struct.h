// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/SickLdmrsObjectArray.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT_ARRAY__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT_ARRAY__STRUCT_H_

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
// Member 'objects'
#include "sick_scan_xd/msg/detail/sick_ldmrs_object__struct.h"

/// Struct defined in msg/SickLdmrsObjectArray in the package sick_scan_xd.
typedef struct sick_scan_xd__msg__SickLdmrsObjectArray
{
  std_msgs__msg__Header header;
  sick_scan_xd__msg__SickLdmrsObject__Sequence objects;
} sick_scan_xd__msg__SickLdmrsObjectArray;

// Struct for a sequence of sick_scan_xd__msg__SickLdmrsObjectArray.
typedef struct sick_scan_xd__msg__SickLdmrsObjectArray__Sequence
{
  sick_scan_xd__msg__SickLdmrsObjectArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__SickLdmrsObjectArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT_ARRAY__STRUCT_H_
