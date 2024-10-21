// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/ImuExtended.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__STRUCT_HPP_

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
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__ImuExtended __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__ImuExtended __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuExtended_
{
  using Type = ImuExtended_<ContainerAllocator>;

  explicit ImuExtended_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    imu(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ticks = 0ul;
      this->quaternion_accuracy = 0.0f;
      this->angular_velocity_reliability = 0;
      this->linear_acceleration_reliability = 0;
    }
  }

  explicit ImuExtended_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    imu(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ticks = 0ul;
      this->quaternion_accuracy = 0.0f;
      this->angular_velocity_reliability = 0;
      this->linear_acceleration_reliability = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _imu_type =
    sensor_msgs::msg::Imu_<ContainerAllocator>;
  _imu_type imu;
  using _ticks_type =
    uint32_t;
  _ticks_type ticks;
  using _quaternion_accuracy_type =
    float;
  _quaternion_accuracy_type quaternion_accuracy;
  using _angular_velocity_reliability_type =
    uint8_t;
  _angular_velocity_reliability_type angular_velocity_reliability;
  using _linear_acceleration_reliability_type =
    uint8_t;
  _linear_acceleration_reliability_type linear_acceleration_reliability;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__imu(
    const sensor_msgs::msg::Imu_<ContainerAllocator> & _arg)
  {
    this->imu = _arg;
    return *this;
  }
  Type & set__ticks(
    const uint32_t & _arg)
  {
    this->ticks = _arg;
    return *this;
  }
  Type & set__quaternion_accuracy(
    const float & _arg)
  {
    this->quaternion_accuracy = _arg;
    return *this;
  }
  Type & set__angular_velocity_reliability(
    const uint8_t & _arg)
  {
    this->angular_velocity_reliability = _arg;
    return *this;
  }
  Type & set__linear_acceleration_reliability(
    const uint8_t & _arg)
  {
    this->linear_acceleration_reliability = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::ImuExtended_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::ImuExtended_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::ImuExtended_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::ImuExtended_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__ImuExtended
    std::shared_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__ImuExtended
    std::shared_ptr<sick_scan_xd::msg::ImuExtended_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuExtended_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->imu != other.imu) {
      return false;
    }
    if (this->ticks != other.ticks) {
      return false;
    }
    if (this->quaternion_accuracy != other.quaternion_accuracy) {
      return false;
    }
    if (this->angular_velocity_reliability != other.angular_velocity_reliability) {
      return false;
    }
    if (this->linear_acceleration_reliability != other.linear_acceleration_reliability) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuExtended_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuExtended_

// alias to use template instance with default allocator
using ImuExtended =
  sick_scan_xd::msg::ImuExtended_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__STRUCT_HPP_
