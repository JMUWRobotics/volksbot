// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:srv/LIDoutputstateSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__LI_DOUTPUTSTATE_SRV__STRUCT_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__LI_DOUTPUTSTATE_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Request __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LIDoutputstateSrv_Request_
{
  using Type = LIDoutputstateSrv_Request_<ContainerAllocator>;

  explicit LIDoutputstateSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->active = false;
    }
  }

  explicit LIDoutputstateSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->active = false;
    }
  }

  // field types and members
  using _active_type =
    bool;
  _active_type active;

  // setters for named parameter idiom
  Type & set__active(
    const bool & _arg)
  {
    this->active = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Request
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Request
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LIDoutputstateSrv_Request_ & other) const
  {
    if (this->active != other.active) {
      return false;
    }
    return true;
  }
  bool operator!=(const LIDoutputstateSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LIDoutputstateSrv_Request_

// alias to use template instance with default allocator
using LIDoutputstateSrv_Request =
  sick_scan_xd::srv::LIDoutputstateSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Response __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LIDoutputstateSrv_Response_
{
  using Type = LIDoutputstateSrv_Response_<ContainerAllocator>;

  explicit LIDoutputstateSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit LIDoutputstateSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Response
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__LIDoutputstateSrv_Response
    std::shared_ptr<sick_scan_xd::srv::LIDoutputstateSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LIDoutputstateSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const LIDoutputstateSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LIDoutputstateSrv_Response_

// alias to use template instance with default allocator
using LIDoutputstateSrv_Response =
  sick_scan_xd::srv::LIDoutputstateSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd

namespace sick_scan_xd
{

namespace srv
{

struct LIDoutputstateSrv
{
  using Request = sick_scan_xd::srv::LIDoutputstateSrv_Request;
  using Response = sick_scan_xd::srv::LIDoutputstateSrv_Response;
};

}  // namespace srv

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__LI_DOUTPUTSTATE_SRV__STRUCT_HPP_
