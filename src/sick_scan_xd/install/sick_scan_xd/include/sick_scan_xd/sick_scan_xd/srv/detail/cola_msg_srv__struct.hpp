// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sick_scan_xd:srv/ColaMsgSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__STRUCT_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Request __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ColaMsgSrv_Request_
{
  using Type = ColaMsgSrv_Request_<ContainerAllocator>;

  explicit ColaMsgSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request = "";
    }
  }

  explicit ColaMsgSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : request(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request = "";
    }
  }

  // field types and members
  using _request_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _request_type request;

  // setters for named parameter idiom
  Type & set__request(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Request
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Request
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColaMsgSrv_Request_ & other) const
  {
    if (this->request != other.request) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColaMsgSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColaMsgSrv_Request_

// alias to use template instance with default allocator
using ColaMsgSrv_Request =
  sick_scan_xd::srv::ColaMsgSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd


#ifndef _WIN32
# define DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Response __declspec(deprecated)
#endif

namespace sick_scan_xd
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ColaMsgSrv_Response_
{
  using Type = ColaMsgSrv_Response_<ContainerAllocator>;

  explicit ColaMsgSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit ColaMsgSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Response
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sick_scan_xd__srv__ColaMsgSrv_Response
    std::shared_ptr<sick_scan_xd::srv::ColaMsgSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColaMsgSrv_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColaMsgSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColaMsgSrv_Response_

// alias to use template instance with default allocator
using ColaMsgSrv_Response =
  sick_scan_xd::srv::ColaMsgSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sick_scan_xd

namespace sick_scan_xd
{

namespace srv
{

struct ColaMsgSrv
{
  using Request = sick_scan_xd::srv::ColaMsgSrv_Request;
  using Response = sick_scan_xd::srv::ColaMsgSrv_Response;
};

}  // namespace srv

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__STRUCT_HPP_
