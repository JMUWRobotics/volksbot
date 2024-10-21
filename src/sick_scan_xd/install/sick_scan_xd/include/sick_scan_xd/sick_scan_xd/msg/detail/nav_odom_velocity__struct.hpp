// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/NAVOdomVelocity.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__NAVOdomVelocity __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__NAVOdomVelocity __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NAVOdomVelocity_
{
  using Type = NAVOdomVelocity_<ContainerAllocator>;

  explicit NAVOdomVelocity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_x = 0.0f;
      this->vel_y = 0.0f;
      this->omega = 0.0f;
      this->timestamp = 0ul;
      this->coordbase = 0;
    }
  }

  explicit NAVOdomVelocity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_x = 0.0f;
      this->vel_y = 0.0f;
      this->omega = 0.0f;
      this->timestamp = 0ul;
      this->coordbase = 0;
    }
  }

  // field types and members
  using _vel_x_type =
    float;
  _vel_x_type vel_x;
  using _vel_y_type =
    float;
  _vel_y_type vel_y;
  using _omega_type =
    float;
  _omega_type omega;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;
  using _coordbase_type =
    uint8_t;
  _coordbase_type coordbase;

  // setters for named parameter idiom
  Type & set__vel_x(
    const float & _arg)
  {
    this->vel_x = _arg;
    return *this;
  }
  Type & set__vel_y(
    const float & _arg)
  {
    this->vel_y = _arg;
    return *this;
  }
  Type & set__omega(
    const float & _arg)
  {
    this->omega = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__coordbase(
    const uint8_t & _arg)
  {
    this->coordbase = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__NAVOdomVelocity
    std::shared_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__NAVOdomVelocity
    std::shared_ptr<sick_scan_xd::msg::NAVOdomVelocity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NAVOdomVelocity_ & other) const
  {
    if (this->vel_x != other.vel_x) {
      return false;
    }
    if (this->vel_y != other.vel_y) {
      return false;
    }
    if (this->omega != other.omega) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->coordbase != other.coordbase) {
      return false;
    }
    return true;
  }
  bool operator!=(const NAVOdomVelocity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NAVOdomVelocity_

// alias to use template instance with default allocator
using NAVOdomVelocity =
  sick_scan_xd::msg::NAVOdomVelocity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__STRUCT_HPP_
