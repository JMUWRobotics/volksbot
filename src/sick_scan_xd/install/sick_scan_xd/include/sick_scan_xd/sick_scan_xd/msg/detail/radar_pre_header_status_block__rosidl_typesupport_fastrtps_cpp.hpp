// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderStatusBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "sick_scan_xd/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace sick_scan_xd
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
cdr_serialize(
  const sick_scan_xd::msg::RadarPreHeaderStatusBlock & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sick_scan_xd::msg::RadarPreHeaderStatusBlock & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
get_serialized_size(
  const sick_scan_xd::msg::RadarPreHeaderStatusBlock & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
max_serialized_size_RadarPreHeaderStatusBlock(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sick_scan_xd

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sick_scan_xd, msg, RadarPreHeaderStatusBlock)();

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
