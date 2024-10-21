// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderDeviceBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarPreHeaderDeviceBlock_bcontaminationerror
{
public:
  explicit Init_RadarPreHeaderDeviceBlock_bcontaminationerror(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarPreHeaderDeviceBlock bcontaminationerror(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock::_bcontaminationerror_type arg)
  {
    msg_.bcontaminationerror = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderDeviceBlock msg_;
};

class Init_RadarPreHeaderDeviceBlock_bcontaminationwarning
{
public:
  explicit Init_RadarPreHeaderDeviceBlock_bcontaminationwarning(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderDeviceBlock_bcontaminationerror bcontaminationwarning(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock::_bcontaminationwarning_type arg)
  {
    msg_.bcontaminationwarning = std::move(arg);
    return Init_RadarPreHeaderDeviceBlock_bcontaminationerror(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderDeviceBlock msg_;
};

class Init_RadarPreHeaderDeviceBlock_bdeviceerror
{
public:
  explicit Init_RadarPreHeaderDeviceBlock_bdeviceerror(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderDeviceBlock_bcontaminationwarning bdeviceerror(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock::_bdeviceerror_type arg)
  {
    msg_.bdeviceerror = std::move(arg);
    return Init_RadarPreHeaderDeviceBlock_bcontaminationwarning(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderDeviceBlock msg_;
};

class Init_RadarPreHeaderDeviceBlock_udiserialno
{
public:
  explicit Init_RadarPreHeaderDeviceBlock_udiserialno(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeaderDeviceBlock_bdeviceerror udiserialno(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock::_udiserialno_type arg)
  {
    msg_.udiserialno = std::move(arg);
    return Init_RadarPreHeaderDeviceBlock_bdeviceerror(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderDeviceBlock msg_;
};

class Init_RadarPreHeaderDeviceBlock_uiident
{
public:
  Init_RadarPreHeaderDeviceBlock_uiident()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarPreHeaderDeviceBlock_udiserialno uiident(::sick_scan_xd::msg::RadarPreHeaderDeviceBlock::_uiident_type arg)
  {
    msg_.uiident = std::move(arg);
    return Init_RadarPreHeaderDeviceBlock_udiserialno(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderDeviceBlock msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarPreHeaderDeviceBlock>()
{
  return sick_scan_xd::msg::builder::Init_RadarPreHeaderDeviceBlock_uiident();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__BUILDER_HPP_
