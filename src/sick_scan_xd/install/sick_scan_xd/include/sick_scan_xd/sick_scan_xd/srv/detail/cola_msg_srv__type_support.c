// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sick_scan_xd:srv/ColaMsgSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sick_scan_xd/srv/detail/cola_msg_srv__rosidl_typesupport_introspection_c.h"
#include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sick_scan_xd/srv/detail/cola_msg_srv__functions.h"
#include "sick_scan_xd/srv/detail/cola_msg_srv__struct.h"


// Include directives for member types
// Member `request`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sick_scan_xd__srv__ColaMsgSrv_Request__init(message_memory);
}

void sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_fini_function(void * message_memory)
{
  sick_scan_xd__srv__ColaMsgSrv_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_member_array[1] = {
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__srv__ColaMsgSrv_Request, request),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_members = {
  "sick_scan_xd__srv",  // message namespace
  "ColaMsgSrv_Request",  // message name
  1,  // number of fields
  sizeof(sick_scan_xd__srv__ColaMsgSrv_Request),
  sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_member_array,  // message members
  sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_type_support_handle = {
  0,
  &sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv_Request)() {
  if (!sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_type_support_handle.typesupport_identifier) {
    sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sick_scan_xd__srv__ColaMsgSrv_Request__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sick_scan_xd/srv/detail/cola_msg_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sick_scan_xd/srv/detail/cola_msg_srv__functions.h"
// already included above
// #include "sick_scan_xd/srv/detail/cola_msg_srv__struct.h"


// Include directives for member types
// Member `response`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sick_scan_xd__srv__ColaMsgSrv_Response__init(message_memory);
}

void sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_fini_function(void * message_memory)
{
  sick_scan_xd__srv__ColaMsgSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_member_array[1] = {
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__srv__ColaMsgSrv_Response, response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_members = {
  "sick_scan_xd__srv",  // message namespace
  "ColaMsgSrv_Response",  // message name
  1,  // number of fields
  sizeof(sick_scan_xd__srv__ColaMsgSrv_Response),
  sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_member_array,  // message members
  sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_type_support_handle = {
  0,
  &sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv_Response)() {
  if (!sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_type_support_handle.typesupport_identifier) {
    sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sick_scan_xd__srv__ColaMsgSrv_Response__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "sick_scan_xd/srv/detail/cola_msg_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_members = {
  "sick_scan_xd__srv",  // service namespace
  "ColaMsgSrv",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_Request_message_type_support_handle,
  NULL  // response message
  // sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_Response_message_type_support_handle
};

static rosidl_service_type_support_t sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_type_support_handle = {
  0,
  &sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv)() {
  if (!sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_type_support_handle.typesupport_identifier) {
    sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, srv, ColaMsgSrv_Response)()->data;
  }

  return &sick_scan_xd__srv__detail__cola_msg_srv__rosidl_typesupport_introspection_c__ColaMsgSrv_service_type_support_handle;
}