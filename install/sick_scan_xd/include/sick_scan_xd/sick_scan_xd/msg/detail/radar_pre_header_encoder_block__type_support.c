// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__rosidl_typesupport_introspection_c.h"
#include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__functions.h"
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__init(message_memory);
}

void sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_fini_function(void * message_memory)
{
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_member_array[2] = {
  {
    "udiencoderpos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock, udiencoderpos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "iencoderspeed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock, iencoderspeed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_members = {
  "sick_scan_xd__msg",  // message namespace
  "RadarPreHeaderEncoderBlock",  // message name
  2,  // number of fields
  sizeof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock),
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_member_array,  // message members
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_init_function,  // function to initialize message memory (memory has to be allocated)
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_type_support_handle = {
  0,
  &sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, msg, RadarPreHeaderEncoderBlock)() {
  if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_type_support_handle.typesupport_identifier) {
    sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sick_scan_xd__msg__RadarPreHeaderEncoderBlock__rosidl_typesupport_introspection_c__RadarPreHeaderEncoderBlock_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
