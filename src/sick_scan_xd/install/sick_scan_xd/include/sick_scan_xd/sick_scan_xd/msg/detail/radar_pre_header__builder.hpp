// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeader.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_pre_header__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarPreHeader_radarpreheaderarrayencoderblock
{
public:
  explicit Init_RadarPreHeader_radarpreheaderarrayencoderblock(::sick_scan_xd::msg::RadarPreHeader & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarPreHeader radarpreheaderarrayencoderblock(::sick_scan_xd::msg::RadarPreHeader::_radarpreheaderarrayencoderblock_type arg)
  {
    msg_.radarpreheaderarrayencoderblock = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeader msg_;
};

class Init_RadarPreHeader_radarpreheadermeasurementparam1block
{
public:
  explicit Init_RadarPreHeader_radarpreheadermeasurementparam1block(::sick_scan_xd::msg::RadarPreHeader & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeader_radarpreheaderarrayencoderblock radarpreheadermeasurementparam1block(::sick_scan_xd::msg::RadarPreHeader::_radarpreheadermeasurementparam1block_type arg)
  {
    msg_.radarpreheadermeasurementparam1block = std::move(arg);
    return Init_RadarPreHeader_radarpreheaderarrayencoderblock(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeader msg_;
};

class Init_RadarPreHeader_radarpreheaderstatusblock
{
public:
  explicit Init_RadarPreHeader_radarpreheaderstatusblock(::sick_scan_xd::msg::RadarPreHeader & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeader_radarpreheadermeasurementparam1block radarpreheaderstatusblock(::sick_scan_xd::msg::RadarPreHeader::_radarpreheaderstatusblock_type arg)
  {
    msg_.radarpreheaderstatusblock = std::move(arg);
    return Init_RadarPreHeader_radarpreheadermeasurementparam1block(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeader msg_;
};

class Init_RadarPreHeader_radarpreheaderdeviceblock
{
public:
  explicit Init_RadarPreHeader_radarpreheaderdeviceblock(::sick_scan_xd::msg::RadarPreHeader & msg)
  : msg_(msg)
  {}
  Init_RadarPreHeader_radarpreheaderstatusblock radarpreheaderdeviceblock(::sick_scan_xd::msg::RadarPreHeader::_radarpreheaderdeviceblock_type arg)
  {
    msg_.radarpreheaderdeviceblock = std::move(arg);
    return Init_RadarPreHeader_radarpreheaderstatusblock(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeader msg_;
};

class Init_RadarPreHeader_uiversionno
{
public:
  Init_RadarPreHeader_uiversionno()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarPreHeader_radarpreheaderdeviceblock uiversionno(::sick_scan_xd::msg::RadarPreHeader::_uiversionno_type arg)
  {
    msg_.uiversionno = std::move(arg);
    return Init_RadarPreHeader_radarpreheaderdeviceblock(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeader msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarPreHeader>()
{
  return sick_scan_xd::msg::builder::Init_RadarPreHeader_uiversionno();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER__BUILDER_HPP_
