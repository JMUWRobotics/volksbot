// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:srv/GetContaminationResultSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__GET_CONTAMINATION_RESULT_SRV__STRUCT_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__GET_CONTAMINATION_RESULT_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Request __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetContaminationResultSrv_Request_
{
  using Type = GetContaminationResultSrv_Request_<ContainerAllocator>;

  explicit GetContaminationResultSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetContaminationResultSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Request
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Request
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetContaminationResultSrv_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetContaminationResultSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetContaminationResultSrv_Request_

// alias to use template instance with default allocator
using GetContaminationResultSrv_Request =
  sick_scan_xd::srv::GetContaminationResultSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Response __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetContaminationResultSrv_Response_
{
  using Type = GetContaminationResultSrv_Response_<ContainerAllocator>;

  explicit GetContaminationResultSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->warning = 0;
      this->error = 0;
      this->success = false;
    }
  }

  explicit GetContaminationResultSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->warning = 0;
      this->error = 0;
      this->success = false;
    }
  }

  // field types and members
  using _warning_type =
    uint8_t;
  _warning_type warning;
  using _error_type =
    uint8_t;
  _error_type error;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__warning(
    const uint8_t & _arg)
  {
    this->warning = _arg;
    return *this;
  }
  Type & set__error(
    const uint8_t & _arg)
  {
    this->error = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Response
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__GetContaminationResultSrv_Response
    std::shared_ptr<sick_scan_xd::srv::GetContaminationResultSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetContaminationResultSrv_Response_ & other) const
  {
    if (this->warning != other.warning) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetContaminationResultSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetContaminationResultSrv_Response_

// alias to use template instance with default allocator
using GetContaminationResultSrv_Response =
  sick_scan_xd::srv::GetContaminationResultSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd

namespace sick_scan_xd
{

namespace srv
{

struct GetContaminationResultSrv
{
  using Request = sick_scan_xd::srv::GetContaminationResultSrv_Request;
  using Response = sick_scan_xd::srv::GetContaminationResultSrv_Response;
};

}  // namespace srv

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__GET_CONTAMINATION_RESULT_SRV__STRUCT_HPP_
