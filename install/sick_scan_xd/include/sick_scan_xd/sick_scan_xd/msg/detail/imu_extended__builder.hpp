// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/ImuExtended.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/imu_extended__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_ImuExtended_linear_acceleration_reliability
{
public:
  explicit Init_ImuExtended_linear_acceleration_reliability(::sick_scan_xd::msg::ImuExtended & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::ImuExtended linear_acceleration_reliability(::sick_scan_xd::msg::ImuExtended::_linear_acceleration_reliability_type arg)
  {
    msg_.linear_acceleration_reliability = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::ImuExtended msg_;
};

class Init_ImuExtended_angular_velocity_reliability
{
public:
  explicit Init_ImuExtended_angular_velocity_reliability(::sick_scan_xd::msg::ImuExtended & msg)
  : msg_(msg)
  {}
  Init_ImuExtended_linear_acceleration_reliability angular_velocity_reliability(::sick_scan_xd::msg::ImuExtended::_angular_velocity_reliability_type arg)
  {
    msg_.angular_velocity_reliability = std::move(arg);
    return Init_ImuExtended_linear_acceleration_reliability(msg_);
  }

private:
  ::sick_scan_xd::msg::ImuExtended msg_;
};

class Init_ImuExtended_quaternion_accuracy
{
public:
  explicit Init_ImuExtended_quaternion_accuracy(::sick_scan_xd::msg::ImuExtended & msg)
  : msg_(msg)
  {}
  Init_ImuExtended_angular_velocity_reliability quaternion_accuracy(::sick_scan_xd::msg::ImuExtended::_quaternion_accuracy_type arg)
  {
    msg_.quaternion_accuracy = std::move(arg);
    return Init_ImuExtended_angular_velocity_reliability(msg_);
  }

private:
  ::sick_scan_xd::msg::ImuExtended msg_;
};

class Init_ImuExtended_ticks
{
public:
  explicit Init_ImuExtended_ticks(::sick_scan_xd::msg::ImuExtended & msg)
  : msg_(msg)
  {}
  Init_ImuExtended_quaternion_accuracy ticks(::sick_scan_xd::msg::ImuExtended::_ticks_type arg)
  {
    msg_.ticks = std::move(arg);
    return Init_ImuExtended_quaternion_accuracy(msg_);
  }

private:
  ::sick_scan_xd::msg::ImuExtended msg_;
};

class Init_ImuExtended_imu
{
public:
  explicit Init_ImuExtended_imu(::sick_scan_xd::msg::ImuExtended & msg)
  : msg_(msg)
  {}
  Init_ImuExtended_ticks imu(::sick_scan_xd::msg::ImuExtended::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_ImuExtended_ticks(msg_);
  }

private:
  ::sick_scan_xd::msg::ImuExtended msg_;
};

class Init_ImuExtended_header
{
public:
  Init_ImuExtended_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuExtended_imu header(::sick_scan_xd::msg::ImuExtended::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImuExtended_imu(msg_);
  }

private:
  ::sick_scan_xd::msg::ImuExtended msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::ImuExtended>()
{
  return sick_scan_xd::msg::builder::Init_ImuExtended_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__BUILDER_HPP_
