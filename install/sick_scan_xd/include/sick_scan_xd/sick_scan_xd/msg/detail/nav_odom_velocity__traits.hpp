// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/NAVOdomVelocity.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/nav_odom_velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const NAVOdomVelocity & msg,
  std::ostream & out)
{
  out << "{";
  // member: vel_x
  {
    out << "vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_x, out);
    out << ", ";
  }

  // member: vel_y
  {
    out << "vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_y, out);
    out << ", ";
  }

  // member: omega
  {
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: coordbase
  {
    out << "coordbase: ";
    rosidl_generator_traits::value_to_yaml(msg.coordbase, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NAVOdomVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vel_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_x, out);
    out << "\n";
  }

  // member: vel_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_y, out);
    out << "\n";
  }

  // member: omega
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: coordbase
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coordbase: ";
    rosidl_generator_traits::value_to_yaml(msg.coordbase, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NAVOdomVelocity & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace sick_scan_xd

namespace rosidl_generator_traits
{

[[deprecated("use sick_scan_xd::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sick_scan_xd::msg::NAVOdomVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::NAVOdomVelocity & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::NAVOdomVelocity>()
{
  return "sick_scan_xd::msg::NAVOdomVelocity";
}

template<>
inline const char * name<sick_scan_xd::msg::NAVOdomVelocity>()
{
  return "sick_scan_xd/msg/NAVOdomVelocity";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::NAVOdomVelocity>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::NAVOdomVelocity>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::NAVOdomVelocity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__TRAITS_HPP_
