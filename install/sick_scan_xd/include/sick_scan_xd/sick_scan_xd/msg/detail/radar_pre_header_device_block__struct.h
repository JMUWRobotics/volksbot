// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/RadarPreHeaderDeviceBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RadarPreHeaderDeviceBlock in the package sick_scan_xd.
typedef struct sick_scan_xd__msg__RadarPreHeaderDeviceBlock
{
  ///  ROS-1:
  /// uint32 uiIdent             # Logical number of the device"
  /// uint32 udiSerialNo         # Serial number of the device
  /// bool bDeviceError          # State of the device
  /// bool bContaminationWarning # Contamination Warning
  /// bool bContaminationError   # Contamination Error
  ///  ROS-2:
  ///  Logical number of the device"
  uint32_t uiident;
  /// Serial number of the device
  uint32_t udiserialno;
  /// State of the device
  bool bdeviceerror;
  /// Contamination Warning
  bool bcontaminationwarning;
  /// Contamination Error
  bool bcontaminationerror;
} sick_scan_xd__msg__RadarPreHeaderDeviceBlock;

// Struct for a sequence of sick_scan_xd__msg__RadarPreHeaderDeviceBlock.
typedef struct sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence
{
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__STRUCT_H_
