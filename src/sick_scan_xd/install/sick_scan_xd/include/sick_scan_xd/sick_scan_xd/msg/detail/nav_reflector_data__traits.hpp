// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/NAVReflectorData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/nav_reflector_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const NAVReflectorData & msg,
  std::ostream & out)
{
  out << "{";
  // member: cartesian_data_valid
  {
    out << "cartesian_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.cartesian_data_valid, out);
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

  // member: polar_data_valid
  {
    out << "polar_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.polar_data_valid, out);
    out << ", ";
  }

  // member: dist
  {
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << ", ";
  }

  // member: phi
  {
    out << "phi: ";
    rosidl_generator_traits::value_to_yaml(msg.phi, out);
    out << ", ";
  }

  // member: opt_reflector_data_valid
  {
    out << "opt_reflector_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.opt_reflector_data_valid, out);
    out << ", ";
  }

  // member: local_id
  {
    out << "local_id: ";
    rosidl_generator_traits::value_to_yaml(msg.local_id, out);
    out << ", ";
  }

  // member: global_id
  {
    out << "global_id: ";
    rosidl_generator_traits::value_to_yaml(msg.global_id, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: sub_type
  {
    out << "sub_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sub_type, out);
    out << ", ";
  }

  // member: quality
  {
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << ", ";
  }

  // member: hit_count
  {
    out << "hit_count: ";
    rosidl_generator_traits::value_to_yaml(msg.hit_count, out);
    out << ", ";
  }

  // member: mean_echo
  {
    out << "mean_echo: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_echo, out);
    out << ", ";
  }

  // member: start_index
  {
    out << "start_index: ";
    rosidl_generator_traits::value_to_yaml(msg.start_index, out);
    out << ", ";
  }

  // member: end_index
  {
    out << "end_index: ";
    rosidl_generator_traits::value_to_yaml(msg.end_index, out);
    out << ", ";
  }

  // member: pos_valid
  {
    out << "pos_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_valid, out);
    out << ", ";
  }

  // member: pos_x
  {
    out << "pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_x, out);
    out << ", ";
  }

  // member: pos_y
  {
    out << "pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NAVReflectorData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cartesian_data_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cartesian_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.cartesian_data_valid, out);
    out << "\n";
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

  // member: polar_data_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polar_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.polar_data_valid, out);
    out << "\n";
  }

  // member: dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
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

  // member: opt_reflector_data_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "opt_reflector_data_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.opt_reflector_data_valid, out);
    out << "\n";
  }

  // member: local_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_id: ";
    rosidl_generator_traits::value_to_yaml(msg.local_id, out);
    out << "\n";
  }

  // member: global_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "global_id: ";
    rosidl_generator_traits::value_to_yaml(msg.global_id, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: sub_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sub_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sub_type, out);
    out << "\n";
  }

  // member: quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
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

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }

  // member: hit_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hit_count: ";
    rosidl_generator_traits::value_to_yaml(msg.hit_count, out);
    out << "\n";
  }

  // member: mean_echo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_echo: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_echo, out);
    out << "\n";
  }

  // member: start_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_index: ";
    rosidl_generator_traits::value_to_yaml(msg.start_index, out);
    out << "\n";
  }

  // member: end_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_index: ";
    rosidl_generator_traits::value_to_yaml(msg.end_index, out);
    out << "\n";
  }

  // member: pos_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_valid, out);
    out << "\n";
  }

  // member: pos_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_x, out);
    out << "\n";
  }

  // member: pos_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NAVReflectorData & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::NAVReflectorData & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::NAVReflectorData & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::NAVReflectorData>()
{
  return "sick_scan_xd::msg::NAVReflectorData";
}

template<>
inline const char * name<sick_scan_xd::msg::NAVReflectorData>()
{
  return "sick_scan_xd/msg/NAVReflectorData";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::NAVReflectorData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::NAVReflectorData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sick_scan_xd::msg::NAVReflectorData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__TRAITS_HPP_
