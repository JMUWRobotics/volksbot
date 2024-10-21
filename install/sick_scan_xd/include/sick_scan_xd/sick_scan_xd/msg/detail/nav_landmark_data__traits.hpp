// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/NAVLandmarkData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/nav_landmark_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'reflectors'
#include "sick_scan_xd/msg/detail/nav_reflector_data__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const NAVLandmarkData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: landmark_filter
  {
    out << "landmark_filter: ";
    rosidl_generator_traits::value_to_yaml(msg.landmark_filter, out);
    out << ", ";
  }

  // member: num_reflectors
  {
    out << "num_reflectors: ";
    rosidl_generator_traits::value_to_yaml(msg.num_reflectors, out);
    out << ", ";
  }

  // member: reflectors
  {
    if (msg.reflectors.size() == 0) {
      out << "reflectors: []";
    } else {
      out << "reflectors: [";
      size_t pending_items = msg.reflectors.size();
      for (auto item : msg.reflectors) {
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
  const NAVLandmarkData & msg,
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

  // member: landmark_filter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "landmark_filter: ";
    rosidl_generator_traits::value_to_yaml(msg.landmark_filter, out);
    out << "\n";
  }

  // member: num_reflectors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_reflectors: ";
    rosidl_generator_traits::value_to_yaml(msg.num_reflectors, out);
    out << "\n";
  }

  // member: reflectors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reflectors.size() == 0) {
      out << "reflectors: []\n";
    } else {
      out << "reflectors:\n";
      for (auto item : msg.reflectors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NAVLandmarkData & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::NAVLandmarkData & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::NAVLandmarkData & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::NAVLandmarkData>()
{
  return "sick_scan_xd::msg::NAVLandmarkData";
}

template<>
inline const char * name<sick_scan_xd::msg::NAVLandmarkData>()
{
  return "sick_scan_xd/msg/NAVLandmarkData";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::NAVLandmarkData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::NAVLandmarkData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sick_scan_xd::msg::NAVLandmarkData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__TRAITS_HPP_
