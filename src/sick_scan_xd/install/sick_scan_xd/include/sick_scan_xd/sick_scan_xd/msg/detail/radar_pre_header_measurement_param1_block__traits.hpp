// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderMeasurementParam1Block.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/radar_pre_header_measurement_param1_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarPreHeaderMeasurementParam1Block & msg,
  std::ostream & out)
{
  out << "{";
  // member: uicycleduration
  {
    out << "uicycleduration: ";
    rosidl_generator_traits::value_to_yaml(msg.uicycleduration, out);
    out << ", ";
  }

  // member: uinoiselevel
  {
    out << "uinoiselevel: ";
    rosidl_generator_traits::value_to_yaml(msg.uinoiselevel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RadarPreHeaderMeasurementParam1Block & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uicycleduration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uicycleduration: ";
    rosidl_generator_traits::value_to_yaml(msg.uicycleduration, out);
    out << "\n";
  }

  // member: uinoiselevel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uinoiselevel: ";
    rosidl_generator_traits::value_to_yaml(msg.uinoiselevel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarPreHeaderMeasurementParam1Block & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>()
{
  return "sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block";
}

template<>
inline const char * name<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>()
{
  return "sick_scan_xd/msg/RadarPreHeaderMeasurementParam1Block";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__TRAITS_HPP_
