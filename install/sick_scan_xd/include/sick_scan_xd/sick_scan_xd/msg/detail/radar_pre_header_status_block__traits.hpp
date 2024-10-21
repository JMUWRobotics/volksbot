// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderStatusBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarPreHeaderStatusBlock & msg,
  std::ostream & out)
{
  out << "{";
  // member: uitelegramcount
  {
    out << "uitelegramcount: ";
    rosidl_generator_traits::value_to_yaml(msg.uitelegramcount, out);
    out << ", ";
  }

  // member: uicyclecount
  {
    out << "uicyclecount: ";
    rosidl_generator_traits::value_to_yaml(msg.uicyclecount, out);
    out << ", ";
  }

  // member: udisystemcountscan
  {
    out << "udisystemcountscan: ";
    rosidl_generator_traits::value_to_yaml(msg.udisystemcountscan, out);
    out << ", ";
  }

  // member: udisystemcounttransmit
  {
    out << "udisystemcounttransmit: ";
    rosidl_generator_traits::value_to_yaml(msg.udisystemcounttransmit, out);
    out << ", ";
  }

  // member: uiinputs
  {
    out << "uiinputs: ";
    rosidl_generator_traits::value_to_yaml(msg.uiinputs, out);
    out << ", ";
  }

  // member: uioutputs
  {
    out << "uioutputs: ";
    rosidl_generator_traits::value_to_yaml(msg.uioutputs, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RadarPreHeaderStatusBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uitelegramcount
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uitelegramcount: ";
    rosidl_generator_traits::value_to_yaml(msg.uitelegramcount, out);
    out << "\n";
  }

  // member: uicyclecount
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uicyclecount: ";
    rosidl_generator_traits::value_to_yaml(msg.uicyclecount, out);
    out << "\n";
  }

  // member: udisystemcountscan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "udisystemcountscan: ";
    rosidl_generator_traits::value_to_yaml(msg.udisystemcountscan, out);
    out << "\n";
  }

  // member: udisystemcounttransmit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "udisystemcounttransmit: ";
    rosidl_generator_traits::value_to_yaml(msg.udisystemcounttransmit, out);
    out << "\n";
  }

  // member: uiinputs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uiinputs: ";
    rosidl_generator_traits::value_to_yaml(msg.uiinputs, out);
    out << "\n";
  }

  // member: uioutputs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uioutputs: ";
    rosidl_generator_traits::value_to_yaml(msg.uioutputs, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarPreHeaderStatusBlock & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::RadarPreHeaderStatusBlock>()
{
  return "sick_scan_xd::msg::RadarPreHeaderStatusBlock";
}

template<>
inline const char * name<sick_scan_xd::msg::RadarPreHeaderStatusBlock>()
{
  return "sick_scan_xd/msg/RadarPreHeaderStatusBlock";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::RadarPreHeaderStatusBlock>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::RadarPreHeaderStatusBlock>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::RadarPreHeaderStatusBlock>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__TRAITS_HPP_
