// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:msg/LFErecMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__STRUCT_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__STRUCT_HPP_

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
// Member 'fields'
#include "sick_scan_xd/msg/detail/lf_erec_field_msg__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__msg__LFErecMsg __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__msg__LFErecMsg __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LFErecMsg_
{
  using Type = LFErecMsg_<ContainerAllocator>;

  explicit LFErecMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fields_number = 0;
    }
  }

  explicit LFErecMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fields_number = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _fields_number_type =
    uint16_t;
  _fields_number_type fields_number;
  using _fields_type =
    std::vector<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>>;
  _fields_type fields;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__fields_number(
    const uint16_t & _arg)
  {
    this->fields_number = _arg;
    return *this;
  }
  Type & set__fields(
    const std::vector<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sick_scan_xd::msg::LFErecFieldMsg_<ContainerAllocator>>> & _arg)
  {
    this->fields = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::msg::LFErecMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::msg::LFErecMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::LFErecMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::msg::LFErecMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__msg__LFErecMsg
    std::shared_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__msg__LFErecMsg
    std::shared_ptr<sick_scan_xd::msg::LFErecMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LFErecMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->fields_number != other.fields_number) {
      return false;
    }
    if (this->fields != other.fields) {
      return false;
    }
    return true;
  }
  bool operator!=(const LFErecMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LFErecMsg_

// alias to use template instance with default allocator
using LFErecMsg =
  sick_scan_xd::msg::LFErecMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__STRUCT_HPP_
