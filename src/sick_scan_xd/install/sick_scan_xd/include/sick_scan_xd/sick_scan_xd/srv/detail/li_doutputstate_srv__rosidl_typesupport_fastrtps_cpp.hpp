// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from sick_scan_xd:srv/LIDoutputstateSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__LI_DOUTPUTSTATE_SRV__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__LI_DOUTPUTSTATE_SRV__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "sick_scan_xd/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "sick_scan_xd/srv/detail/li_doutputstate_srv__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
cdr_serialize(
  const sick_scan_xd::srv::LIDoutputstateSrv_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sick_scan_xd::srv::LIDoutputstateSrv_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
get_serialized_size(
  const sick_scan_xd::srv::LIDoutputstateSrv_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
max_serialized_size_LIDoutputstateSrv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace sick_scan_xd

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sick_scan_xd, srv, LIDoutputstateSrv_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "sick_scan_xd/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "sick_scan_xd/srv/detail/li_doutputstate_srv__struct.hpp"

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

// already included above
// #include "fastcdr/Cdr.h"

namespace sick_scan_xd
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
cdr_serialize(
  const sick_scan_xd::srv::LIDoutputstateSrv_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sick_scan_xd::srv::LIDoutputstateSrv_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
get_serialized_size(
  const sick_scan_xd::srv::LIDoutputstateSrv_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
max_serialized_size_LIDoutputstateSrv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace sick_scan_xd

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sick_scan_xd, srv, LIDoutputstateSrv_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "sick_scan_xd/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sick_scan_xd
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sick_scan_xd, srv, LIDoutputstateSrv)();

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__SRV__DETAIL__LI_DOUTPUTSTATE_SRV__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
