// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarPreHeaderEncoderBlock & msg,
  std::ostream & out)
{
  out << "{";
  // member: udiencoderpos
  {
    out << "udiencoderpos: ";
    rosidl_generator_traits::value_to_yaml(msg.udiencoderpos, out);
    out << ", ";
  }

  // member: iencoderspeed
  {
    out << "iencoderspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.iencoderspeed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RadarPreHeaderEncoderBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: udiencoderpos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "udiencoderpos: ";
    rosidl_generator_traits::value_to_yaml(msg.udiencoderpos, out);
    out << "\n";
  }

  // member: iencoderspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "iencoderspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.iencoderspeed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarPreHeaderEncoderBlock & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::RadarPreHeaderEncoderBlock & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::RadarPreHeaderEncoderBlock & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>()
{
  return "sick_scan_xd::msg::RadarPreHeaderEncoderBlock";
}

template<>
inline const char * name<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>()
{
  return "sick_scan_xd/msg/RadarPreHeaderEncoderBlock";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::RadarPreHeaderEncoderBlock>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__TRAITS_HPP_
