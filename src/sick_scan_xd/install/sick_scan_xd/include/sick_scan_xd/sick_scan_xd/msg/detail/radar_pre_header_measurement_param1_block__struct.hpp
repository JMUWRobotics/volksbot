// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderMeasurementParam1Block.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarPreHeaderMeasurementParam1Block_
{
  using Type = RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>;

  explicit RadarPreHeaderMeasurementParam1Block_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uicycleduration = 0ul;
      this->uinoiselevel = 0ul;
    }
  }

  explicit RadarPreHeaderMeasurementParam1Block_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uicycleduration = 0ul;
      this->uinoiselevel = 0ul;
    }
  }

  // field types and members
  using _uicycleduration_type =
    uint32_t;
  _uicycleduration_type uicycleduration;
  using _uinoiselevel_type =
    uint32_t;
  _uinoiselevel_type uinoiselevel;

  // setters for named parameter idiom
  Type & set__uicycleduration(
    const uint32_t & _arg)
  {
    this->uicycleduration = _arg;
    return *this;
  }
  Type & set__uinoiselevel(
    const uint32_t & _arg)
  {
    this->uinoiselevel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarPreHeaderMeasurementParam1Block_ & other) const
  {
    if (this->uicycleduration != other.uicycleduration) {
      return false;
    }
    if (this->uinoiselevel != other.uinoiselevel) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarPreHeaderMeasurementParam1Block_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarPreHeaderMeasurementParam1Block_

// alias to use template instance with default allocator
using RadarPreHeaderMeasurementParam1Block =
  sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__STRUCT_HPP_
