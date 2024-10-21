// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderEncoderBlock __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderEncoderBlock __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarPreHeaderEncoderBlock_
{
  using Type = RadarPreHeaderEncoderBlock_<ContainerAllocator>;

  explicit RadarPreHeaderEncoderBlock_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->udiencoderpos = 0ul;
      this->iencoderspeed = 0;
    }
  }

  explicit RadarPreHeaderEncoderBlock_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->udiencoderpos = 0ul;
      this->iencoderspeed = 0;
    }
  }

  // field types and members
  using _udiencoderpos_type =
    uint32_t;
  _udiencoderpos_type udiencoderpos;
  using _iencoderspeed_type =
    int16_t;
  _iencoderspeed_type iencoderspeed;

  // setters for named parameter idiom
  Type & set__udiencoderpos(
    const uint32_t & _arg)
  {
    this->udiencoderpos = _arg;
    return *this;
  }
  Type & set__iencoderspeed(
    const int16_t & _arg)
  {
    this->iencoderspeed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderEncoderBlock
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderEncoderBlock
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarPreHeaderEncoderBlock_ & other) const
  {
    if (this->udiencoderpos != other.udiencoderpos) {
      return false;
    }
    if (this->iencoderspeed != other.iencoderspeed) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarPreHeaderEncoderBlock_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarPreHeaderEncoderBlock_

// alias to use template instance with default allocator
using RadarPreHeaderEncoderBlock =
  sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__STRUCT_HPP_
