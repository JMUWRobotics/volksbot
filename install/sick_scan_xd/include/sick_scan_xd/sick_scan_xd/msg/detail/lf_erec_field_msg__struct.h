// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/LFErecFieldMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LFErecFieldMsg in the package sick_scan_xd.
/**
  * This message contains a single field of a "sSN LFErec" message of a Sick laser scanner as an ros message.
  * See https://github.com/SICKAG/libsick_ldmrs/blob/master/src/sopas/LdmrsSopasLayer.cpp lines 1414 ff.
  * Field result field_result_mrs is 0 (invalid/incorrect), 1 (free/clear) or 2 (infringed)
  * Note: field indices are sorted in reverse order, i.e. with 2 configured fields, we typically have
  * output_msg.fields[0].field_index = 1, output_msg.fields[0].field_result_mrs = 0 (invalid)
  * output_msg.fields[1].field_index = 2, output_msg.fields[1].field_result_mrs = 1 or 2 (clear=1 or infringed=2)
  * output_msg.fields[2].field_index = 3, output_msg.fields[2].field_result_mrs = 1 or 2 (clear=1 or infringed=2)
 */
typedef struct sick_scan_xd__msg__LFErecFieldMsg
{
  uint16_t version_number;
  uint8_t field_index;
  uint32_t sys_count;
  float dist_scale_factor;
  float dist_scale_offset;
  uint32_t angle_scale_factor;
  int32_t angle_scale_offset;
  /// field result is 0 (invalid/incorrect), 1 (free/clear) or 2 (infringed)
  uint8_t field_result_mrs;
  /// Time block
  /// No time data: 0, Time data: 1
  uint16_t time_state;
  /// f.e. 2021
  uint16_t year;
  /// 1 ... 12
  uint8_t month;
  /// 1 ... 31
  uint8_t day;
  /// 0 ... 23
  uint8_t hour;
  /// 0 ... 59
  uint8_t minute;
  /// 0 ... 59
  uint8_t second;
  /// 0 ... 999999
  uint32_t microsecond;
} sick_scan_xd__msg__LFErecFieldMsg;

// Struct for a sequence of sick_scan_xd__msg__LFErecFieldMsg.
typedef struct sick_scan_xd__msg__LFErecFieldMsg__Sequence
{
  sick_scan_xd__msg__LFErecFieldMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__LFErecFieldMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__STRUCT_H_
