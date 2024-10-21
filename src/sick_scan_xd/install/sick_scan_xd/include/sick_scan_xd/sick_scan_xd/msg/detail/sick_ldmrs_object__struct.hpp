// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/SickLdmrsObject.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'tracking_time'
// Member 'last_seen'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_with_covariance__struct.hpp"
// Member 'bounding_box_center'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'bounding_box_size'
// Member 'object_box_size'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'object_box_center'
#include "geometry_msgs/msg/detail/pose_with_covariance__struct.hpp"
// Member 'contour_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__SickLdmrsObject __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__SickLdmrsObject __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SickLdmrsObject_
{
  using Type = SickLdmrsObject_<ContainerAllocator>;

  explicit SickLdmrsObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tracking_time(_init),
    last_seen(_init),
    velocity(_init),
    bounding_box_center(_init),
    bounding_box_size(_init),
    object_box_center(_init),
    object_box_size(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  explicit SickLdmrsObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tracking_time(_alloc, _init),
    last_seen(_alloc, _init),
    velocity(_alloc, _init),
    bounding_box_center(_alloc, _init),
    bounding_box_size(_alloc, _init),
    object_box_center(_alloc, _init),
    object_box_size(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _tracking_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _tracking_time_type tracking_time;
  using _last_seen_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _last_seen_type last_seen;
  using _velocity_type =
    geometry_msgs::msg::TwistWithCovariance_<ContainerAllocator>;
  _velocity_type velocity;
  using _bounding_box_center_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _bounding_box_center_type bounding_box_center;
  using _bounding_box_size_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _bounding_box_size_type bounding_box_size;
  using _object_box_center_type =
    geometry_msgs::msg::PoseWithCovariance_<ContainerAllocator>;
  _object_box_center_type object_box_center;
  using _object_box_size_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _object_box_size_type object_box_size;
  using _contour_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _contour_points_type contour_points;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__tracking_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->tracking_time = _arg;
    return *this;
  }
  Type & set__last_seen(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->last_seen = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::TwistWithCovariance_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__bounding_box_center(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->bounding_box_center = _arg;
    return *this;
  }
  Type & set__bounding_box_size(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->bounding_box_size = _arg;
    return *this;
  }
  Type & set__object_box_center(
    const geometry_msgs::msg::PoseWithCovariance_<ContainerAllocator> & _arg)
  {
    this->object_box_center = _arg;
    return *this;
  }
  Type & set__object_box_size(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->object_box_size = _arg;
    return *this;
  }
  Type & set__contour_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->contour_points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__SickLdmrsObject
    std::shared_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__SickLdmrsObject
    std::shared_ptr<sick_scan_xd::msg::SickLdmrsObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SickLdmrsObject_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->tracking_time != other.tracking_time) {
      return false;
    }
    if (this->last_seen != other.last_seen) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->bounding_box_center != other.bounding_box_center) {
      return false;
    }
    if (this->bounding_box_size != other.bounding_box_size) {
      return false;
    }
    if (this->object_box_center != other.object_box_center) {
      return false;
    }
    if (this->object_box_size != other.object_box_size) {
      return false;
    }
    if (this->contour_points != other.contour_points) {
      return false;
    }
    return true;
  }
  bool operator!=(const SickLdmrsObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SickLdmrsObject_

// alias to use template instance with default allocator
using SickLdmrsObject =
  sick_scan_xd::msg::SickLdmrsObject_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT__STRUCT_HPP_
