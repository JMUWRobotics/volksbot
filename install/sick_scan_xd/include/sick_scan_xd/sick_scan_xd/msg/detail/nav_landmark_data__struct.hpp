// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/NAVLandmarkData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__STRUCT_HPP_

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
// Member 'reflectors'
#include "sick_scan_xd/msg/detail/nav_reflector_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__NAVLandmarkData __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__NAVLandmarkData __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NAVLandmarkData_
{
  using Type = NAVLandmarkData_<ContainerAllocator>;

  explicit NAVLandmarkData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->landmark_filter = 0;
      this->num_reflectors = 0;
    }
  }

  explicit NAVLandmarkData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->landmark_filter = 0;
      this->num_reflectors = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _landmark_filter_type =
    uint8_t;
  _landmark_filter_type landmark_filter;
  using _num_reflectors_type =
    uint16_t;
  _num_reflectors_type num_reflectors;
  using _reflectors_type =
    std::vector<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>>;
  _reflectors_type reflectors;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__landmark_filter(
    const uint8_t & _arg)
  {
    this->landmark_filter = _arg;
    return *this;
  }
  Type & set__num_reflectors(
    const uint16_t & _arg)
  {
    this->num_reflectors = _arg;
    return *this;
  }
  Type & set__reflectors(
    const std::vector<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>> & _arg)
  {
    this->reflectors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__NAVLandmarkData
    std::shared_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__NAVLandmarkData
    std::shared_ptr<sick_scan_xd::msg::NAVLandmarkData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NAVLandmarkData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->landmark_filter != other.landmark_filter) {
      return false;
    }
    if (this->num_reflectors != other.num_reflectors) {
      return false;
    }
    if (this->reflectors != other.reflectors) {
      return false;
    }
    return true;
  }
  bool operator!=(const NAVLandmarkData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NAVLandmarkData_

// alias to use template instance with default allocator
using NAVLandmarkData =
  sick_scan_xd::msg::NAVLandmarkData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__STRUCT_HPP_
