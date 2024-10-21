// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/NAVReflectorData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/nav_reflector_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_NAVReflectorData_pos_y
{
public:
  explicit Init_NAVReflectorData_pos_y(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::NAVReflectorData pos_y(::sick_scan_xd::msg::NAVReflectorData::_pos_y_type arg)
  {
    msg_.pos_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_pos_x
{
public:
  explicit Init_NAVReflectorData_pos_x(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_pos_y pos_x(::sick_scan_xd::msg::NAVReflectorData::_pos_x_type arg)
  {
    msg_.pos_x = std::move(arg);
    return Init_NAVReflectorData_pos_y(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_pos_valid
{
public:
  explicit Init_NAVReflectorData_pos_valid(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_pos_x pos_valid(::sick_scan_xd::msg::NAVReflectorData::_pos_valid_type arg)
  {
    msg_.pos_valid = std::move(arg);
    return Init_NAVReflectorData_pos_x(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_end_index
{
public:
  explicit Init_NAVReflectorData_end_index(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_pos_valid end_index(::sick_scan_xd::msg::NAVReflectorData::_end_index_type arg)
  {
    msg_.end_index = std::move(arg);
    return Init_NAVReflectorData_pos_valid(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_start_index
{
public:
  explicit Init_NAVReflectorData_start_index(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_end_index start_index(::sick_scan_xd::msg::NAVReflectorData::_start_index_type arg)
  {
    msg_.start_index = std::move(arg);
    return Init_NAVReflectorData_end_index(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_mean_echo
{
public:
  explicit Init_NAVReflectorData_mean_echo(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_start_index mean_echo(::sick_scan_xd::msg::NAVReflectorData::_mean_echo_type arg)
  {
    msg_.mean_echo = std::move(arg);
    return Init_NAVReflectorData_start_index(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_hit_count
{
public:
  explicit Init_NAVReflectorData_hit_count(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_mean_echo hit_count(::sick_scan_xd::msg::NAVReflectorData::_hit_count_type arg)
  {
    msg_.hit_count = std::move(arg);
    return Init_NAVReflectorData_mean_echo(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_size
{
public:
  explicit Init_NAVReflectorData_size(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_hit_count size(::sick_scan_xd::msg::NAVReflectorData::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_NAVReflectorData_hit_count(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_timestamp
{
public:
  explicit Init_NAVReflectorData_timestamp(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_size timestamp(::sick_scan_xd::msg::NAVReflectorData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_NAVReflectorData_size(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_quality
{
public:
  explicit Init_NAVReflectorData_quality(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_timestamp quality(::sick_scan_xd::msg::NAVReflectorData::_quality_type arg)
  {
    msg_.quality = std::move(arg);
    return Init_NAVReflectorData_timestamp(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_sub_type
{
public:
  explicit Init_NAVReflectorData_sub_type(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_quality sub_type(::sick_scan_xd::msg::NAVReflectorData::_sub_type_type arg)
  {
    msg_.sub_type = std::move(arg);
    return Init_NAVReflectorData_quality(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_type
{
public:
  explicit Init_NAVReflectorData_type(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_sub_type type(::sick_scan_xd::msg::NAVReflectorData::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_NAVReflectorData_sub_type(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_global_id
{
public:
  explicit Init_NAVReflectorData_global_id(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_type global_id(::sick_scan_xd::msg::NAVReflectorData::_global_id_type arg)
  {
    msg_.global_id = std::move(arg);
    return Init_NAVReflectorData_type(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_local_id
{
public:
  explicit Init_NAVReflectorData_local_id(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_global_id local_id(::sick_scan_xd::msg::NAVReflectorData::_local_id_type arg)
  {
    msg_.local_id = std::move(arg);
    return Init_NAVReflectorData_global_id(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_opt_reflector_data_valid
{
public:
  explicit Init_NAVReflectorData_opt_reflector_data_valid(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_local_id opt_reflector_data_valid(::sick_scan_xd::msg::NAVReflectorData::_opt_reflector_data_valid_type arg)
  {
    msg_.opt_reflector_data_valid = std::move(arg);
    return Init_NAVReflectorData_local_id(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_phi
{
public:
  explicit Init_NAVReflectorData_phi(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_opt_reflector_data_valid phi(::sick_scan_xd::msg::NAVReflectorData::_phi_type arg)
  {
    msg_.phi = std::move(arg);
    return Init_NAVReflectorData_opt_reflector_data_valid(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_dist
{
public:
  explicit Init_NAVReflectorData_dist(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_phi dist(::sick_scan_xd::msg::NAVReflectorData::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return Init_NAVReflectorData_phi(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_polar_data_valid
{
public:
  explicit Init_NAVReflectorData_polar_data_valid(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_dist polar_data_valid(::sick_scan_xd::msg::NAVReflectorData::_polar_data_valid_type arg)
  {
    msg_.polar_data_valid = std::move(arg);
    return Init_NAVReflectorData_dist(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_y
{
public:
  explicit Init_NAVReflectorData_y(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_polar_data_valid y(::sick_scan_xd::msg::NAVReflectorData::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NAVReflectorData_polar_data_valid(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_x
{
public:
  explicit Init_NAVReflectorData_x(::sick_scan_xd::msg::NAVReflectorData & msg)
  : msg_(msg)
  {}
  Init_NAVReflectorData_y x(::sick_scan_xd::msg::NAVReflectorData::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NAVReflectorData_y(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

class Init_NAVReflectorData_cartesian_data_valid
{
public:
  Init_NAVReflectorData_cartesian_data_valid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NAVReflectorData_x cartesian_data_valid(::sick_scan_xd::msg::NAVReflectorData::_cartesian_data_valid_type arg)
  {
    msg_.cartesian_data_valid = std::move(arg);
    return Init_NAVReflectorData_x(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVReflectorData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::NAVReflectorData>()
{
  return sick_scan_xd::msg::builder::Init_NAVReflectorData_cartesian_data_valid();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_REFLECTOR_DATA__BUILDER_HPP_
