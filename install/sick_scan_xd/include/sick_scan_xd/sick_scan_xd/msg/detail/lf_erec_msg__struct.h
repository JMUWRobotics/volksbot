// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/LFErecMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__STRUCT_H_

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
// Member 'fields'
#include "sick_scan_xd/msg/detail/lf_erec_field_msg__struct.h"

/// Struct defined in msg/LFErecMsg in the package sick_scan_xd.
/**
  * This message contains a single field of a "sSN LFErec" message of a Sick laser scanner as an ros message.
  * See https://github.com/SICKAG/libsick_ldmrs/blob/master/src/sopas/LdmrsSopasLayer.cpp lines 1414 ff.
  * Field result field_result_mrs is 0 (invalid/incorrect), 1 (free/clear) or 2 (infringed)
  * Note: field indices are sorted in reverse order, i.e. with 2 configured fields, we typically have
  * output_msg.fields[0].field_index = 1, output_msg.fields[0].field_result_mrs = 0 (invalid)
  * output_msg.fields[1].field_index = 2, output_msg.fields[1].field_result_mrs = 1 or 2 (clear=1 or infringed=2)
  * output_msg.fields[2].field_index = 3, output_msg.fields[2].field_result_mrs = 1 or 2 (clear=1 or infringed=2)
 */
typedef struct sick_scan_xd__msg__LFErecMsg
{
  std_msgs__msg__Header header;
  /// number of fields
  uint16_t fields_number;
  /// 3 fields for TiM871S
  sick_scan_xd__msg__LFErecFieldMsg__Sequence fields;
} sick_scan_xd__msg__LFErecMsg;

// Struct for a sequence of sick_scan_xd__msg__LFErecMsg.
typedef struct sick_scan_xd__msg__LFErecMsg__Sequence
{
  sick_scan_xd__msg__LFErecMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__LFErecMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__STRUCT_H_
