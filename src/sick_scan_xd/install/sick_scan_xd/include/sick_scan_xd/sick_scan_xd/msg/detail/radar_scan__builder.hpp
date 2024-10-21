// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarScan.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_SCAN__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_SCAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_scan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarScan_objects
{
public:
  explicit Init_RadarScan_objects(::sick_scan_xd::msg::RadarScan & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarScan objects(::sick_scan_xd::msg::RadarScan::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarScan msg_;
};

class Init_RadarScan_targets
{
public:
  explicit Init_RadarScan_targets(::sick_scan_xd::msg::RadarScan & msg)
  : msg_(msg)
  {}
  Init_RadarScan_objects targets(::sick_scan_xd::msg::RadarScan::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return Init_RadarScan_objects(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarScan msg_;
};

class Init_RadarScan_radarpreheader
{
public:
  explicit Init_RadarScan_radarpreheader(::sick_scan_xd::msg::RadarScan & msg)
  : msg_(msg)
  {}
  Init_RadarScan_targets radarpreheader(::sick_scan_xd::msg::RadarScan::_radarpreheader_type arg)
  {
    msg_.radarpreheader = std::move(arg);
    return Init_RadarScan_targets(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarScan msg_;
};

class Init_RadarScan_header
{
public:
  Init_RadarScan_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarScan_radarpreheader header(::sick_scan_xd::msg::RadarScan::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RadarScan_radarpreheader(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarScan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarScan>()
{
  return sick_scan_xd::msg::builder::Init_RadarScan_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_SCAN__BUILDER_HPP_
