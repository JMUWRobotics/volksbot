// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/RadarObject.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/radar_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_RadarObject_contour_points
{
public:
  explicit Init_RadarObject_contour_points(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::RadarObject contour_points(::sick_scan_xd::msg::RadarObject::_contour_points_type arg)
  {
    msg_.contour_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_object_box_size
{
public:
  explicit Init_RadarObject_object_box_size(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_contour_points object_box_size(::sick_scan_xd::msg::RadarObject::_object_box_size_type arg)
  {
    msg_.object_box_size = std::move(arg);
    return Init_RadarObject_contour_points(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_object_box_center
{
public:
  explicit Init_RadarObject_object_box_center(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_object_box_size object_box_center(::sick_scan_xd::msg::RadarObject::_object_box_center_type arg)
  {
    msg_.object_box_center = std::move(arg);
    return Init_RadarObject_object_box_size(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_bounding_box_size
{
public:
  explicit Init_RadarObject_bounding_box_size(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_object_box_center bounding_box_size(::sick_scan_xd::msg::RadarObject::_bounding_box_size_type arg)
  {
    msg_.bounding_box_size = std::move(arg);
    return Init_RadarObject_object_box_center(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_bounding_box_center
{
public:
  explicit Init_RadarObject_bounding_box_center(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_bounding_box_size bounding_box_center(::sick_scan_xd::msg::RadarObject::_bounding_box_center_type arg)
  {
    msg_.bounding_box_center = std::move(arg);
    return Init_RadarObject_bounding_box_size(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_velocity
{
public:
  explicit Init_RadarObject_velocity(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_bounding_box_center velocity(::sick_scan_xd::msg::RadarObject::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_RadarObject_bounding_box_center(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_last_seen
{
public:
  explicit Init_RadarObject_last_seen(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_velocity last_seen(::sick_scan_xd::msg::RadarObject::_last_seen_type arg)
  {
    msg_.last_seen = std::move(arg);
    return Init_RadarObject_velocity(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_tracking_time
{
public:
  explicit Init_RadarObject_tracking_time(::sick_scan_xd::msg::RadarObject & msg)
  : msg_(msg)
  {}
  Init_RadarObject_last_seen tracking_time(::sick_scan_xd::msg::RadarObject::_tracking_time_type arg)
  {
    msg_.tracking_time = std::move(arg);
    return Init_RadarObject_last_seen(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

class Init_RadarObject_id
{
public:
  Init_RadarObject_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarObject_tracking_time id(::sick_scan_xd::msg::RadarObject::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RadarObject_tracking_time(msg_);
  }

private:
  ::sick_scan_xd::msg::RadarObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::RadarObject>()
{
  return sick_scan_xd::msg::builder::Init_RadarObject_id();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_OBJECT__BUILDER_HPP_
