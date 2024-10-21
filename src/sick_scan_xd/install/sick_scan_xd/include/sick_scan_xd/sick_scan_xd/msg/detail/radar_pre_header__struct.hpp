// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeader.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'radarpreheaderdeviceblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__struct.hpp"
// Member 'radarpreheaderstatusblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__struct.hpp"
// Member 'radarpreheadermeasurementparam1block'
#include "sick_scan_xd/msg/detail/radar_pre_header_measurement_param1_block__struct.hpp"
// Member 'radarpreheaderarrayencoderblock'
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeader __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__RadarPreHeader __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarPreHeader_
{
  using Type = RadarPreHeader_<ContainerAllocator>;

  explicit RadarPreHeader_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : radarpreheaderdeviceblock(_init),
    radarpreheaderstatusblock(_init),
    radarpreheadermeasurementparam1block(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uiversionno = 0;
    }
  }

  explicit RadarPreHeader_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : radarpreheaderdeviceblock(_alloc, _init),
    radarpreheaderstatusblock(_alloc, _init),
    radarpreheadermeasurementparam1block(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uiversionno = 0;
    }
  }

  // field types and members
  using _uiversionno_type =
    uint16_t;
  _uiversionno_type uiversionno;
  using _radarpreheaderdeviceblock_type =
    sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator>;
  _radarpreheaderdeviceblock_type radarpreheaderdeviceblock;
  using _radarpreheaderstatusblock_type =
    sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator>;
  _radarpreheaderstatusblock_type radarpreheaderstatusblock;
  using _radarpreheadermeasurementparam1block_type =
    sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>;
  _radarpreheadermeasurementparam1block_type radarpreheadermeasurementparam1block;
  using _radarpreheaderarrayencoderblock_type =
    std::vector<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>>;
  _radarpreheaderarrayencoderblock_type radarpreheaderarrayencoderblock;

  // setters for named parameter idiom
  Type & set__uiversionno(
    const uint16_t & _arg)
  {
    this->uiversionno = _arg;
    return *this;
  }
  Type & set__radarpreheaderdeviceblock(
    const sick_scan_xd::msg::RadarPreHeaderDeviceBlock_<ContainerAllocator> & _arg)
  {
    this->radarpreheaderdeviceblock = _arg;
    return *this;
  }
  Type & set__radarpreheaderstatusblock(
    const sick_scan_xd::msg::RadarPreHeaderStatusBlock_<ContainerAllocator> & _arg)
  {
    this->radarpreheaderstatusblock = _arg;
    return *this;
  }
  Type & set__radarpreheadermeasurementparam1block(
    const sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> & _arg)
  {
    this->radarpreheadermeasurementparam1block = _arg;
    return *this;
  }
  Type & set__radarpreheaderarrayencoderblock(
    const std::vector<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::RadarPreHeaderEncoderBlock_<ContainerAllocator>>> & _arg)
  {
    this->radarpreheaderarrayencoderblock = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeader
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__RadarPreHeader
    std::shared_ptr<sick_scan_xd::msg::RadarPreHeader_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarPreHeader_ & other) const
  {
    if (this->uiversionno != other.uiversionno) {
      return false;
    }
    if (this->radarpreheaderdeviceblock != other.radarpreheaderdeviceblock) {
      return false;
    }
    if (this->radarpreheaderstatusblock != other.radarpreheaderstatusblock) {
      return false;
    }
    if (this->radarpreheadermeasurementparam1block != other.radarpreheadermeasurementparam1block) {
      return false;
    }
    if (this->radarpreheaderarrayencoderblock != other.radarpreheaderarrayencoderblock) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarPreHeader_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarPreHeader_

// alias to use template instance with default allocator
using RadarPreHeader =
  sick_scan_xd::msg::RadarPreHeader_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__STRUCT_HPP_
