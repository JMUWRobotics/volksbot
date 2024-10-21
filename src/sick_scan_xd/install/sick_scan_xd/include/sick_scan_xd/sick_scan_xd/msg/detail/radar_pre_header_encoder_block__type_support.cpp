// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace sick_scan_xd
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RadarPreHeaderEncoderBlock_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) sick_scan_xd::msg::RadarPreHeaderEncoderBlock(_init);
}

void RadarPreHeaderEncoderBlock_fini_function(void * message_memory)
{
  auto typed_message = static_cast<sick_scan_xd::msg::RadarPreHeaderEncoderBlock *>(message_memory);
  typed_message->~RadarPreHeaderEncoderBlock();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RadarPreHeaderEncoderBlock_message_member_array[2] = {
  {
    "udiencoderpos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeaderEncoderBlock, udiencoderpos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iencoderspeed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeaderEncoderBlock, iencoderspeed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RadarPreHeaderEncoderBlock_message_members = {
  "sick_scan_xd::msg",  // message namespace
  "RadarPreHeaderEncoderBlock",  // message name
  2,  // number of fields
  sizeof(sick_scan_xd::msg::RadarPreHeaderEncoderBlock),
  RadarPreHeaderEncoderBlock_message_member_array,  // message members
  RadarPreHeaderEncoderBlock_init_function,  // function to initialize message memory (memory has to be allocated)
  RadarPreHeaderEncoderBlock_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RadarPreHeaderEncoderBlock_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RadarPreHeaderEncoderBlock_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace sick_scan_xd


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>()
{
  return &::sick_scan_xd::msg::rosidl_typesupport_introspection_cpp::RadarPreHeaderEncoderBlock_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sick_scan_xd, msg, RadarPreHeaderEncoderBlock)() {
  return &::sick_scan_xd::msg::rosidl_typesupport_introspection_cpp::RadarPreHeaderEncoderBlock_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
