// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sick_scan_xd:msg/LIDoutputstateMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sick_scan_xd/msg/detail/li_doutputstate_msg__rosidl_typesupport_introspection_c.h"
#include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sick_scan_xd/msg/detail/li_doutputstate_msg__functions.h"
#include "sick_scan_xd/msg/detail/li_doutputstate_msg__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `output_state`
// Member `output_count`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sick_scan_xd__msg__LIDoutputstateMsg__init(message_memory);
}

void sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_fini_function(void * message_memory)
{
  sick_scan_xd__msg__LIDoutputstateMsg__fini(message_memory);
}

size_t sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__size_function__LIDoutputstateMsg__output_state(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_const_function__LIDoutputstateMsg__output_state(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_function__LIDoutputstateMsg__output_state(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__fetch_function__LIDoutputstateMsg__output_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_const_function__LIDoutputstateMsg__output_state(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__assign_function__LIDoutputstateMsg__output_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_function__LIDoutputstateMsg__output_state(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__resize_function__LIDoutputstateMsg__output_state(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__size_function__LIDoutputstateMsg__output_count(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_const_function__LIDoutputstateMsg__output_count(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_function__LIDoutputstateMsg__output_count(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__fetch_function__LIDoutputstateMsg__output_count(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_const_function__LIDoutputstateMsg__output_count(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__assign_function__LIDoutputstateMsg__output_count(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_function__LIDoutputstateMsg__output_count(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__resize_function__LIDoutputstateMsg__output_count(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_member_array[13] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "version_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, version_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "system_counter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, system_counter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "output_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, output_state),  // bytes offset in struct
    NULL,  // default value
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__size_function__LIDoutputstateMsg__output_state,  // size() function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_const_function__LIDoutputstateMsg__output_state,  // get_const(index) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_function__LIDoutputstateMsg__output_state,  // get(index) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__fetch_function__LIDoutputstateMsg__output_state,  // fetch(index, &value) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__assign_function__LIDoutputstateMsg__output_state,  // assign(index, value) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__resize_function__LIDoutputstateMsg__output_state  // resize(index) function pointer
  },
  {
    "output_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, output_count),  // bytes offset in struct
    NULL,  // default value
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__size_function__LIDoutputstateMsg__output_count,  // size() function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_const_function__LIDoutputstateMsg__output_count,  // get_const(index) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__get_function__LIDoutputstateMsg__output_count,  // get(index) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__fetch_function__LIDoutputstateMsg__output_count,  // fetch(index, &value) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__assign_function__LIDoutputstateMsg__output_count,  // assign(index, value) function pointer
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__resize_function__LIDoutputstateMsg__output_count  // resize(index) function pointer
  },
  {
    "time_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, time_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "year",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, year),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "month",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, month),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "day",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, day),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hour",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, hour),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "minute",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, minute),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "second",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, second),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "microsecond",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__LIDoutputstateMsg, microsecond),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_members = {
  "sick_scan_xd__msg",  // message namespace
  "LIDoutputstateMsg",  // message name
  13,  // number of fields
  sizeof(sick_scan_xd__msg__LIDoutputstateMsg),
  sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_member_array,  // message members
  sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_type_support_handle = {
  0,
  &sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, msg, LIDoutputstateMsg)() {
  sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_type_support_handle.typesupport_identifier) {
    sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sick_scan_xd__msg__LIDoutputstateMsg__rosidl_typesupport_introspection_c__LIDoutputstateMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
