// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/NAVPoseData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/nav_pose_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const NAVPoseData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: phi
  {
    out << "phi: ";
    rosidl_generator_traits::value_to_yaml(msg.phi, out);
    out << ", ";
  }

  // member: opt_pose_data_valid
  {
    out << "opt_pose_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.opt_pose_data_valid, out);
    out << ", ";
  }

  // member: output_mode
  {
    out << "output_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.output_mode, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: mean_dev
  {
    out << "mean_dev: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_dev, out);
    out << ", ";
  }

  // member: nav_mode
  {
    out << "nav_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.nav_mode, out);
    out << ", ";
  }

  // member: info_state
  {
    out << "info_state: ";
    rosidl_generator_traits::value_to_yaml(msg.info_state, out);
    out << ", ";
  }

  // member: quant_used_reflectors
  {
    out << "quant_used_reflectors: ";
    rosidl_generator_traits::value_to_yaml(msg.quant_used_reflectors, out);
    out << ", ";
  }

  // member: pose_valid
  {
    out << "pose_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_valid, out);
    out << ", ";
  }

  // member: pose_x
  {
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << ", ";
  }

  // member: pose_y
  {
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
    out << ", ";
  }

  // member: pose_yaw
  {
    out << "pose_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NAVPoseData & msg,
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: phi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phi: ";
    rosidl_generator_traits::value_to_yaml(msg.phi, out);
    out << "\n";
  }

  // member: opt_pose_data_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "opt_pose_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.opt_pose_data_valid, out);
    out << "\n";
  }

  // member: output_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.output_mode, out);
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

  // member: mean_dev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_dev: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_dev, out);
    out << "\n";
  }

  // member: nav_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nav_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.nav_mode, out);
    out << "\n";
  }

  // member: info_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info_state: ";
    rosidl_generator_traits::value_to_yaml(msg.info_state, out);
    out << "\n";
  }

  // member: quant_used_reflectors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quant_used_reflectors: ";
    rosidl_generator_traits::value_to_yaml(msg.quant_used_reflectors, out);
    out << "\n";
  }

  // member: pose_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_valid, out);
    out << "\n";
  }

  // member: pose_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << "\n";
  }

  // member: pose_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
    out << "\n";
  }

  // member: pose_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NAVPoseData & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::NAVPoseData & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::NAVPoseData & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::NAVPoseData>()
{
  return "sick_scan_xd::msg::NAVPoseData";
}

template<>
inline const char * name<sick_scan_xd::msg::NAVPoseData>()
{
  return "sick_scan_xd/msg/NAVPoseData";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::NAVPoseData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::NAVPoseData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<sick_scan_xd::msg::NAVPoseData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__TRAITS_HPP_
