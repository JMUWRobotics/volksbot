// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderStatusBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderStatusBlock __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderStatusBlock __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarPreHeaderStatusBlock_
{
  using Type = RadarPreHeaderStatusBlock_<ContainerAllocator>;

  explicit RadarPreHeaderStatusBlock_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uitelegramcount = 0ul;
      this->uicyclecount = 0ul;
      this->udisystemcountscan = 0ul;
      this->udisystemcounttransmit = 0ul;
      this->uiinputs = 0;
      this->uioutputs = 0;
    }
  }

  explicit RadarPreHeaderStatusBlock_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uitelegramcount = 0ul;
      this->uicyclecount = 0ul;
      this->udisystemcountscan = 0ul;
      this->udisystemcounttransmit = 0ul;
      this->uiinputs = 0;
      this->uioutputs = 0;
    }
  }

  // field types and members
  using _uitelegramcount_type =
    uint32_t;
  _uitelegramcount_type uitelegramcount;
  using _uicyclecount_type =
    uint32_t;
  _uicyclecount_type uicyclecount;
  using _udisystemcountscan_type =
    uint32_t;
  _udisystemcountscan_type udisystemcountscan;
  using _udisystemcounttransmit_type =
    uint32_t;
  _udisystemcounttransmit_type udisystemcounttransmit;
  using _uiinputs_type =
    uint16_t;
  _uiinputs_type uiinputs;
  using _uioutputs_type =
    uint16_t;
  _uioutputs_type uioutputs;

  // setters for named parameter idiom
  Type & set__uitelegramcount(
    const uint32_t & _arg)
  {
    this->uitelegramcount = _arg;
    return *this;
  }
  Type & set__uicyclecount(
    const uint32_t & _arg)
  {
    this->uicyclecount = _arg;
    return *this;
  }
  Type & set__udisystemcountscan(
    const uint32_t & _arg)
  {
    this->udisystemcountscan = _arg;
    return *this;
  }
  Type & set__udisystemcounttransmit(
    const uint32_t & _arg)
  {
    this->udisystemcounttransmit = _arg;
    return *this;
  }
  Type & set__uiinputs(
    const uint16_t & _arg)
  {
    this->uiinputs = _arg;
    return *this;
  }
  Type & set__uioutputs(
    const uint16_t & _arg)
  {
    this->uioutputs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderStatusBlock
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderStatusBlock
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarPreHeaderStatusBlock_ & other) const
  {
    if (this->uitelegramcount != other.uitelegramcount) {
      return false;
    }
    if (this->uicyclecount != other.uicyclecount) {
      return false;
    }
    if (this->udisystemcountscan != other.udisystemcountscan) {
      return false;
    }
    if (this->udisystemcounttransmit != other.udisystemcounttransmit) {
      return false;
    }
    if (this->uiinputs != other.uiinputs) {
      return false;
    }
    if (this->uioutputs != other.uioutputs) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarPreHeaderStatusBlock_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarPreHeaderStatusBlock_

// alias to use template instance with default allocator
using RadarPreHeaderStatusBlock =
  sick_scan_xd::msg::RadarPreHeaderStatusBlock_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__STRUCT_HPP_
