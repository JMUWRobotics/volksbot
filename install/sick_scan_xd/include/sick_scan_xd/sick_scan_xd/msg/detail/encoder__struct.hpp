// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/Encoder.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__ENCODER__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__ENCODER__STRUCT_HPP_

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
# define DEPRECATED__sick_scan_xd__msg__Encoder __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__Encoder __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Encoder_
{
  using Type = Encoder_<ContainerAllocator>;

  explicit Encoder_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enc_position = 0l;
      this->enc_speed = 0;
    }
  }

  explicit Encoder_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enc_position = 0l;
      this->enc_speed = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _enc_position_type =
    int32_t;
  _enc_position_type enc_position;
  using _enc_speed_type =
    int16_t;
  _enc_speed_type enc_speed;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__enc_position(
    const int32_t & _arg)
  {
    this->enc_position = _arg;
    return *this;
  }
  Type & set__enc_speed(
    const int16_t & _arg)
  {
    this->enc_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::Encoder_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::Encoder_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::Encoder_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::Encoder_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__Encoder
    std::shared_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__Encoder
    std::shared_ptr<sick_scan_xd::msg::Encoder_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Encoder_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->enc_position != other.enc_position) {
      return false;
    }
    if (this->enc_speed != other.enc_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Encoder_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Encoder_

// alias to use template instance with default allocator
using Encoder =
  sick_scan_xd::msg::Encoder_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__ENCODER__STRUCT_HPP_
