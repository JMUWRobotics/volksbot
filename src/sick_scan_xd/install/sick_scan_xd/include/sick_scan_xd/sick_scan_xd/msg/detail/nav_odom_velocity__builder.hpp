// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/NAVOdomVelocity.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/nav_odom_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_NAVOdomVelocity_coordbase
{
public:
  explicit Init_NAVOdomVelocity_coordbase(::sick_scan_xd::msg::NAVOdomVelocity & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::NAVOdomVelocity coordbase(::sick_scan_xd::msg::NAVOdomVelocity::_coordbase_type arg)
  {
    msg_.coordbase = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVOdomVelocity msg_;
};

class Init_NAVOdomVelocity_timestamp
{
public:
  explicit Init_NAVOdomVelocity_timestamp(::sick_scan_xd::msg::NAVOdomVelocity & msg)
  : msg_(msg)
  {}
  Init_NAVOdomVelocity_coordbase timestamp(::sick_scan_xd::msg::NAVOdomVelocity::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_NAVOdomVelocity_coordbase(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVOdomVelocity msg_;
};

class Init_NAVOdomVelocity_omega
{
public:
  explicit Init_NAVOdomVelocity_omega(::sick_scan_xd::msg::NAVOdomVelocity & msg)
  : msg_(msg)
  {}
  Init_NAVOdomVelocity_timestamp omega(::sick_scan_xd::msg::NAVOdomVelocity::_omega_type arg)
  {
    msg_.omega = std::move(arg);
    return Init_NAVOdomVelocity_timestamp(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVOdomVelocity msg_;
};

class Init_NAVOdomVelocity_vel_y
{
public:
  explicit Init_NAVOdomVelocity_vel_y(::sick_scan_xd::msg::NAVOdomVelocity & msg)
  : msg_(msg)
  {}
  Init_NAVOdomVelocity_omega vel_y(::sick_scan_xd::msg::NAVOdomVelocity::_vel_y_type arg)
  {
    msg_.vel_y = std::move(arg);
    return Init_NAVOdomVelocity_omega(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVOdomVelocity msg_;
};

class Init_NAVOdomVelocity_vel_x
{
public:
  Init_NAVOdomVelocity_vel_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NAVOdomVelocity_vel_y vel_x(::sick_scan_xd::msg::NAVOdomVelocity::_vel_x_type arg)
  {
    msg_.vel_x = std::move(arg);
    return Init_NAVOdomVelocity_vel_y(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVOdomVelocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::NAVOdomVelocity>()
{
  return sick_scan_xd::msg::builder::Init_NAVOdomVelocity_vel_x();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_ODOM_VELOCITY__BUILDER_HPP_
