// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderDeviceBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderDeviceBlock __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeaderDeviceBlock __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarPreHeaderDeviceBlock_
{
  using Type = RadarPreHeaderDeviceBlock_<ContainerAllocator>;

  explicit RadarPreHeaderDeviceBlock_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uiident = 0ul;
      this->udiserialno = 0ul;
      this->bdeviceerror = false;
      this->bcontaminationwarning = false;
      this->bcontaminationerror = false;
    }
  }

  explicit RadarPreHeaderDeviceBlock_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uiident = 0ul;
      this->udiserialno = 0ul;
      this->bdeviceerror = false;
      this->bcontaminationwarning = false;
      this->bcontaminationerror = false;
    }
  }

  // field types and members
  using _uiident_type =
    uint32_t;
  _uiident_type uiident;
  using _udiserialno_type =
    uint32_t;
  _udiserialno_type udiserialno;
  using _bdeviceerror_type =
    bool;
  _bdeviceerror_type bdeviceerror;
  using _bcontaminationwarning_type =
    bool;
  _bcontaminationwarning_type bcontaminationwarning;
  using _bcontaminationerror_type =
    bool;
  _bcontaminationerror_type bcontaminationerror;

  // setters for named parameter idiom
  Type & set__uiident(
    const uint32_t & _arg)
  {
    this->uiident = _arg;
    return *this;
  }
  Type & set__udiserialno(
    const uint32_t & _arg)
  {
    this->udiserialno = _arg;
    return *this;
  }
  Type & set__bdeviceerror(
    const bool & _arg)
  {
    this->bdeviceerror = _arg;
    return *this;
  }
  Type & set__bcontaminationwarning(
    const bool & _arg)
  {
    this->bcontaminationwarning = _arg;
    return *this;
  }
  Type & set__bcontaminationerror(
    const bool & _arg)
  {
    this->bcontaminationerror = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderDeviceBlock
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeaderDeviceBlock
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarPreHeaderDeviceBlock_ & other) const
  {
    if (this->uiident != other.uiident) {
      return false;
    }
    if (this->udiserialno != other.udiserialno) {
      return false;
    }
    if (this->bdeviceerror != other.bdeviceerror) {
      return false;
    }
    if (this->bcontaminationwarning != other.bcontaminationwarning) {
      return false;
    }
    if (this->bcontaminationerror != other.bcontaminationerror) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarPreHeaderDeviceBlock_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarPreHeaderDeviceBlock_

// alias to use template instance with default allocator
using RadarPreHeaderDeviceBlock =
  sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__STRUCT_HPP_
