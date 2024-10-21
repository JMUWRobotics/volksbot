// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/Encoder.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__ENCODER__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__ENCODER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/encoder__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const Encoder & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: enc_position
  {
    out << "enc_position: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_position, out);
    out << ", ";
  }

  // member: enc_speed
  {
    out << "enc_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Encoder & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: enc_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enc_position: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_position, out);
    out << "\n";
  }

  // member: enc_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enc_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Encoder & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::Encoder & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::Encoder & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::Encoder>()
{
  return "sick_scan_xd::msg::Encoder";
}

template<>
inline const char * name<sick_scan_xd::msg::Encoder>()
{
  return "sick_scan_xd/msg/Encoder";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::Encoder>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::Encoder>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<sick_scan_xd::msg::Encoder>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__ENCODER__TRAITS_HPP_
