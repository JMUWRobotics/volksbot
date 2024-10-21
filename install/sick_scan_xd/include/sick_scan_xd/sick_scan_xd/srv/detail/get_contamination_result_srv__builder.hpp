// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:srv/GetContaminationResultSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__GET_CONTAMINATION_RESULT_SRV__BUILDER_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__GET_CONTAMINATION_RESULT_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/srv/detail/get_contamination_result_srv__struct.hpp"
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
auto build<::sick_scan_xd::srv::GetContaminationResultSrv_Request>()
{
  return ::sick_scan_xd::srv::GetContaminationResultSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace sick_scan_xd


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_GetContaminationResultSrv_Response_success
{
public:
  explicit Init_GetContaminationResultSrv_Response_success(::sick_scan_xd::srv::GetContaminationResultSrv_Response & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::srv::GetContaminationResultSrv_Response success(::sick_scan_xd::srv::GetContaminationResultSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::GetContaminationResultSrv_Response msg_;
};

class Init_GetContaminationResultSrv_Response_error
{
public:
  explicit Init_GetContaminationResultSrv_Response_error(::sick_scan_xd::srv::GetContaminationResultSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GetContaminationResultSrv_Response_success error(::sick_scan_xd::srv::GetContaminationResultSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_GetContaminationResultSrv_Response_success(msg_);
  }

private:
  ::sick_scan_xd::srv::GetContaminationResultSrv_Response msg_;
};

class Init_GetContaminationResultSrv_Response_warning
{
public:
  Init_GetContaminationResultSrv_Response_warning()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetContaminationResultSrv_Response_error warning(::sick_scan_xd::srv::GetContaminationResultSrv_Response::_warning_type arg)
  {
    msg_.warning = std::move(arg);
    return Init_GetContaminationResultSrv_Response_error(msg_);
  }

private:
  ::sick_scan_xd::srv::GetContaminationResultSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::GetContaminationResultSrv_Response>()
{
  return sick_scan_xd::srv::builder::Init_GetContaminationResultSrv_Response_warning();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__GET_CONTAMINATION_RESULT_SRV__BUILDER_HPP_
