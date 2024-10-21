// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:srv/SCdevicestateSrv.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__SRV__DETAIL__S_CDEVICESTATE_SRV__BUILDER_HPP_
#define SICK_SCAN_XD__SRV__DETAIL__S_CDEVICESTATE_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/srv/detail/s_cdevicestate_srv__struct.hpp"
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
auto build<::sick_scan_xd::srv::SCdevicestateSrv_Request>()
{
  return ::sick_scan_xd::srv::SCdevicestateSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace sick_scan_xd


namespace sick_scan_xd
{

namespace srv
{

namespace builder
{

class Init_SCdevicestateSrv_Response_success
{
public:
  explicit Init_SCdevicestateSrv_Response_success(::sick_scan_xd::srv::SCdevicestateSrv_Response & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::srv::SCdevicestateSrv_Response success(::sick_scan_xd::srv::SCdevicestateSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::srv::SCdevicestateSrv_Response msg_;
};

class Init_SCdevicestateSrv_Response_state
{
public:
  Init_SCdevicestateSrv_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SCdevicestateSrv_Response_success state(::sick_scan_xd::srv::SCdevicestateSrv_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_SCdevicestateSrv_Response_success(msg_);
  }

private:
  ::sick_scan_xd::srv::SCdevicestateSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::srv::SCdevicestateSrv_Response>()
{
  return sick_scan_xd::srv::builder::Init_SCdevicestateSrv_Response_state();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__SRV__DETAIL__S_CDEVICESTATE_SRV__BUILDER_HPP_
