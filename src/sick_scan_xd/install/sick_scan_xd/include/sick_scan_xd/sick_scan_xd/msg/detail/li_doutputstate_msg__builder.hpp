// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/LIDoutputstateMsg.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/li_doutputstate_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_LIDoutputstateMsg_microsecond
{
public:
  explicit Init_LIDoutputstateMsg_microsecond(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::LIDoutputstateMsg microsecond(::sick_scan_xd::msg::LIDoutputstateMsg::_microsecond_type arg)
  {
    msg_.microsecond = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_second
{
public:
  explicit Init_LIDoutputstateMsg_second(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_microsecond second(::sick_scan_xd::msg::LIDoutputstateMsg::_second_type arg)
  {
    msg_.second = std::move(arg);
    return Init_LIDoutputstateMsg_microsecond(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_minute
{
public:
  explicit Init_LIDoutputstateMsg_minute(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_second minute(::sick_scan_xd::msg::LIDoutputstateMsg::_minute_type arg)
  {
    msg_.minute = std::move(arg);
    return Init_LIDoutputstateMsg_second(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_hour
{
public:
  explicit Init_LIDoutputstateMsg_hour(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_minute hour(::sick_scan_xd::msg::LIDoutputstateMsg::_hour_type arg)
  {
    msg_.hour = std::move(arg);
    return Init_LIDoutputstateMsg_minute(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_day
{
public:
  explicit Init_LIDoutputstateMsg_day(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_hour day(::sick_scan_xd::msg::LIDoutputstateMsg::_day_type arg)
  {
    msg_.day = std::move(arg);
    return Init_LIDoutputstateMsg_hour(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_month
{
public:
  explicit Init_LIDoutputstateMsg_month(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_day month(::sick_scan_xd::msg::LIDoutputstateMsg::_month_type arg)
  {
    msg_.month = std::move(arg);
    return Init_LIDoutputstateMsg_day(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_year
{
public:
  explicit Init_LIDoutputstateMsg_year(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_month year(::sick_scan_xd::msg::LIDoutputstateMsg::_year_type arg)
  {
    msg_.year = std::move(arg);
    return Init_LIDoutputstateMsg_month(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_time_state
{
public:
  explicit Init_LIDoutputstateMsg_time_state(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_year time_state(::sick_scan_xd::msg::LIDoutputstateMsg::_time_state_type arg)
  {
    msg_.time_state = std::move(arg);
    return Init_LIDoutputstateMsg_year(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_output_count
{
public:
  explicit Init_LIDoutputstateMsg_output_count(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_time_state output_count(::sick_scan_xd::msg::LIDoutputstateMsg::_output_count_type arg)
  {
    msg_.output_count = std::move(arg);
    return Init_LIDoutputstateMsg_time_state(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_output_state
{
public:
  explicit Init_LIDoutputstateMsg_output_state(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_output_count output_state(::sick_scan_xd::msg::LIDoutputstateMsg::_output_state_type arg)
  {
    msg_.output_state = std::move(arg);
    return Init_LIDoutputstateMsg_output_count(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_system_counter
{
public:
  explicit Init_LIDoutputstateMsg_system_counter(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_output_state system_counter(::sick_scan_xd::msg::LIDoutputstateMsg::_system_counter_type arg)
  {
    msg_.system_counter = std::move(arg);
    return Init_LIDoutputstateMsg_output_state(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_version_number
{
public:
  explicit Init_LIDoutputstateMsg_version_number(::sick_scan_xd::msg::LIDoutputstateMsg & msg)
  : msg_(msg)
  {}
  Init_LIDoutputstateMsg_system_counter version_number(::sick_scan_xd::msg::LIDoutputstateMsg::_version_number_type arg)
  {
    msg_.version_number = std::move(arg);
    return Init_LIDoutputstateMsg_system_counter(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

class Init_LIDoutputstateMsg_header
{
public:
  Init_LIDoutputstateMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LIDoutputstateMsg_version_number header(::sick_scan_xd::msg::LIDoutputstateMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LIDoutputstateMsg_version_number(msg_);
  }

private:
  ::sick_scan_xd::msg::LIDoutputstateMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::LIDoutputstateMsg>()
{
  return sick_scan_xd::msg::builder::Init_LIDoutputstateMsg_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__LI_DOUTPUTSTATE_MSG__BUILDER_HPP_
