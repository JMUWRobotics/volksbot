// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:srv/SCsoftresetSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__S_CSOFTRESET_SRV__TRAITS_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__S_CSOFTRESET_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/srv/detail/s_csoftreset_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace srv
{

inline void to_flow_style_yaml(
  const SCsoftresetSrv_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SCsoftresetSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SCsoftresetSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sick_scan_xd

namespace rosidl_generator_traits
{

[[deprecated("use sick_scan_xd::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sick_scan_xd::srv::SCsoftresetSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::srv::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::srv::SCsoftresetSrv_Request & msg)
{
  return sick_scan_xd::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::srv::SCsoftresetSrv_Request>()
{
  return "sick_scan_xd::srv::SCsoftresetSrv_Request";
}

template<>
inline const char * name<sick_scan_xd::srv::SCsoftresetSrv_Request>()
{
  return "sick_scan_xd/srv/SCsoftresetSrv_Request";
}

template<>
struct has_fixed_size<sick_scan_xd::srv::SCsoftresetSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::srv::SCsoftresetSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::srv::SCsoftresetSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace sick_scan_xd
{

namespace srv
{

inline void to_flow_style_yaml(
  const SCsoftresetSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SCsoftresetSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SCsoftresetSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sick_scan_xd

namespace rosidl_generator_traits
{

[[deprecated("use sick_scan_xd::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sick_scan_xd::srv::SCsoftresetSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::srv::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::srv::SCsoftresetSrv_Response & msg)
{
  return sick_scan_xd::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::srv::SCsoftresetSrv_Response>()
{
  return "sick_scan_xd::srv::SCsoftresetSrv_Response";
}

template<>
inline const char * name<sick_scan_xd::srv::SCsoftresetSrv_Response>()
{
  return "sick_scan_xd/srv/SCsoftresetSrv_Response";
}

template<>
struct has_fixed_size<sick_scan_xd::srv::SCsoftresetSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::srv::SCsoftresetSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::srv::SCsoftresetSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sick_scan_xd::srv::SCsoftresetSrv>()
{
  return "sick_scan_xd::srv::SCsoftresetSrv";
}

template<>
inline const char * name<sick_scan_xd::srv::SCsoftresetSrv>()
{
  return "sick_scan_xd/srv/SCsoftresetSrv";
}

template<>
struct has_fixed_size<sick_scan_xd::srv::SCsoftresetSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<sick_scan_xd::srv::SCsoftresetSrv_Request>::value &&
    has_fixed_size<sick_scan_xd::srv::SCsoftresetSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<sick_scan_xd::srv::SCsoftresetSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<sick_scan_xd::srv::SCsoftresetSrv_Request>::value &&
    has_bounded_size<sick_scan_xd::srv::SCsoftresetSrv_Response>::value
  >
{
};

template<>
struct is_service<sick_scan_xd::srv::SCsoftresetSrv>
  : std::true_type
{
};

template<>
struct is_service_request<sick_scan_xd::srv::SCsoftresetSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sick_scan_xd::srv::SCsoftresetSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__SRV__DETAIL__S_CSOFTRESET_SRV__TRAITS_HPP_
