// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderDeviceBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarPreHeaderDeviceBlock & msg,
  std::ostream & out)
{
  out << "{";
  // member: uiident
  {
    out << "uiident: ";
    rosidl_generator_traits::value_to_yaml(msg.uiident, out);
    out << ", ";
  }

  // member: udiserialno
  {
    out << "udiserialno: ";
    rosidl_generator_traits::value_to_yaml(msg.udiserialno, out);
    out << ", ";
  }

  // member: bdeviceerror
  {
    out << "bdeviceerror: ";
    rosidl_generator_traits::value_to_yaml(msg.bdeviceerror, out);
    out << ", ";
  }

  // member: bcontaminationwarning
  {
    out << "bcontaminationwarning: ";
    rosidl_generator_traits::value_to_yaml(msg.bcontaminationwarning, out);
    out << ", ";
  }

  // member: bcontaminationerror
  {
    out << "bcontaminationerror: ";
    rosidl_generator_traits::value_to_yaml(msg.bcontaminationerror, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RadarPreHeaderDeviceBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uiident
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uiident: ";
    rosidl_generator_traits::value_to_yaml(msg.uiident, out);
    out << "\n";
  }

  // member: udiserialno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "udiserialno: ";
    rosidl_generator_traits::value_to_yaml(msg.udiserialno, out);
    out << "\n";
  }

  // member: bdeviceerror
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bdeviceerror: ";
    rosidl_generator_traits::value_to_yaml(msg.bdeviceerror, out);
    out << "\n";
  }

  // member: bcontaminationwarning
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bcontaminationwarning: ";
    rosidl_generator_traits::value_to_yaml(msg.bcontaminationwarning, out);
    out << "\n";
  }

  // member: bcontaminationerror
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bcontaminationerror: ";
    rosidl_generator_traits::value_to_yaml(msg.bcontaminationerror, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarPreHeaderDeviceBlock & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::RadarPreHeaderDeviceBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::RadarPreHeaderDeviceBlock & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::RadarPreHeaderDeviceBlock>()
{
  return "sick_scan_xd::msg::RadarPreHeaderDeviceBlock";
}

template<>
inline const char * name<sick_scan_xd::msg::RadarPreHeaderDeviceBlock>()
{
  return "sick_scan_xd/msg/RadarPreHeaderDeviceBlock";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::RadarPreHeaderDeviceBlock>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::RadarPreHeaderDeviceBlock>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::RadarPreHeaderDeviceBlock>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__TRAITS_HPP_
