// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/Encoder.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__ENCODER__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__ENCODER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/encoder__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_Encoder_enc_speed
{
public:
  explicit Init_Encoder_enc_speed(::sick_scan_xd::msg::Encoder & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::Encoder enc_speed(::sick_scan_xd::msg::Encoder::_enc_speed_type arg)
  {
    msg_.enc_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::Encoder msg_;
};

class Init_Encoder_enc_position
{
public:
  explicit Init_Encoder_enc_position(::sick_scan_xd::msg::Encoder & msg)
  : msg_(msg)
  {}
  Init_Encoder_enc_speed enc_position(::sick_scan_xd::msg::Encoder::_enc_position_type arg)
  {
    msg_.enc_position = std::move(arg);
    return Init_Encoder_enc_speed(msg_);
  }

private:
  ::sick_scan_xd::msg::Encoder msg_;
};

class Init_Encoder_header
{
public:
  Init_Encoder_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Encoder_enc_position header(::sick_scan_xd::msg::Encoder::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Encoder_enc_position(msg_);
  }

private:
  ::sick_scan_xd::msg::Encoder msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::Encoder>()
{
  return sick_scan_xd::msg::builder::Init_Encoder_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__ENCODER__BUILDER_HPP_
