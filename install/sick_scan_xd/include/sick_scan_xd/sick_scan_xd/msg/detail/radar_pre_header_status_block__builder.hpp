// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderStatusBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarPreHeaderStatusBlock_uioutputs
{
public:
  explicit Init_RadarPreHeaderStatusBlock_uioutputs(::sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock uioutputs(::sick_scan_xd::msg::RadarPreHeaderStatusBlock::_uioutputs_type arg)
  {
    msg_.uioutputs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock msg_;
};

class Init_RadarPreHeaderStatusBlock_uiinputs
{
public:
  explicit Init_RadarPreHeaderStatusBlock_uiinputs(::sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderStatusBlock_uioutputs uiinputs(::sick_scan_xd::msg::RadarPreHeaderStatusBlock::_uiinputs_type arg)
  {
    msg_.uiinputs = std::move(arg);
    return Init_RadarPreHeaderStatusBlock_uioutputs(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock msg_;
};

class Init_RadarPreHeaderStatusBlock_udisystemcounttransmit
{
public:
  explicit Init_RadarPreHeaderStatusBlock_udisystemcounttransmit(::sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderStatusBlock_uiinputs udisystemcounttransmit(::sick_scan_xd::msg::RadarPreHeaderStatusBlock::_udisystemcounttransmit_type arg)
  {
    msg_.udisystemcounttransmit = std::move(arg);
    return Init_RadarPreHeaderStatusBlock_uiinputs(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock msg_;
};

class Init_RadarPreHeaderStatusBlock_udisystemcountscan
{
public:
  explicit Init_RadarPreHeaderStatusBlock_udisystemcountscan(::sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderStatusBlock_udisystemcounttransmit udisystemcountscan(::sick_scan_xd::msg::RadarPreHeaderStatusBlock::_udisystemcountscan_type arg)
  {
    msg_.udisystemcountscan = std::move(arg);
    return Init_RadarPreHeaderStatusBlock_udisystemcounttransmit(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock msg_;
};

class Init_RadarPreHeaderStatusBlock_uicyclecount
{
public:
  explicit Init_RadarPreHeaderStatusBlock_uicyclecount(::sick_scan_xd::msg::RadarPreHeaderStatusBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderStatusBlock_udisystemcountscan uicyclecount(::sick_scan_xd::msg::RadarPreHeaderStatusBlock::_uicyclecount_type arg)
  {
    msg_.uicyclecount = std::move(arg);
    return Init_RadarPreHeaderStatusBlock_udisystemcountscan(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock msg_;
};

class Init_RadarPreHeaderStatusBlock_uitelegramcount
{
public:
  Init_RadarPreHeaderStatusBlock_uitelegramcount()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarPreHeaderStatusBlock_uicyclecount uitelegramcount(::sick_scan_xd::msg::RadarPreHeaderStatusBlock::_uitelegramcount_type arg)
  {
    msg_.uitelegramcount = std::move(arg);
    return Init_RadarPreHeaderStatusBlock_uicyclecount(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderStatusBlock msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarPreHeaderStatusBlock>()
{
  return sick_scan_xd::msg::builder::Init_RadarPreHeaderStatusBlock_uitelegramcount();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_STATUS_BLOCK__BUILDER_HPP_
