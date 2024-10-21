// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:srv/SCdevicestateSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__S_CDEVICESTATE_SRV__STRUCT_H_
#define SICK_SCAN_XD__SRV__DETAIL__S_CDEVICESTATE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SCdevicestateSrv in the package sick_scan_xd.
typedef struct sick_scan_xd__srv__SCdevicestateSrv_Request
{
  uint8_t structure_needs_at_least_one_member;
} sick_scan_xd__srv__SCdevicestateSrv_Request;

// Struct for a sequence of sick_scan_xd__srv__SCdevicestateSrv_Request.
typedef struct sick_scan_xd__srv__SCdevicestateSrv_Request__Sequence
{
  sick_scan_xd__srv__SCdevicestateSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__srv__SCdevicestateSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SCdevicestateSrv in the package sick_scan_xd.
typedef struct sick_scan_xd__srv__SCdevicestateSrv_Response
{
  /// Response (output)
  ///
  /// device state: busy:0, ready:1, error:2
  int32_t state;
  /// true: success response received from lidar, false: service failed (timeout or error status from controller)
  bool success;
} sick_scan_xd__srv__SCdevicestateSrv_Response;

// Struct for a sequence of sick_scan_xd__srv__SCdevicestateSrv_Response.
typedef struct sick_scan_xd__srv__SCdevicestateSrv_Response__Sequence
{
  sick_scan_xd__srv__SCdevicestateSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__srv__SCdevicestateSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__SRV__DETAIL__S_CDEVICESTATE_SRV__STRUCT_H_
