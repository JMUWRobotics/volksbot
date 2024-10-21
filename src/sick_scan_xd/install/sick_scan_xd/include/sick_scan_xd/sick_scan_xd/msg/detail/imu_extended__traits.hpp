// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/ImuExtended.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/imu_extended__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImuExtended & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: imu
  {
    out << "imu: ";
    to_flow_style_yaml(msg.imu, out);
    out << ", ";
  }

  // member: ticks
  {
    out << "ticks: ";
    rosidl_generator_traits::value_to_yaml(msg.ticks, out);
    out << ", ";
  }

  // member: quaternion_accuracy
  {
    out << "quaternion_accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.quaternion_accuracy, out);
    out << ", ";
  }

  // member: angular_velocity_reliability
  {
    out << "angular_velocity_reliability: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_reliability, out);
    out << ", ";
  }

  // member: linear_acceleration_reliability
  {
    out << "linear_acceleration_reliability: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_acceleration_reliability, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImuExtended & msg,
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

  // member: imu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu:\n";
    to_block_style_yaml(msg.imu, out, indentation + 2);
  }

  // member: ticks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ticks: ";
    rosidl_generator_traits::value_to_yaml(msg.ticks, out);
    out << "\n";
  }

  // member: quaternion_accuracy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quaternion_accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.quaternion_accuracy, out);
    out << "\n";
  }

  // member: angular_velocity_reliability
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity_reliability: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_reliability, out);
    out << "\n";
  }

  // member: linear_acceleration_reliability
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_acceleration_reliability: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_acceleration_reliability, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImuExtended & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::ImuExtended & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::ImuExtended & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::ImuExtended>()
{
  return "sick_scan_xd::msg::ImuExtended";
}

template<>
inline const char * name<sick_scan_xd::msg::ImuExtended>()
{
  return "sick_scan_xd/msg/ImuExtended";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::ImuExtended>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Imu>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::ImuExtended>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Imu>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<sick_scan_xd::msg::ImuExtended>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__TRAITS_HPP_
