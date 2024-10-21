// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/SickImu.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__SICK_IMU__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__SICK_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/sick_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_SickImu_linear_acceleration_reliability
{
public:
  explicit Init_SickImu_linear_acceleration_reliability(::sick_scan_xd::msg::SickImu & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::SickImu linear_acceleration_reliability(::sick_scan_xd::msg::SickImu::_linear_acceleration_reliability_type arg)
  {
    msg_.linear_acceleration_reliability = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::SickImu msg_;
};

class Init_SickImu_angular_velocity_reliability
{
public:
  explicit Init_SickImu_angular_velocity_reliability(::sick_scan_xd::msg::SickImu & msg)
  : msg_(msg)
  {}
  Init_SickImu_linear_acceleration_reliability angular_velocity_reliability(::sick_scan_xd::msg::SickImu::_angular_velocity_reliability_type arg)
  {
    msg_.angular_velocity_reliability = std::move(arg);
    return Init_SickImu_linear_acceleration_reliability(msg_);
  }

private:
  ::sick_scan_xd::msg::SickImu msg_;
};

class Init_SickImu_quaternion_accuracy
{
public:
  explicit Init_SickImu_quaternion_accuracy(::sick_scan_xd::msg::SickImu & msg)
  : msg_(msg)
  {}
  Init_SickImu_angular_velocity_reliability quaternion_accuracy(::sick_scan_xd::msg::SickImu::_quaternion_accuracy_type arg)
  {
    msg_.quaternion_accuracy = std::move(arg);
    return Init_SickImu_angular_velocity_reliability(msg_);
  }

private:
  ::sick_scan_xd::msg::SickImu msg_;
};

class Init_SickImu_ticks
{
public:
  explicit Init_SickImu_ticks(::sick_scan_xd::msg::SickImu & msg)
  : msg_(msg)
  {}
  Init_SickImu_quaternion_accuracy ticks(::sick_scan_xd::msg::SickImu::_ticks_type arg)
  {
    msg_.ticks = std::move(arg);
    return Init_SickImu_quaternion_accuracy(msg_);
  }

private:
  ::sick_scan_xd::msg::SickImu msg_;
};

class Init_SickImu_imu
{
public:
  explicit Init_SickImu_imu(::sick_scan_xd::msg::SickImu & msg)
  : msg_(msg)
  {}
  Init_SickImu_ticks imu(::sick_scan_xd::msg::SickImu::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_SickImu_ticks(msg_);
  }

private:
  ::sick_scan_xd::msg::SickImu msg_;
};

class Init_SickImu_header
{
public:
  Init_SickImu_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SickImu_imu header(::sick_scan_xd::msg::SickImu::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SickImu_imu(msg_);
  }

private:
  ::sick_scan_xd::msg::SickImu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::SickImu>()
{
  return sick_scan_xd::msg::builder::Init_SickImu_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__SICK_IMU__BUILDER_HPP_
