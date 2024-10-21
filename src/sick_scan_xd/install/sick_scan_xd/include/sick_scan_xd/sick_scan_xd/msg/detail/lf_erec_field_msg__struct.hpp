// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/LFErecFieldMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__LFErecFieldMsg __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__LFErecFieldMsg __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LFErecFieldMsg_
{
  using Type = LFErecFieldMsg_<ContainerAllocator>;

  explicit LFErecFieldMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version_number = 0;
      this->field_index = 0;
      this->sys_count = 0ul;
      this->dist_scale_factor = 0.0f;
      this->dist_scale_offset = 0.0f;
      this->angle_scale_factor = 0ul;
      this->angle_scale_offset = 0l;
      this->field_result_mrs = 0;
      this->time_state = 0;
      this->year = 0;
      this->month = 0;
      this->day = 0;
      this->hour = 0;
      this->minute = 0;
      this->second = 0;
      this->microsecond = 0ul;
    }
  }

  explicit LFErecFieldMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version_number = 0;
      this->field_index = 0;
      this->sys_count = 0ul;
      this->dist_scale_factor = 0.0f;
      this->dist_scale_offset = 0.0f;
      this->angle_scale_factor = 0ul;
      this->angle_scale_offset = 0l;
      this->field_result_mrs = 0;
      this->time_state = 0;
      this->year = 0;
      this->month = 0;
      this->day = 0;
      this->hour = 0;
      this->minute = 0;
      this->second = 0;
      this->microsecond = 0ul;
    }
  }

  // field types and members
  using _version_number_type =
    uint16_t;
  _version_number_type version_number;
  using _field_index_type =
    uint8_t;
  _field_index_type field_index;
  using _sys_count_type =
    uint32_t;
  _sys_count_type sys_count;
  using _dist_scale_factor_type =
    float;
  _dist_scale_factor_type dist_scale_factor;
  using _dist_scale_offset_type =
    float;
  _dist_scale_offset_type dist_scale_offset;
  using _angle_scale_factor_type =
    uint32_t;
  _angle_scale_factor_type angle_scale_factor;
  using _angle_scale_offset_type =
    int32_t;
  _angle_scale_offset_type angle_scale_offset;
  using _field_result_mrs_type =
    uint8_t;
  _field_result_mrs_type field_result_mrs;
  using _time_state_type =
    uint16_t;
  _time_state_type time_state;
  using _year_type =
    uint16_t;
  _year_type year;
  using _month_type =
    uint8_t;
  _month_type month;
  using _day_type =
    uint8_t;
  _day_type day;
  using _hour_type =
    uint8_t;
  _hour_type hour;
  using _minute_type =
    uint8_t;
  _minute_type minute;
  using _second_type =
    uint8_t;
  _second_type second;
  using _microsecond_type =
    uint32_t;
  _microsecond_type microsecond;

  // setters for named parameter idiom
  Type & set__version_number(
    const uint16_t & _arg)
  {
    this->version_number = _arg;
    return *this;
  }
  Type & set__field_index(
    const uint8_t & _arg)
  {
    this->field_index = _arg;
    return *this;
  }
  Type & set__sys_count(
    const uint32_t & _arg)
  {
    this->sys_count = _arg;
    return *this;
  }
  Type & set__dist_scale_factor(
    const float & _arg)
  {
    this->dist_scale_factor = _arg;
    return *this;
  }
  Type & set__dist_scale_offset(
    const float & _arg)
  {
    this->dist_scale_offset = _arg;
    return *this;
  }
  Type & set__angle_scale_factor(
    const uint32_t & _arg)
  {
    this->angle_scale_factor = _arg;
    return *this;
  }
  Type & set__angle_scale_offset(
    const int32_t & _arg)
  {
    this->angle_scale_offset = _arg;
    return *this;
  }
  Type & set__field_result_mrs(
    const uint8_t & _arg)
  {
    this->field_result_mrs = _arg;
    return *this;
  }
  Type & set__time_state(
    const uint16_t & _arg)
  {
    this->time_state = _arg;
    return *this;
  }
  Type & set__year(
    const uint16_t & _arg)
  {
    this->year = _arg;
    return *this;
  }
  Type & set__month(
    const uint8_t & _arg)
  {
    this->month = _arg;
    return *this;
  }
  Type & set__day(
    const uint8_t & _arg)
  {
    this->day = _arg;
    return *this;
  }
  Type & set__hour(
    const uint8_t & _arg)
  {
    this->hour = _arg;
    return *this;
  }
  Type & set__minute(
    const uint8_t & _arg)
  {
    this->minute = _arg;
    return *this;
  }
  Type & set__second(
    const uint8_t & _arg)
  {
    this->second = _arg;
    return *this;
  }
  Type & set__microsecond(
    const uint32_t & _arg)
  {
    this->microsecond = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__LFErecFieldMsg
    std::shared_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__LFErecFieldMsg
    std::shared_ptr<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LFErecFieldMsg_ & other) const
  {
    if (this->version_number != other.version_number) {
      return false;
    }
    if (this->field_index != other.field_index) {
      return false;
    }
    if (this->sys_count != other.sys_count) {
      return false;
    }
    if (this->dist_scale_factor != other.dist_scale_factor) {
      return false;
    }
    if (this->dist_scale_offset != other.dist_scale_offset) {
      return false;
    }
    if (this->angle_scale_factor != other.angle_scale_factor) {
      return false;
    }
    if (this->angle_scale_offset != other.angle_scale_offset) {
      return false;
    }
    if (this->field_result_mrs != other.field_result_mrs) {
      return false;
    }
    if (this->time_state != other.time_state) {
      return false;
    }
    if (this->year != other.year) {
      return false;
    }
    if (this->month != other.month) {
      return false;
    }
    if (this->day != other.day) {
      return false;
    }
    if (this->hour != other.hour) {
      return false;
    }
    if (this->minute != other.minute) {
      return false;
    }
    if (this->second != other.second) {
      return false;
    }
    if (this->microsecond != other.microsecond) {
      return false;
    }
    return true;
  }
  bool operator!=(const LFErecFieldMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LFErecFieldMsg_

// alias to use template instance with default allocator
using LFErecFieldMsg =
  sick_scan_xd::msg::LFErecFieldMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__STRUCT_HPP_
