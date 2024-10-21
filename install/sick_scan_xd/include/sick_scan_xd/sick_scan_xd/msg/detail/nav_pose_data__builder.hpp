// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/NAVPoseData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/nav_pose_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_NAVPoseData_pose_yaw
{
public:
  explicit Init_NAVPoseData_pose_yaw(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::NAVPoseData pose_yaw(::sick_scan_xd::msg::NAVPoseData::_pose_yaw_type arg)
  {
    msg_.pose_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_pose_y
{
public:
  explicit Init_NAVPoseData_pose_y(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_pose_yaw pose_y(::sick_scan_xd::msg::NAVPoseData::_pose_y_type arg)
  {
    msg_.pose_y = std::move(arg);
    return Init_NAVPoseData_pose_yaw(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_pose_x
{
public:
  explicit Init_NAVPoseData_pose_x(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_pose_y pose_x(::sick_scan_xd::msg::NAVPoseData::_pose_x_type arg)
  {
    msg_.pose_x = std::move(arg);
    return Init_NAVPoseData_pose_y(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_pose_valid
{
public:
  explicit Init_NAVPoseData_pose_valid(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_pose_x pose_valid(::sick_scan_xd::msg::NAVPoseData::_pose_valid_type arg)
  {
    msg_.pose_valid = std::move(arg);
    return Init_NAVPoseData_pose_x(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_quant_used_reflectors
{
public:
  explicit Init_NAVPoseData_quant_used_reflectors(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_pose_valid quant_used_reflectors(::sick_scan_xd::msg::NAVPoseData::_quant_used_reflectors_type arg)
  {
    msg_.quant_used_reflectors = std::move(arg);
    return Init_NAVPoseData_pose_valid(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_info_state
{
public:
  explicit Init_NAVPoseData_info_state(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_quant_used_reflectors info_state(::sick_scan_xd::msg::NAVPoseData::_info_state_type arg)
  {
    msg_.info_state = std::move(arg);
    return Init_NAVPoseData_quant_used_reflectors(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_nav_mode
{
public:
  explicit Init_NAVPoseData_nav_mode(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_info_state nav_mode(::sick_scan_xd::msg::NAVPoseData::_nav_mode_type arg)
  {
    msg_.nav_mode = std::move(arg);
    return Init_NAVPoseData_info_state(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_mean_dev
{
public:
  explicit Init_NAVPoseData_mean_dev(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_nav_mode mean_dev(::sick_scan_xd::msg::NAVPoseData::_mean_dev_type arg)
  {
    msg_.mean_dev = std::move(arg);
    return Init_NAVPoseData_nav_mode(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_timestamp
{
public:
  explicit Init_NAVPoseData_timestamp(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_mean_dev timestamp(::sick_scan_xd::msg::NAVPoseData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_NAVPoseData_mean_dev(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_output_mode
{
public:
  explicit Init_NAVPoseData_output_mode(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_timestamp output_mode(::sick_scan_xd::msg::NAVPoseData::_output_mode_type arg)
  {
    msg_.output_mode = std::move(arg);
    return Init_NAVPoseData_timestamp(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_opt_pose_data_valid
{
public:
  explicit Init_NAVPoseData_opt_pose_data_valid(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_output_mode opt_pose_data_valid(::sick_scan_xd::msg::NAVPoseData::_opt_pose_data_valid_type arg)
  {
    msg_.opt_pose_data_valid = std::move(arg);
    return Init_NAVPoseData_output_mode(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_phi
{
public:
  explicit Init_NAVPoseData_phi(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_opt_pose_data_valid phi(::sick_scan_xd::msg::NAVPoseData::_phi_type arg)
  {
    msg_.phi = std::move(arg);
    return Init_NAVPoseData_opt_pose_data_valid(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_y
{
public:
  explicit Init_NAVPoseData_y(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_phi y(::sick_scan_xd::msg::NAVPoseData::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NAVPoseData_phi(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_x
{
public:
  explicit Init_NAVPoseData_x(::sick_scan_xd::msg::NAVPoseData & msg)
  : msg_(msg)
  {}
  Init_NAVPoseData_y x(::sick_scan_xd::msg::NAVPoseData::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NAVPoseData_y(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

class Init_NAVPoseData_header
{
public:
  Init_NAVPoseData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NAVPoseData_x header(::sick_scan_xd::msg::NAVPoseData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NAVPoseData_x(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVPoseData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::NAVPoseData>()
{
  return sick_scan_xd::msg::builder::Init_NAVPoseData_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_POSE_DATA__BUILDER_HPP_
