// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/RadarScan.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_SCAN__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_SCAN__STRUCT_HPP_

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
// Member 'radarpreheader'
#include "sick_scan_xd/msg/detail/radar_pre_header__struct.hpp"
// Member 'targets'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"
// Member 'objects'
#include "sick_scan_xd/msg/detail/radar_object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__RadarScan __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__RadarScan __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarScan_
{
  using Type = RadarScan_<ContainerAllocator>;

  explicit RadarScan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    radarpreheader(_init),
    targets(_init)
  {
    (void)_init;
  }

  explicit RadarScan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    radarpreheader(_alloc, _init),
    targets(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _radarpreheader_type =
    sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>;
  _radarpreheader_type radarpreheader;
  using _targets_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _targets_type targets;
  using _objects_type =
    std::vector<sick_scan_xd::msg::RadarObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::RadarObject_<ContainerAllocator>>>;
  _objects_type objects;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__radarpreheader(
    const sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> & _arg)
  {
    this->radarpreheader = _arg;
    return *this;
  }
  Type & set__targets(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->targets = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<sick_scan_xd::msg::RadarObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::RadarObject_<ContainerAllocator>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::RadarScan_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::RadarScan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarScan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarScan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__RadarScan
    std::shared_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__RadarScan
    std::shared_ptr<sick_scan_xd::msg::RadarScan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarScan_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->radarpreheader != other.radarpreheader) {
      return false;
    }
    if (this->targets != other.targets) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarScan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarScan_

// alias to use template instance with default allocator
using RadarScan =
  sick_scan_xd::msg::RadarScan_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_SCAN__STRUCT_HPP_
