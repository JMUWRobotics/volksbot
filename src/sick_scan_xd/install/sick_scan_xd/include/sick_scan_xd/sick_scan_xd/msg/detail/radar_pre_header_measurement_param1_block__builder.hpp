// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderMeasurementParam1Block.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_pre_header_measurement_param1_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarPreHeaderMeasurementParam1Block_uinoiselevel
{
public:
  explicit Init_RadarPreHeaderMeasurementParam1Block_uinoiselevel(::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block uinoiselevel(::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block::_uinoiselevel_type arg)
  {
    msg_.uinoiselevel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block msg_;
};

class Init_RadarPreHeaderMeasurementParam1Block_uicycleduration
{
public:
  Init_RadarPreHeaderMeasurementParam1Block_uicycleduration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarPreHeaderMeasurementParam1Block_uinoiselevel uicycleduration(::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block::_uicycleduration_type arg)
  {
    msg_.uicycleduration = std::move(arg);
    return Init_RadarPreHeaderMeasurementParam1Block_uinoiselevel(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarPreHeaderMeasurementParam1Block>()
{
  return sick_scan_xd::msg::builder::Init_RadarPreHeaderMeasurementParam1Block_uicycleduration();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_MEASUREMENT_PARAM1_BLOCK__BUILDER_HPP_
