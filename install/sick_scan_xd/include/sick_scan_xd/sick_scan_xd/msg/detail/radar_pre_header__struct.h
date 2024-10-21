// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:msg/RadarPreHeader.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__STRUCT_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'radarpreheaderdeviceblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__struct.h"
// Member 'radarpreheaderstatusblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__struct.h"
// Member 'radarpreheadermeasurementparam1block'
#include "sick_scan_xd/msg/detail/radar_pre_header_measurement_param1_block__struct.h"
// Member 'radarpreheaderarrayencoderblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__struct.h"

/// Struct defined in msg/RadarPreHeader in the package sick_scan_xd.
/**
  * Version information for this whole structure (MeasurementData)
 */
typedef struct sick_scan_xd__msg__RadarPreHeader
{
  uint16_t uiversionno;
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock radarpreheaderdeviceblock;
  sick_scan_xd__msg__RadarPreHeaderStatusBlock radarpreheaderstatusblock;
  sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block radarpreheadermeasurementparam1block;
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence radarpreheaderarrayencoderblock;
} sick_scan_xd__msg__RadarPreHeader;

// Struct for a sequence of sick_scan_xd__msg__RadarPreHeader.
typedef struct sick_scan_xd__msg__RadarPreHeader__Sequence
{
  sick_scan_xd__msg__RadarPreHeader * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__msg__RadarPreHeader__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__STRUCT_H_
