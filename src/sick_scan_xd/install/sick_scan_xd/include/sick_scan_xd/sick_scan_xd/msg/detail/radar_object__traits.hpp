// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/RadarObject.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/radar_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'tracking_time'
// Member 'last_seen'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_with_covariance__traits.hpp"
// Member 'bounding_box_center'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'bounding_box_size'
// Member 'object_box_size'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'object_box_center'
#include "geometry_msgs/msg/detail/pose_with_covariance__traits.hpp"
// Member 'contour_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: tracking_time
  {
    out << "tracking_time: ";
    to_flow_style_yaml(msg.tracking_time, out);
    out << ", ";
  }

  // member: last_seen
  {
    out << "last_seen: ";
    to_flow_style_yaml(msg.last_seen, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: bounding_box_center
  {
    out << "bounding_box_center: ";
    to_flow_style_yaml(msg.bounding_box_center, out);
    out << ", ";
  }

  // member: bounding_box_size
  {
    out << "bounding_box_size: ";
    to_flow_style_yaml(msg.bounding_box_size, out);
    out << ", ";
  }

  // member: object_box_center
  {
    out << "object_box_center: ";
    to_flow_style_yaml(msg.object_box_center, out);
    out << ", ";
  }

  // member: object_box_size
  {
    out << "object_box_size: ";
    to_flow_style_yaml(msg.object_box_size, out);
    out << ", ";
  }

  // member: contour_points
  {
    if (msg.contour_points.size() == 0) {
      out << "contour_points: []";
    } else {
      out << "contour_points: [";
      size_t pending_items = msg.contour_points.size();
      for (auto item : msg.contour_points) {
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
  const RadarObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: tracking_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracking_time:\n";
    to_block_style_yaml(msg.tracking_time, out, indentation + 2);
  }

  // member: last_seen
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_seen:\n";
    to_block_style_yaml(msg.last_seen, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: bounding_box_center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounding_box_center:\n";
    to_block_style_yaml(msg.bounding_box_center, out, indentation + 2);
  }

  // member: bounding_box_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounding_box_size:\n";
    to_block_style_yaml(msg.bounding_box_size, out, indentation + 2);
  }

  // member: object_box_center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_box_center:\n";
    to_block_style_yaml(msg.object_box_center, out, indentation + 2);
  }

  // member: object_box_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_box_size:\n";
    to_block_style_yaml(msg.object_box_size, out, indentation + 2);
  }

  // member: contour_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.contour_points.size() == 0) {
      out << "contour_points: []\n";
    } else {
      out << "contour_points:\n";
      for (auto item : msg.contour_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarObject & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::RadarObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::RadarObject & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::RadarObject>()
{
  return "sick_scan_xd::msg::RadarObject";
}

template<>
inline const char * name<sick_scan_xd::msg::RadarObject>()
{
  return "sick_scan_xd/msg/RadarObject";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::RadarObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::RadarObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sick_scan_xd::msg::RadarObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__TRAITS_HPP_
