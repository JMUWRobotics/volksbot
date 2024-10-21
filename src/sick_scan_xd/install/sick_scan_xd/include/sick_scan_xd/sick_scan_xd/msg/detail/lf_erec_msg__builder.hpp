// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/LFErecMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/lf_erec_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_LFErecMsg_fields
{
public:
  explicit Init_LFErecMsg_fields(::sick_scan_xd::msg::LFErecMsg & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::LFErecMsg fields(::sick_scan_xd::msg::LFErecMsg::_fields_type arg)
  {
    msg_.fields = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecMsg msg_;
};

class Init_LFErecMsg_fields_number
{
public:
  explicit Init_LFErecMsg_fields_number(::sick_scan_xd::msg::LFErecMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecMsg_fields fields_number(::sick_scan_xd::msg::LFErecMsg::_fields_number_type arg)
  {
    msg_.fields_number = std::move(arg);
    return Init_LFErecMsg_fields(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecMsg msg_;
};

class Init_LFErecMsg_header
{
public:
  Init_LFErecMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LFErecMsg_fields_number header(::sick_scan_xd::msg::LFErecMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LFErecMsg_fields_number(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::LFErecMsg>()
{
  return sick_scan_xd::msg::builder::Init_LFErecMsg_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_MSG__BUILDER_HPP_
