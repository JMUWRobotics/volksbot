// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sick_scan_xd:msg/LIDoutputstateMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__TRAITS_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sick_scan_xd/msg/detail/li_doutputstate_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace sick_scan_xd
{

namespace msg
{

inline void to_flow_style_yaml(
  const LIDoutputstateMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: version_number
  {
    out << "version_number: ";
    rosidl_generator_traits::value_to_yaml(msg.version_number, out);
    out << ", ";
  }

  // member: system_counter
  {
    out << "system_counter: ";
    rosidl_generator_traits::value_to_yaml(msg.system_counter, out);
    out << ", ";
  }

  // member: output_state
  {
    if (msg.output_state.size() == 0) {
      out << "output_state: []";
    } else {
      out << "output_state: [";
      size_t pending_items = msg.output_state.size();
      for (auto item : msg.output_state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: output_count
  {
    if (msg.output_count.size() == 0) {
      out << "output_count: []";
    } else {
      out << "output_count: [";
      size_t pending_items = msg.output_count.size();
      for (auto item : msg.output_count) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: time_state
  {
    out << "time_state: ";
    rosidl_generator_traits::value_to_yaml(msg.time_state, out);
    out << ", ";
  }

  // member: year
  {
    out << "year: ";
    rosidl_generator_traits::value_to_yaml(msg.year, out);
    out << ", ";
  }

  // member: month
  {
    out << "month: ";
    rosidl_generator_traits::value_to_yaml(msg.month, out);
    out << ", ";
  }

  // member: day
  {
    out << "day: ";
    rosidl_generator_traits::value_to_yaml(msg.day, out);
    out << ", ";
  }

  // member: hour
  {
    out << "hour: ";
    rosidl_generator_traits::value_to_yaml(msg.hour, out);
    out << ", ";
  }

  // member: minute
  {
    out << "minute: ";
    rosidl_generator_traits::value_to_yaml(msg.minute, out);
    out << ", ";
  }

  // member: second
  {
    out << "second: ";
    rosidl_generator_traits::value_to_yaml(msg.second, out);
    out << ", ";
  }

  // member: microsecond
  {
    out << "microsecond: ";
    rosidl_generator_traits::value_to_yaml(msg.microsecond, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LIDoutputstateMsg & msg,
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

  // member: version_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version_number: ";
    rosidl_generator_traits::value_to_yaml(msg.version_number, out);
    out << "\n";
  }

  // member: system_counter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "system_counter: ";
    rosidl_generator_traits::value_to_yaml(msg.system_counter, out);
    out << "\n";
  }

  // member: output_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.output_state.size() == 0) {
      out << "output_state: []\n";
    } else {
      out << "output_state:\n";
      for (auto item : msg.output_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: output_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.output_count.size() == 0) {
      out << "output_count: []\n";
    } else {
      out << "output_count:\n";
      for (auto item : msg.output_count) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: time_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_state: ";
    rosidl_generator_traits::value_to_yaml(msg.time_state, out);
    out << "\n";
  }

  // member: year
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "year: ";
    rosidl_generator_traits::value_to_yaml(msg.year, out);
    out << "\n";
  }

  // member: month
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "month: ";
    rosidl_generator_traits::value_to_yaml(msg.month, out);
    out << "\n";
  }

  // member: day
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "day: ";
    rosidl_generator_traits::value_to_yaml(msg.day, out);
    out << "\n";
  }

  // member: hour
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hour: ";
    rosidl_generator_traits::value_to_yaml(msg.hour, out);
    out << "\n";
  }

  // member: minute
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "minute: ";
    rosidl_generator_traits::value_to_yaml(msg.minute, out);
    out << "\n";
  }

  // member: second
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "second: ";
    rosidl_generator_traits::value_to_yaml(msg.second, out);
    out << "\n";
  }

  // member: microsecond
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "microsecond: ";
    rosidl_generator_traits::value_to_yaml(msg.microsecond, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LIDoutputstateMsg & msg, bool use_flow_style = false)
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
  const sick_scan_xd::msg::LIDoutputstateMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  sick_scan_xd::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sick_scan_xd::msg::to_yaml() instead")]]
inline std::string to_yaml(const sick_scan_xd::msg::LIDoutputstateMsg & msg)
{
  return sick_scan_xd::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sick_scan_xd::msg::LIDoutputstateMsg>()
{
  return "sick_scan_xd::msg::LIDoutputstateMsg";
}

template<>
inline const char * name<sick_scan_xd::msg::LIDoutputstateMsg>()
{
  return "sick_scan_xd/msg/LIDoutputstateMsg";
}

template<>
struct has_fixed_size<sick_scan_xd::msg::LIDoutputstateMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sick_scan_xd::msg::LIDoutputstateMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sick_scan_xd::msg::LIDoutputstateMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__TRAITS_HPP_
