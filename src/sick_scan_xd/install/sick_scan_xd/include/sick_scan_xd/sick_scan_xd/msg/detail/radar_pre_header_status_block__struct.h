// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/RadarPreHeaderStatusBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RadarPreHeaderStatusBlock in the package sick_scan_xd.
/**
  *  ROS-1:
  * uint32 uiTelegramCount # telegram number
  * uint32 uiCycleCount # "scan number"
  * uint32 udiSystemCountScan # system time since power on of scan gen. [us]
  * uint32 udiSystemCountTransmit # system time since power on of scan transmission [us]
  * uint16 uiInputs # state of digital inputs
  * uint16 uiOutputs # state of digital outputs
 */
typedef struct sick_scan_xd__msg__RadarPreHeaderStatusBlock
{
  /// ROS-2:
  /// telegram number
  uint32_t uitelegramcount;
  /// "scan number"
  uint32_t uicyclecount;
  /// system time since power on of scan gen.
  uint32_t udisystemcountscan;
  /// system time since power on of scan transmission
  uint32_t udisystemcounttransmit;
  /// state of digital inputs
  uint16_t uiinputs;
  /// state of digital outputs
  uint16_t uioutputs;
} sick_scan_xd__msg__RadarPreHeaderStatusBlock;

// Struct for a sequence of sick_scan_xd__msg__RadarPreHeaderStatusBlock.
typedef struct sick_scan_xd__msg__RadarPreHeaderStatusBlock__Sequence
{
  sick_scan_xd__msg__RadarPreHeaderStatusBlock * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__RadarPreHeaderStatusBlock__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__STRUCT_H_
