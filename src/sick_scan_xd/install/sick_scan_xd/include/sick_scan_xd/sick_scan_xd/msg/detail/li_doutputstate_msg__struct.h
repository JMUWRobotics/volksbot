// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/LIDoutputstateMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__STRUCT_H_

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
// Member 'output_state'
// Member 'output_count'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/LIDoutputstateMsg in the package sick_scan_xd.
/**
  * This message contains the "sSN LIDoutputstate" message of a Sick laser scanner as an ros message.
 */
typedef struct sick_scan_xd__msg__LIDoutputstateMsg
{
  ///  ROS-1:
  /// Header header
  ///  ROS-2:
  std_msgs__msg__Header header;
  /// Status code
  /// Status code version number
  uint16_t version_number;
  /// Status code system counter (time in microsec since power up, max. 71 min then starting from 0 again)
  uint32_t system_counter;
  /// Array of output states (state and count)
  /// output states, each state with value 0 (not active), 1 (active) or 2 (not used)
  rosidl_runtime_c__uint8__Sequence output_state;
  /// output counter
  rosidl_runtime_c__uint32__Sequence output_count;
  /// Time block (sensortime from the last change of min. one of the outputs)
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
} sick_scan_xd__msg__LIDoutputstateMsg;

// Struct for a sequence of sick_scan_xd__msg__LIDoutputstateMsg.
typedef struct sick_scan_xd__msg__LIDoutputstateMsg__Sequence
{
  sick_scan_xd__msg__LIDoutputstateMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__LIDoutputstateMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__STRUCT_H_
