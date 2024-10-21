// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/NAVReflectorData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__NAVReflectorData __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__NAVReflectorData __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NAVReflectorData_
{
  using Type = NAVReflectorData_<ContainerAllocator>;

  explicit NAVReflectorData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cartesian_data_valid = 0;
      this->x = 0l;
      this->y = 0l;
      this->polar_data_valid = 0;
      this->dist = 0ul;
      this->phi = 0ul;
      this->opt_reflector_data_valid = 0;
      this->local_id = 0;
      this->global_id = 0;
      this->type = 0;
      this->sub_type = 0;
      this->quality = 0;
      this->timestamp = 0ul;
      this->size = 0;
      this->hit_count = 0;
      this->mean_echo = 0;
      this->start_index = 0;
      this->end_index = 0;
      this->pos_valid = 0;
      this->pos_x = 0.0f;
      this->pos_y = 0.0f;
    }
  }

  explicit NAVReflectorData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cartesian_data_valid = 0;
      this->x = 0l;
      this->y = 0l;
      this->polar_data_valid = 0;
      this->dist = 0ul;
      this->phi = 0ul;
      this->opt_reflector_data_valid = 0;
      this->local_id = 0;
      this->global_id = 0;
      this->type = 0;
      this->sub_type = 0;
      this->quality = 0;
      this->timestamp = 0ul;
      this->size = 0;
      this->hit_count = 0;
      this->mean_echo = 0;
      this->start_index = 0;
      this->end_index = 0;
      this->pos_valid = 0;
      this->pos_x = 0.0f;
      this->pos_y = 0.0f;
    }
  }

  // field types and members
  using _cartesian_data_valid_type =
    uint16_t;
  _cartesian_data_valid_type cartesian_data_valid;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _polar_data_valid_type =
    uint16_t;
  _polar_data_valid_type polar_data_valid;
  using _dist_type =
    uint32_t;
  _dist_type dist;
  using _phi_type =
    uint32_t;
  _phi_type phi;
  using _opt_reflector_data_valid_type =
    uint16_t;
  _opt_reflector_data_valid_type opt_reflector_data_valid;
  using _local_id_type =
    uint16_t;
  _local_id_type local_id;
  using _global_id_type =
    uint16_t;
  _global_id_type global_id;
  using _type_type =
    uint8_t;
  _type_type type;
  using _sub_type_type =
    uint16_t;
  _sub_type_type sub_type;
  using _quality_type =
    uint16_t;
  _quality_type quality;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;
  using _size_type =
    uint16_t;
  _size_type size;
  using _hit_count_type =
    uint16_t;
  _hit_count_type hit_count;
  using _mean_echo_type =
    uint16_t;
  _mean_echo_type mean_echo;
  using _start_index_type =
    uint16_t;
  _start_index_type start_index;
  using _end_index_type =
    uint16_t;
  _end_index_type end_index;
  using _pos_valid_type =
    int8_t;
  _pos_valid_type pos_valid;
  using _pos_x_type =
    float;
  _pos_x_type pos_x;
  using _pos_y_type =
    float;
  _pos_y_type pos_y;

  // setters for named parameter idiom
  Type & set__cartesian_data_valid(
    const uint16_t & _arg)
  {
    this->cartesian_data_valid = _arg;
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
  Type & set__polar_data_valid(
    const uint16_t & _arg)
  {
    this->polar_data_valid = _arg;
    return *this;
  }
  Type & set__dist(
    const uint32_t & _arg)
  {
    this->dist = _arg;
    return *this;
  }
  Type & set__phi(
    const uint32_t & _arg)
  {
    this->phi = _arg;
    return *this;
  }
  Type & set__opt_reflector_data_valid(
    const uint16_t & _arg)
  {
    this->opt_reflector_data_valid = _arg;
    return *this;
  }
  Type & set__local_id(
    const uint16_t & _arg)
  {
    this->local_id = _arg;
    return *this;
  }
  Type & set__global_id(
    const uint16_t & _arg)
  {
    this->global_id = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__sub_type(
    const uint16_t & _arg)
  {
    this->sub_type = _arg;
    return *this;
  }
  Type & set__quality(
    const uint16_t & _arg)
  {
    this->quality = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__size(
    const uint16_t & _arg)
  {
    this->size = _arg;
    return *this;
  }
  Type & set__hit_count(
    const uint16_t & _arg)
  {
    this->hit_count = _arg;
    return *this;
  }
  Type & set__mean_echo(
    const uint16_t & _arg)
  {
    this->mean_echo = _arg;
    return *this;
  }
  Type & set__start_index(
    const uint16_t & _arg)
  {
    this->start_index = _arg;
    return *this;
  }
  Type & set__end_index(
    const uint16_t & _arg)
  {
    this->end_index = _arg;
    return *this;
  }
  Type & set__pos_valid(
    const int8_t & _arg)
  {
    this->pos_valid = _arg;
    return *this;
  }
  Type & set__pos_x(
    const float & _arg)
  {
    this->pos_x = _arg;
    return *this;
  }
  Type & set__pos_y(
    const float & _arg)
  {
    this->pos_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__NAVReflectorData
    std::shared_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__NAVReflectorData
    std::shared_ptr<sick_scan_xd::msg::NAVReflectorData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NAVReflectorData_ & other) const
  {
    if (this->cartesian_data_valid != other.cartesian_data_valid) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->polar_data_valid != other.polar_data_valid) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    if (this->phi != other.phi) {
      return false;
    }
    if (this->opt_reflector_data_valid != other.opt_reflector_data_valid) {
      return false;
    }
    if (this->local_id != other.local_id) {
      return false;
    }
    if (this->global_id != other.global_id) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->sub_type != other.sub_type) {
      return false;
    }
    if (this->quality != other.quality) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    if (this->hit_count != other.hit_count) {
      return false;
    }
    if (this->mean_echo != other.mean_echo) {
      return false;
    }
    if (this->start_index != other.start_index) {
      return false;
    }
    if (this->end_index != other.end_index) {
      return false;
    }
    if (this->pos_valid != other.pos_valid) {
      return false;
    }
    if (this->pos_x != other.pos_x) {
      return false;
    }
    if (this->pos_y != other.pos_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const NAVReflectorData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NAVReflectorData_

// alias to use template instance with default allocator
using NAVReflectorData =
  sick_scan_xd::msg::NAVReflectorData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__STRUCT_HPP_
