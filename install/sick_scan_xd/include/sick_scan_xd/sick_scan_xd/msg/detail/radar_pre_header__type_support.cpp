// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from sick_scan_xd:msg/RadarPreHeader.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "sick_scan_xd/msg/detail/radar_pre_header__struct.hpp"
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

void RadarPreHeader_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) sick_scan_xd::msg::RadarPreHeader(_init);
}

void RadarPreHeader_fini_function(void * message_memory)
{
  auto typed_message = static_cast<sick_scan_xd::msg::RadarPreHeader *>(message_memory);
  typed_message->~RadarPreHeader();
}

size_t size_function__RadarPreHeader__radarpreheaderarrayencoderblock(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sick_scan_xd::msg::RadarPreHeaderEncoderBlock> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RadarPreHeader__radarpreheaderarrayencoderblock(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sick_scan_xd::msg::RadarPreHeaderEncoderBlock> *>(untyped_member);
  return &member[index];
}

void * get_function__RadarPreHeader__radarpreheaderarrayencoderblock(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sick_scan_xd::msg::RadarPreHeaderEncoderBlock> *>(untyped_member);
  return &member[index];
}

void fetch_function__RadarPreHeader__radarpreheaderarrayencoderblock(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sick_scan_xd::msg::RadarPreHeaderEncoderBlock *>(
    get_const_function__RadarPreHeader__radarpreheaderarrayencoderblock(untyped_member, index));
  auto & value = *reinterpret_cast<sick_scan_xd::msg::RadarPreHeaderEncoderBlock *>(untyped_value);
  value = item;
}

void assign_function__RadarPreHeader__radarpreheaderarrayencoderblock(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sick_scan_xd::msg::RadarPreHeaderEncoderBlock *>(
    get_function__RadarPreHeader__radarpreheaderarrayencoderblock(untyped_member, index));
  const auto & value = *reinterpret_cast<const sick_scan_xd::msg::RadarPreHeaderEncoderBlock *>(untyped_value);
  item = value;
}

void resize_function__RadarPreHeader__radarpreheaderarrayencoderblock(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sick_scan_xd::msg::RadarPreHeaderEncoderBlock> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RadarPreHeader_message_member_array[5] = {
  {
    "uiversionno",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeader, uiversionno),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "radarpreheaderdeviceblock",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sick_scan_xd::msg::RadarPreHeaderDeviceBlock>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeader, radarpreheaderdeviceblock),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "radarpreheaderstatusblock",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sick_scan_xd::msg::RadarPreHeaderStatusBlock>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeader, radarpreheaderstatusblock),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "radarpreheadermeasurementparam1block",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeader, radarpreheadermeasurementparam1block),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "radarpreheaderarrayencoderblock",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::RadarPreHeader, radarpreheaderarrayencoderblock),  // bytes offset in struct
    nullptr,  // default value
    size_function__RadarPreHeader__radarpreheaderarrayencoderblock,  // size() function pointer
    get_const_function__RadarPreHeader__radarpreheaderarrayencoderblock,  // get_const(index) function pointer
    get_function__RadarPreHeader__radarpreheaderarrayencoderblock,  // get(index) function pointer
    fetch_function__RadarPreHeader__radarpreheaderarrayencoderblock,  // fetch(index, &value) function pointer
    assign_function__RadarPreHeader__radarpreheaderarrayencoderblock,  // assign(index, value) function pointer
    resize_function__RadarPreHeader__radarpreheaderarrayencoderblock  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RadarPreHeader_message_members = {
  "sick_scan_xd::msg",  // message namespace
  "RadarPreHeader",  // message name
  5,  // number of fields
  sizeof(sick_scan_xd::msg::RadarPreHeader),
  RadarPreHeader_message_member_array,  // message members
  RadarPreHeader_init_function,  // function to initialize message memory (memory has to be allocated)
  RadarPreHeader_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RadarPreHeader_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RadarPreHeader_message_members,
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
get_message_type_support_handle<sick_scan_xd::msg::RadarPreHeader>()
{
  return &::sick_scan_xd::msg::rosidl_typesupport_introspection_cpp::RadarPreHeader_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sick_scan_xd, msg, RadarPreHeader)() {
  return &::sick_scan_xd::msg::rosidl_typesupport_introspection_cpp::RadarPreHeader_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
