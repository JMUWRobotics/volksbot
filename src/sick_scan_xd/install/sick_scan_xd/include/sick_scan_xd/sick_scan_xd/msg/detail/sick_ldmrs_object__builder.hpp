// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/SickLdmrsObject.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/sick_ldmrs_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_SickLdmrsObject_contour_points
{
public:
  explicit Init_SickLdmrsObject_contour_points(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::SickLdmrsObject contour_points(::sick_scan_xd::msg::SickLdmrsObject::_contour_points_type arg)
  {
    msg_.contour_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_object_box_size
{
public:
  explicit Init_SickLdmrsObject_object_box_size(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_contour_points object_box_size(::sick_scan_xd::msg::SickLdmrsObject::_object_box_size_type arg)
  {
    msg_.object_box_size = std::move(arg);
    return Init_SickLdmrsObject_contour_points(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_object_box_center
{
public:
  explicit Init_SickLdmrsObject_object_box_center(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_object_box_size object_box_center(::sick_scan_xd::msg::SickLdmrsObject::_object_box_center_type arg)
  {
    msg_.object_box_center = std::move(arg);
    return Init_SickLdmrsObject_object_box_size(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_bounding_box_size
{
public:
  explicit Init_SickLdmrsObject_bounding_box_size(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_object_box_center bounding_box_size(::sick_scan_xd::msg::SickLdmrsObject::_bounding_box_size_type arg)
  {
    msg_.bounding_box_size = std::move(arg);
    return Init_SickLdmrsObject_object_box_center(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_bounding_box_center
{
public:
  explicit Init_SickLdmrsObject_bounding_box_center(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_bounding_box_size bounding_box_center(::sick_scan_xd::msg::SickLdmrsObject::_bounding_box_center_type arg)
  {
    msg_.bounding_box_center = std::move(arg);
    return Init_SickLdmrsObject_bounding_box_size(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_velocity
{
public:
  explicit Init_SickLdmrsObject_velocity(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_bounding_box_center velocity(::sick_scan_xd::msg::SickLdmrsObject::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_SickLdmrsObject_bounding_box_center(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_last_seen
{
public:
  explicit Init_SickLdmrsObject_last_seen(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_velocity last_seen(::sick_scan_xd::msg::SickLdmrsObject::_last_seen_type arg)
  {
    msg_.last_seen = std::move(arg);
    return Init_SickLdmrsObject_velocity(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_tracking_time
{
public:
  explicit Init_SickLdmrsObject_tracking_time(::sick_scan_xd::msg::SickLdmrsObject & msg)
  : msg_(msg)
  {}
  Init_SickLdmrsObject_last_seen tracking_time(::sick_scan_xd::msg::SickLdmrsObject::_tracking_time_type arg)
  {
    msg_.tracking_time = std::move(arg);
    return Init_SickLdmrsObject_last_seen(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

class Init_SickLdmrsObject_id
{
public:
  Init_SickLdmrsObject_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SickLdmrsObject_tracking_time id(::sick_scan_xd::msg::SickLdmrsObject::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SickLdmrsObject_tracking_time(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::SickLdmrsObject>()
{
  return sick_scan_xd::msg::builder::Init_SickLdmrsObject_id();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT__BUILDER_HPP_
