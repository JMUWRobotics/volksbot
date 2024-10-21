// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:srv/SCrebootSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__S_CREBOOT_SRV__STRUCT_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__S_CREBOOT_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Request __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SCrebootSrv_Request_
{
  using Type = SCrebootSrv_Request_<ContainerAllocator>;

  explicit SCrebootSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SCrebootSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Request
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Request
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SCrebootSrv_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SCrebootSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SCrebootSrv_Request_

// alias to use template instance with default allocator
using SCrebootSrv_Request =
  sick_scan_xd::srv::SCrebootSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Response __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SCrebootSrv_Response_
{
  using Type = SCrebootSrv_Response_<ContainerAllocator>;

  explicit SCrebootSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SCrebootSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Response
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__SCrebootSrv_Response
    std::shared_ptr<sick_scan_xd::srv::SCrebootSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SCrebootSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SCrebootSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SCrebootSrv_Response_

// alias to use template instance with default allocator
using SCrebootSrv_Response =
  sick_scan_xd::srv::SCrebootSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd

namespace sick_scan_xd
{

namespace srv
{

struct SCrebootSrv
{
  using Request = sick_scan_xd::srv::SCrebootSrv_Request;
  using Response = sick_scan_xd::srv::SCrebootSrv_Response;
};

}  // namespace srv

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__S_CREBOOT_SRV__STRUCT_HPP_
