// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from sick_scan_xd:msg/NAVLandmarkData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "sick_scan_xd/msg/detail/nav_landmark_data__struct.hpp"
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

void NAVLandmarkData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) sick_scan_xd::msg::NAVLandmarkData(_init);
}

void NAVLandmarkData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<sick_scan_xd::msg::NAVLandmarkData *>(message_memory);
  typed_message->~NAVLandmarkData();
}

size_t size_function__NAVLandmarkData__reflectors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sick_scan_xd::msg::NAVReflectorData> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NAVLandmarkData__reflectors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sick_scan_xd::msg::NAVReflectorData> *>(untyped_member);
  return &member[index];
}

void * get_function__NAVLandmarkData__reflectors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sick_scan_xd::msg::NAVReflectorData> *>(untyped_member);
  return &member[index];
}

void fetch_function__NAVLandmarkData__reflectors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sick_scan_xd::msg::NAVReflectorData *>(
    get_const_function__NAVLandmarkData__reflectors(untyped_member, index));
  auto & value = *reinterpret_cast<sick_scan_xd::msg::NAVReflectorData *>(untyped_value);
  value = item;
}

void assign_function__NAVLandmarkData__reflectors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sick_scan_xd::msg::NAVReflectorData *>(
    get_function__NAVLandmarkData__reflectors(untyped_member, index));
  const auto & value = *reinterpret_cast<const sick_scan_xd::msg::NAVReflectorData *>(untyped_value);
  item = value;
}

void resize_function__NAVLandmarkData__reflectors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sick_scan_xd::msg::NAVReflectorData> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NAVLandmarkData_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::NAVLandmarkData, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "landmark_filter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::NAVLandmarkData, landmark_filter),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_reflectors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::NAVLandmarkData, num_reflectors),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "reflectors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sick_scan_xd::msg::NAVReflectorData>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd::msg::NAVLandmarkData, reflectors),  // bytes offset in struct
    nullptr,  // default value
    size_function__NAVLandmarkData__reflectors,  // size() function pointer
    get_const_function__NAVLandmarkData__reflectors,  // get_const(index) function pointer
    get_function__NAVLandmarkData__reflectors,  // get(index) function pointer
    fetch_function__NAVLandmarkData__reflectors,  // fetch(index, &value) function pointer
    assign_function__NAVLandmarkData__reflectors,  // assign(index, value) function pointer
    resize_function__NAVLandmarkData__reflectors  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NAVLandmarkData_message_members = {
  "sick_scan_xd::msg",  // message namespace
  "NAVLandmarkData",  // message name
  4,  // number of fields
  sizeof(sick_scan_xd::msg::NAVLandmarkData),
  NAVLandmarkData_message_member_array,  // message members
  NAVLandmarkData_init_function,  // function to initialize message memory (memory has to be allocated)
  NAVLandmarkData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NAVLandmarkData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NAVLandmarkData_message_members,
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
get_message_type_support_handle<sick_scan_xd::msg::NAVLandmarkData>()
{
  return &::sick_scan_xd::msg::rosidl_typesupport_introspection_cpp::NAVLandmarkData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sick_scan_xd, msg, NAVLandmarkData)() {
  return &::sick_scan_xd::msg::rosidl_typesupport_introspection_cpp::NAVLandmarkData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
