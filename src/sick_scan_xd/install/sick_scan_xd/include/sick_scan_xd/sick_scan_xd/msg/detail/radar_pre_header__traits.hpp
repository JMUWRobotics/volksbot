// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeader.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/radar_pre_header__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'radarpreheaderdeviceblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__traits.hpp"
// Member 'radarpreheaderstatusblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__traits.hpp"
// Member 'radarpreheadermeasurementparam1block'
#include "sick_scan_xd/msg/detail/radar_pre_header_measurement_param1_block__traits.hpp"
// Member 'radarpreheaderarrayencoderblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarPreHeader & msg,
  std::ostream & out)
{
  out << "{";
  // member: uiversionno
  {
    out << "uiversionno: ";
    rosidl_generator_traits::value_to_yaml(msg.uiversionno, out);
    out << ", ";
  }

  // member: radarpreheaderdeviceblock
  {
    out << "radarpreheaderdeviceblock: ";
    to_flow_style_yaml(msg.radarpreheaderdeviceblock, out);
    out << ", ";
  }

  // member: radarpreheaderstatusblock
  {
    out << "radarpreheaderstatusblock: ";
    to_flow_style_yaml(msg.radarpreheaderstatusblock, out);
    out << ", ";
  }

  // member: radarpreheadermeasurementparam1block
  {
    out << "radarpreheadermeasurementparam1block: ";
    to_flow_style_yaml(msg.radarpreheadermeasurementparam1block, out);
    out << ", ";
  }

  // member: radarpreheaderarrayencoderblock
  {
    if (msg.radarpreheaderarrayencoderblock.size() == 0) {
      out << "radarpreheaderarrayencoderblock: []";
    } else {
      out << "radarpreheaderarrayencoderblock: [";
      size_t pending_items = msg.radarpreheaderarrayencoderblock.size();
      for (auto item : msg.radarpreheaderarrayencoderblock) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RadarPreHeader & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uiversionno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uiversionno: ";
    rosidl_generator_traits::value_to_yaml(msg.uiversionno, out);
    out << "\n";
  }

  // member: radarpreheaderdeviceblock
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radarpreheaderdeviceblock:\n";
    to_block_style_yaml(msg.radarpreheaderdeviceblock, out, indentation + 2);
  }

  // member: radarpreheaderstatusblock
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radarpreheaderstatusblock:\n";
    to_block_style_yaml(msg.radarpreheaderstatusblock, out, indentation + 2);
  }

  // member: radarpreheadermeasurementparam1block
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radarpreheadermeasurementparam1block:\n";
    to_block_style_yaml(msg.radarpreheadermeasurementparam1block, out, indentation + 2);
  }

  // member: radarpreheaderarrayencoderblock
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.radarpreheaderarrayencoderblock.size() == 0) {
      out << "radarpreheaderarrayencoderblock: []\n";
    } else {
      out << "radarpreheaderarrayencoderblock:\n";
      for (auto item : msg.radarpreheaderarrayencoderblock) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarPreHeader & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::RadarPreHeader & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::RadarPreHeader & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::RadarPreHeader>()
{
  return "sick_scan_xd::msg::RadarPreHeader";
}

template<>
inline const char * name<sick_scan_xd::msg::RadarPreHeader>()
{
  return "sick_scan_xd/msg/RadarPreHeader";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::RadarPreHeader>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::RadarPreHeader>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sick_scan_xd::msg::RadarPreHeader>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__TRAITS_HPP_
