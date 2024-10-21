// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:srv/ColaMsgSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__BUILDER_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/srv/detail/cola_msg_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_ColaMsgSrv_Request_request
{
public:
  Init_ColaMsgSrv_Request_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sick_scan_xd::srv::ColaMsgSrv_Request request(::sick_scan_xd::srv::ColaMsgSrv_Request::_request_type arg)
  {
    msg_.request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::ColaMsgSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::ColaMsgSrv_Request>()
{
  return sick_scan_xd::srv::builder::Init_ColaMsgSrv_Request_request();
}

}  // namespace sick_scan_xd


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_ColaMsgSrv_Response_response
{
public:
  Init_ColaMsgSrv_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sick_scan_xd::srv::ColaMsgSrv_Response response(::sick_scan_xd::srv::ColaMsgSrv_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::ColaMsgSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::ColaMsgSrv_Response>()
{
  return sick_scan_xd::srv::builder::Init_ColaMsgSrv_Response_response();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__COLA_MSG_SRV__BUILDER_HPP_
