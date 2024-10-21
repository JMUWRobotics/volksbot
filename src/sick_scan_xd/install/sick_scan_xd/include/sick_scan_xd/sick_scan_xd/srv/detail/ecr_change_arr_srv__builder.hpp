// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:srv/ECRChangeArrSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__ECR_CHANGE_ARR_SRV__BUILDER_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__ECR_CHANGE_ARR_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/srv/detail/ecr_change_arr_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_ECRChangeArrSrv_Request_active
{
public:
  Init_ECRChangeArrSrv_Request_active()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sick_scan_xd::srv::ECRChangeArrSrv_Request active(::sick_scan_xd::srv::ECRChangeArrSrv_Request::_active_type arg)
  {
    msg_.active = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::ECRChangeArrSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::ECRChangeArrSrv_Request>()
{
  return sick_scan_xd::srv::builder::Init_ECRChangeArrSrv_Request_active();
}

}  // namespace sick_scan_xd


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_ECRChangeArrSrv_Response_success
{
public:
  Init_ECRChangeArrSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sick_scan_xd::srv::ECRChangeArrSrv_Response success(::sick_scan_xd::srv::ECRChangeArrSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::ECRChangeArrSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::ECRChangeArrSrv_Response>()
{
  return sick_scan_xd::srv::builder::Init_ECRChangeArrSrv_Response_success();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__ECR_CHANGE_ARR_SRV__BUILDER_HPP_
