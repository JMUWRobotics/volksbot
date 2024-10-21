// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sick_scan_xd:msg/SickLdmrsObjectArray.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT_ARRAY__BUILDER_HPP_
#define SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sick_scan_xd/msg/detail/sick_ldmrs_object_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sick_scan_xd
{

namespace msg
{

namespace builder
{

class Init_SickLdmrsObjectArray_objects
{
public:
  explicit Init_SickLdmrsObjectArray_objects(::sick_scan_xd::msg::SickLdmrsObjectArray & msg)
  : msg_(msg)
  {}
  ::sick_scan_xd::msg::SickLdmrsObjectArray objects(::sick_scan_xd::msg::SickLdmrsObjectArray::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObjectArray msg_;
};

class Init_SickLdmrsObjectArray_header
{
public:
  Init_SickLdmrsObjectArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SickLdmrsObjectArray_objects header(::sick_scan_xd::msg::SickLdmrsObjectArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SickLdmrsObjectArray_objects(msg_);
  }

private:
  ::sick_scan_xd::msg::SickLdmrsObjectArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sick_scan_xd::msg::SickLdmrsObjectArray>()
{
  return sick_scan_xd::msg::builder::Init_SickLdmrsObjectArray_header();
}

}  // namespace sick_scan_xd

#endif  // SICK_SCAN_XD__MSG__DETAIL__SICK_LDMRS_OBJECT_ARRAY__BUILDER_HPP_
