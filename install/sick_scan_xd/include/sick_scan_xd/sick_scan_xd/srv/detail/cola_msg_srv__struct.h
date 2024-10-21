// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sick_scan_xd:srv/ColaMsgSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__STRUCT_H_
#define SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'request'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ColaMsgSrv in the package sick_scan_xd.
typedef struct sick_scan_xd__srv__ColaMsgSrv_Request
{
  /// Request (input)
  rosidl_runtime_c__String request;
} sick_scan_xd__srv__ColaMsgSrv_Request;

// Struct for a sequence of sick_scan_xd__srv__ColaMsgSrv_Request.
typedef struct sick_scan_xd__srv__ColaMsgSrv_Request__Sequence
{
  sick_scan_xd__srv__ColaMsgSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__srv__ColaMsgSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ColaMsgSrv in the package sick_scan_xd.
typedef struct sick_scan_xd__srv__ColaMsgSrv_Response
{
  /// Response (output)
  rosidl_runtime_c__String response;
} sick_scan_xd__srv__ColaMsgSrv_Response;

// Struct for a sequence of sick_scan_xd__srv__ColaMsgSrv_Response.
typedef struct sick_scan_xd__srv__ColaMsgSrv_Response__Sequence
{
  sick_scan_xd__srv__ColaMsgSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sick_scan_xd__srv__ColaMsgSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__STRUCT_H_
