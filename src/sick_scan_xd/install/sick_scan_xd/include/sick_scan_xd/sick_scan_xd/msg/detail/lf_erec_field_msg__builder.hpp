// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/LFErecFieldMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/lf_erec_field_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_LFErecFieldMsg_microsecond
{
public:
  explicit Init_LFErecFieldMsg_microsecond(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::LFErecFieldMsg microsecond(::sick_scan_xd::msg::LFErecFieldMsg::_microsecond_type arg)
  {
    msg_.microsecond = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_second
{
public:
  explicit Init_LFErecFieldMsg_second(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_microsecond second(::sick_scan_xd::msg::LFErecFieldMsg::_second_type arg)
  {
    msg_.second = std::move(arg);
    return Init_LFErecFieldMsg_microsecond(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_minute
{
public:
  explicit Init_LFErecFieldMsg_minute(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_second minute(::sick_scan_xd::msg::LFErecFieldMsg::_minute_type arg)
  {
    msg_.minute = std::move(arg);
    return Init_LFErecFieldMsg_second(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_hour
{
public:
  explicit Init_LFErecFieldMsg_hour(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_minute hour(::sick_scan_xd::msg::LFErecFieldMsg::_hour_type arg)
  {
    msg_.hour = std::move(arg);
    return Init_LFErecFieldMsg_minute(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_day
{
public:
  explicit Init_LFErecFieldMsg_day(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_hour day(::sick_scan_xd::msg::LFErecFieldMsg::_day_type arg)
  {
    msg_.day = std::move(arg);
    return Init_LFErecFieldMsg_hour(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_month
{
public:
  explicit Init_LFErecFieldMsg_month(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_day month(::sick_scan_xd::msg::LFErecFieldMsg::_month_type arg)
  {
    msg_.month = std::move(arg);
    return Init_LFErecFieldMsg_day(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_year
{
public:
  explicit Init_LFErecFieldMsg_year(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_month year(::sick_scan_xd::msg::LFErecFieldMsg::_year_type arg)
  {
    msg_.year = std::move(arg);
    return Init_LFErecFieldMsg_month(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_time_state
{
public:
  explicit Init_LFErecFieldMsg_time_state(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_year time_state(::sick_scan_xd::msg::LFErecFieldMsg::_time_state_type arg)
  {
    msg_.time_state = std::move(arg);
    return Init_LFErecFieldMsg_year(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_field_result_mrs
{
public:
  explicit Init_LFErecFieldMsg_field_result_mrs(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_time_state field_result_mrs(::sick_scan_xd::msg::LFErecFieldMsg::_field_result_mrs_type arg)
  {
    msg_.field_result_mrs = std::move(arg);
    return Init_LFErecFieldMsg_time_state(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_angle_scale_offset
{
public:
  explicit Init_LFErecFieldMsg_angle_scale_offset(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_field_result_mrs angle_scale_offset(::sick_scan_xd::msg::LFErecFieldMsg::_angle_scale_offset_type arg)
  {
    msg_.angle_scale_offset = std::move(arg);
    return Init_LFErecFieldMsg_field_result_mrs(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_angle_scale_factor
{
public:
  explicit Init_LFErecFieldMsg_angle_scale_factor(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_angle_scale_offset angle_scale_factor(::sick_scan_xd::msg::LFErecFieldMsg::_angle_scale_factor_type arg)
  {
    msg_.angle_scale_factor = std::move(arg);
    return Init_LFErecFieldMsg_angle_scale_offset(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_dist_scale_offset
{
public:
  explicit Init_LFErecFieldMsg_dist_scale_offset(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_angle_scale_factor dist_scale_offset(::sick_scan_xd::msg::LFErecFieldMsg::_dist_scale_offset_type arg)
  {
    msg_.dist_scale_offset = std::move(arg);
    return Init_LFErecFieldMsg_angle_scale_factor(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_dist_scale_factor
{
public:
  explicit Init_LFErecFieldMsg_dist_scale_factor(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_dist_scale_offset dist_scale_factor(::sick_scan_xd::msg::LFErecFieldMsg::_dist_scale_factor_type arg)
  {
    msg_.dist_scale_factor = std::move(arg);
    return Init_LFErecFieldMsg_dist_scale_offset(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_sys_count
{
public:
  explicit Init_LFErecFieldMsg_sys_count(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_dist_scale_factor sys_count(::sick_scan_xd::msg::LFErecFieldMsg::_sys_count_type arg)
  {
    msg_.sys_count = std::move(arg);
    return Init_LFErecFieldMsg_dist_scale_factor(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_field_index
{
public:
  explicit Init_LFErecFieldMsg_field_index(::sick_scan_xd::msg::LFErecFieldMsg & msg)
  : msg_(msg)
  {}
  Init_LFErecFieldMsg_sys_count field_index(::sick_scan_xd::msg::LFErecFieldMsg::_field_index_type arg)
  {
    msg_.field_index = std::move(arg);
    return Init_LFErecFieldMsg_sys_count(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

class Init_LFErecFieldMsg_version_number
{
public:
  Init_LFErecFieldMsg_version_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LFErecFieldMsg_field_index version_number(::sick_scan_xd::msg::LFErecFieldMsg::_version_number_type arg)
  {
    msg_.version_number = std::move(arg);
    return Init_LFErecFieldMsg_field_index(msg_);
  }

private:
  ::sick_scan_xd::msg::LFErecFieldMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::LFErecFieldMsg>()
{
  return sick_scan_xd::msg::builder::Init_LFErecFieldMsg_version_number();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__LF_EREC_FIELD_MSG__BUILDER_HPP_
