// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/LFErecFieldMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/lf_erec_field_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const LFErecFieldMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: version_number
  {
    out << "version_number: ";
    rosidl_generator_traits::value_to_yaml(msg.version_number, out);
    out << ", ";
  }

  // member: field_index
  {
    out << "field_index: ";
    rosidl_generator_traits::value_to_yaml(msg.field_index, out);
    out << ", ";
  }

  // member: sys_count
  {
    out << "sys_count: ";
    rosidl_generator_traits::value_to_yaml(msg.sys_count, out);
    out << ", ";
  }

  // member: dist_scale_factor
  {
    out << "dist_scale_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_scale_factor, out);
    out << ", ";
  }

  // member: dist_scale_offset
  {
    out << "dist_scale_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_scale_offset, out);
    out << ", ";
  }

  // member: angle_scale_factor
  {
    out << "angle_scale_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_scale_factor, out);
    out << ", ";
  }

  // member: angle_scale_offset
  {
    out << "angle_scale_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_scale_offset, out);
    out << ", ";
  }

  // member: field_result_mrs
  {
    out << "field_result_mrs: ";
    rosidl_generator_traits::value_to_yaml(msg.field_result_mrs, out);
    out << ", ";
  }

  // member: time_state
  {
    out << "time_state: ";
    rosidl_generator_traits::value_to_yaml(msg.time_state, out);
    out << ", ";
  }

  // member: year
  {
    out << "year: ";
    rosidl_generator_traits::value_to_yaml(msg.year, out);
    out << ", ";
  }

  // member: month
  {
    out << "month: ";
    rosidl_generator_traits::value_to_yaml(msg.month, out);
    out << ", ";
  }

  // member: day
  {
    out << "day: ";
    rosidl_generator_traits::value_to_yaml(msg.day, out);
    out << ", ";
  }

  // member: hour
  {
    out << "hour: ";
    rosidl_generator_traits::value_to_yaml(msg.hour, out);
    out << ", ";
  }

  // member: minute
  {
    out << "minute: ";
    rosidl_generator_traits::value_to_yaml(msg.minute, out);
    out << ", ";
  }

  // member: second
  {
    out << "second: ";
    rosidl_generator_traits::value_to_yaml(msg.second, out);
    out << ", ";
  }

  // member: microsecond
  {
    out << "microsecond: ";
    rosidl_generator_traits::value_to_yaml(msg.microsecond, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LFErecFieldMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: version_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version_number: ";
    rosidl_generator_traits::value_to_yaml(msg.version_number, out);
    out << "\n";
  }

  // member: field_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "field_index: ";
    rosidl_generator_traits::value_to_yaml(msg.field_index, out);
    out << "\n";
  }

  // member: sys_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sys_count: ";
    rosidl_generator_traits::value_to_yaml(msg.sys_count, out);
    out << "\n";
  }

  // member: dist_scale_factor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_scale_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_scale_factor, out);
    out << "\n";
  }

  // member: dist_scale_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_scale_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_scale_offset, out);
    out << "\n";
  }

  // member: angle_scale_factor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_scale_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_scale_factor, out);
    out << "\n";
  }

  // member: angle_scale_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_scale_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_scale_offset, out);
    out << "\n";
  }

  // member: field_result_mrs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "field_result_mrs: ";
    rosidl_generator_traits::value_to_yaml(msg.field_result_mrs, out);
    out << "\n";
  }

  // member: time_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_state: ";
    rosidl_generator_traits::value_to_yaml(msg.time_state, out);
    out << "\n";
  }

  // member: year
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "year: ";
    rosidl_generator_traits::value_to_yaml(msg.year, out);
    out << "\n";
  }

  // member: month
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "month: ";
    rosidl_generator_traits::value_to_yaml(msg.month, out);
    out << "\n";
  }

  // member: day
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "day: ";
    rosidl_generator_traits::value_to_yaml(msg.day, out);
    out << "\n";
  }

  // member: hour
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hour: ";
    rosidl_generator_traits::value_to_yaml(msg.hour, out);
    out << "\n";
  }

  // member: minute
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "minute: ";
    rosidl_generator_traits::value_to_yaml(msg.minute, out);
    out << "\n";
  }

  // member: second
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "second: ";
    rosidl_generator_traits::value_to_yaml(msg.second, out);
    out << "\n";
  }

  // member: microsecond
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "microsecond: ";
    rosidl_generator_traits::value_to_yaml(msg.microsecond, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LFErecFieldMsg & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::LFErecFieldMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::LFErecFieldMsg & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::LFErecFieldMsg>()
{
  return "sick_scan_xd::msg::LFErecFieldMsg";
}

template<>
inline const char * name<sick_scan_xd::msg::LFErecFieldMsg>()
{
  return "sick_scan_xd/msg/LFErecFieldMsg";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::LFErecFieldMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::LFErecFieldMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::LFErecFieldMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__TRAITS_HPP_
