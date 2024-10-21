// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/NAVPoseData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__STRUCT_HPP_

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
# define DEPRECATED__sick_scan_xd__msg__NAVPoseData __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__NAVPoseData __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NAVPoseData_
{
  using Type = NAVPoseData_<ContainerAllocator>;

  explicit NAVPoseData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0l;
      this->y = 0l;
      this->phi = 0ul;
      this->opt_pose_data_valid = 0;
      this->output_mode = 0;
      this->timestamp = 0ul;
      this->mean_dev = 0l;
      this->nav_mode = 0;
      this->info_state = 0ul;
      this->quant_used_reflectors = 0;
      this->pose_valid = 0;
      this->pose_x = 0.0f;
      this->pose_y = 0.0f;
      this->pose_yaw = 0.0f;
    }
  }

  explicit NAVPoseData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0l;
      this->y = 0l;
      this->phi = 0ul;
      this->opt_pose_data_valid = 0;
      this->output_mode = 0;
      this->timestamp = 0ul;
      this->mean_dev = 0l;
      this->nav_mode = 0;
      this->info_state = 0ul;
      this->quant_used_reflectors = 0;
      this->pose_valid = 0;
      this->pose_x = 0.0f;
      this->pose_y = 0.0f;
      this->pose_yaw = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _phi_type =
    uint32_t;
  _phi_type phi;
  using _opt_pose_data_valid_type =
    uint16_t;
  _opt_pose_data_valid_type opt_pose_data_valid;
  using _output_mode_type =
    uint8_t;
  _output_mode_type output_mode;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;
  using _mean_dev_type =
    int32_t;
  _mean_dev_type mean_dev;
  using _nav_mode_type =
    uint8_t;
  _nav_mode_type nav_mode;
  using _info_state_type =
    uint32_t;
  _info_state_type info_state;
  using _quant_used_reflectors_type =
    uint8_t;
  _quant_used_reflectors_type quant_used_reflectors;
  using _pose_valid_type =
    int8_t;
  _pose_valid_type pose_valid;
  using _pose_x_type =
    float;
  _pose_x_type pose_x;
  using _pose_y_type =
    float;
  _pose_y_type pose_y;
  using _pose_yaw_type =
    float;
  _pose_yaw_type pose_yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__phi(
    const uint32_t & _arg)
  {
    this->phi = _arg;
    return *this;
  }
  Type & set__opt_pose_data_valid(
    const uint16_t & _arg)
  {
    this->opt_pose_data_valid = _arg;
    return *this;
  }
  Type & set__output_mode(
    const uint8_t & _arg)
  {
    this->output_mode = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__mean_dev(
    const int32_t & _arg)
  {
    this->mean_dev = _arg;
    return *this;
  }
  Type & set__nav_mode(
    const uint8_t & _arg)
  {
    this->nav_mode = _arg;
    return *this;
  }
  Type & set__info_state(
    const uint32_t & _arg)
  {
    this->info_state = _arg;
    return *this;
  }
  Type & set__quant_used_reflectors(
    const uint8_t & _arg)
  {
    this->quant_used_reflectors = _arg;
    return *this;
  }
  Type & set__pose_valid(
    const int8_t & _arg)
  {
    this->pose_valid = _arg;
    return *this;
  }
  Type & set__pose_x(
    const float & _arg)
  {
    this->pose_x = _arg;
    return *this;
  }
  Type & set__pose_y(
    const float & _arg)
  {
    this->pose_y = _arg;
    return *this;
  }
  Type & set__pose_yaw(
    const float & _arg)
  {
    this->pose_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::NAVPoseData_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::NAVPoseData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVPoseData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVPoseData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__NAVPoseData
    std::shared_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__NAVPoseData
    std::shared_ptr<sick_scan_xd::msg::NAVPoseData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NAVPoseData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->phi != other.phi) {
      return false;
    }
    if (this->opt_pose_data_valid != other.opt_pose_data_valid) {
      return false;
    }
    if (this->output_mode != other.output_mode) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->mean_dev != other.mean_dev) {
      return false;
    }
    if (this->nav_mode != other.nav_mode) {
      return false;
    }
    if (this->info_state != other.info_state) {
      return false;
    }
    if (this->quant_used_reflectors != other.quant_used_reflectors) {
      return false;
    }
    if (this->pose_valid != other.pose_valid) {
      return false;
    }
    if (this->pose_x != other.pose_x) {
      return false;
    }
    if (this->pose_y != other.pose_y) {
      return false;
    }
    if (this->pose_yaw != other.pose_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const NAVPoseData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NAVPoseData_

// alias to use template instance with default allocator
using NAVPoseData =
  sick_scan_xd::msg::NAVPoseData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__STRUCT_HPP_
