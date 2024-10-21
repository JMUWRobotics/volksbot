// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:srv/SickScanExitSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__SICK_SCAN_EXIT_SRV__BUILDER_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__SICK_SCAN_EXIT_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/srv/detail/sick_scan_exit_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::SickScanExitSrv_Request>()
{
  return ::sick_scan_xd::srv::SickScanExitSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace sick_scan_xd


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_SickScanExitSrv_Response_success
{
public:
  Init_SickScanExitSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sick_scan_xd::srv::SickScanExitSrv_Response success(::sick_scan_xd::srv::SickScanExitSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::SickScanExitSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::SickScanExitSrv_Response>()
{
  return sick_scan_xd::srv::builder::Init_SickScanExitSrv_Response_success();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__SICK_SCAN_EXIT_SRV__BUILDER_HPP_
