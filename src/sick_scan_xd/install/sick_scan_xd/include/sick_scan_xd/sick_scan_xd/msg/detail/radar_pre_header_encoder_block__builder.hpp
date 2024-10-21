// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarPreHeaderEncoderBlock_iencoderspeed
{
public:
  explicit Init_RadarPreHeaderEncoderBlock_iencoderspeed(::sick_scan_xd::msg::RadarPreHeaderEncoderBlock & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarPreHeaderEncoderBlock iencoderspeed(::sick_scan_xd::msg::RadarPreHeaderEncoderBlock::_iencoderspeed_type arg)
  {
    msg_.iencoderspeed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderEncoderBlock msg_;
};

class Init_RadarPreHeaderEncoderBlock_udiencoderpos
{
public:
  Init_RadarPreHeaderEncoderBlock_udiencoderpos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarPreHeaderEncoderBlock_iencoderspeed udiencoderpos(::sick_scan_xd::msg::RadarPreHeaderEncoderBlock::_udiencoderpos_type arg)
  {
    msg_.udiencoderpos = std::move(arg);
    return Init_RadarPreHeaderEncoderBlock_iencoderspeed(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarPreHeaderEncoderBlock msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarPreHeaderEncoderBlock>()
{
  return sick_scan_xd::msg::builder::Init_RadarPreHeaderEncoderBlock_udiencoderpos();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_ENCODER_BLOCK__BUILDER_HPP_
