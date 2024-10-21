// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/LIDoutputstateMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__LIDoutputstateMsg __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__LIDoutputstateMsg __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LIDoutputstateMsg_
{
  using Type = LIDoutputstateMsg_<ContainerAllocator>;

  explicit LIDoutputstateMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version_number = 0;
      this->system_counter = 0ul;
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

  explicit LIDoutputstateMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->version_number = 0;
      this->system_counter = 0ul;
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
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _version_number_type =
    uint16_t;
  _version_number_type version_number;
  using _system_counter_type =
    uint32_t;
  _system_counter_type system_counter;
  using _output_state_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _output_state_type output_state;
  using _output_count_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _output_count_type output_count;
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
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__version_number(
    const uint16_t & _arg)
  {
    this->version_number = _arg;
    return *this;
  }
  Type & set__system_counter(
    const uint32_t & _arg)
  {
    this->system_counter = _arg;
    return *this;
  }
  Type & set__output_state(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->output_state = _arg;
    return *this;
  }
  Type & set__output_count(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->output_count = _arg;
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
    sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__LIDoutputstateMsg
    std::shared_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__LIDoutputstateMsg
    std::shared_ptr<sick_scan_xd::msg::LIDoutputstateMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LIDoutputstateMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->version_number != other.version_number) {
      return false;
    }
    if (this->system_counter != other.system_counter) {
      return false;
    }
    if (this->output_state != other.output_state) {
      return false;
    }
    if (this->output_count != other.output_count) {
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
  bool operator!=(const LIDoutputstateMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LIDoutputstateMsg_

// alias to use template instance with default allocator
using LIDoutputstateMsg =
  sick_scan_xd::msg::LIDoutputstateMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__STRUCT_HPP_
