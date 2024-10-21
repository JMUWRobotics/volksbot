// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/NAVLandmarkData.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/nav_landmark_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_NAVLandmarkData_reflectors
{
public:
  explicit Init_NAVLandmarkData_reflectors(::sick_scan_xd::msg::NAVLandmarkData & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::NAVLandmarkData reflectors(::sick_scan_xd::msg::NAVLandmarkData::_reflectors_type arg)
  {
    msg_.reflectors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVLandmarkData msg_;
};

class Init_NAVLandmarkData_num_reflectors
{
public:
  explicit Init_NAVLandmarkData_num_reflectors(::sick_scan_xd::msg::NAVLandmarkData & msg)
  : msg_(msg)
  {}
  Init_NAVLandmarkData_reflectors num_reflectors(::sick_scan_xd::msg::NAVLandmarkData::_num_reflectors_type arg)
  {
    msg_.num_reflectors = std::move(arg);
    return Init_NAVLandmarkData_reflectors(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVLandmarkData msg_;
};

class Init_NAVLandmarkData_landmark_filter
{
public:
  explicit Init_NAVLandmarkData_landmark_filter(::sick_scan_xd::msg::NAVLandmarkData & msg)
  : msg_(msg)
  {}
  Init_NAVLandmarkData_num_reflectors landmark_filter(::sick_scan_xd::msg::NAVLandmarkData::_landmark_filter_type arg)
  {
    msg_.landmark_filter = std::move(arg);
    return Init_NAVLandmarkData_num_reflectors(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVLandmarkData msg_;
};

class Init_NAVLandmarkData_header
{
public:
  Init_NAVLandmarkData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NAVLandmarkData_landmark_filter header(::sick_scan_xd::msg::NAVLandmarkData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NAVLandmarkData_landmark_filter(msg_);
  }

private:
  ::sick_scan_xd::msg::NAVLandmarkData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::NAVLandmarkData>()
{
  return sick_scan_xd::msg::builder::Init_NAVLandmarkData_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__NAV_LANDMARK_DATA__BUILDER_HPP_
