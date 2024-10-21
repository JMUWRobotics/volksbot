// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sick_scan_xd:msg/RadarObject.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sick_scan_xd/msg/detail/radar_object__rosidl_typesupport_introspection_c.h"
#include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sick_scan_xd/msg/detail/radar_object__functions.h"
#include "sick_scan_xd/msg/detail/radar_object__struct.h"


// Include directives for member types
// Member `tracking_time`
// Member `last_seen`
#include "builtin_interfaces/msg/time.h"
// Member `tracking_time`
// Member `last_seen`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `velocity`
#include "geometry_msgs/msg/twist_with_covariance.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist_with_covariance__rosidl_typesupport_introspection_c.h"
// Member `bounding_box_center`
#include "geometry_msgs/msg/pose.h"
// Member `bounding_box_center`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `bounding_box_size`
// Member `object_box_size`
#include "geometry_msgs/msg/vector3.h"
// Member `bounding_box_size`
// Member `object_box_size`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `object_box_center`
#include "geometry_msgs/msg/pose_with_covariance.h"
// Member `object_box_center`
#include "geometry_msgs/msg/detail/pose_with_covariance__rosidl_typesupport_introspection_c.h"
// Member `contour_points`
#include "geometry_msgs/msg/point.h"
// Member `contour_points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sick_scan_xd__msg__RadarObject__init(message_memory);
}

void sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_fini_function(void * message_memory)
{
  sick_scan_xd__msg__RadarObject__fini(message_memory);
}

size_t sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__size_function__RadarObject__contour_points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__get_const_function__RadarObject__contour_points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__get_function__RadarObject__contour_points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__fetch_function__RadarObject__contour_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__get_const_function__RadarObject__contour_points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__assign_function__RadarObject__contour_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__get_function__RadarObject__contour_points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__resize_function__RadarObject__contour_points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[9] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracking_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, tracking_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_seen",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, last_seen),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_box_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, bounding_box_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_box_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, bounding_box_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_box_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, object_box_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_box_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, object_box_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "contour_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarObject, contour_points),  // bytes offset in struct
    NULL,  // default value
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__size_function__RadarObject__contour_points,  // size() function pointer
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__get_const_function__RadarObject__contour_points,  // get_const(index) function pointer
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__get_function__RadarObject__contour_points,  // get(index) function pointer
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__fetch_function__RadarObject__contour_points,  // fetch(index, &value) function pointer
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__assign_function__RadarObject__contour_points,  // assign(index, value) function pointer
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__resize_function__RadarObject__contour_points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_members = {
  "sick_scan_xd__msg",  // message namespace
  "RadarObject",  // message name
  9,  // number of fields
  sizeof(sick_scan_xd__msg__RadarObject),
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array,  // message members
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_init_function,  // function to initialize message memory (memory has to be allocated)
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_type_support_handle = {
  0,
  &sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, msg, RadarObject)() {
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, TwistWithCovariance)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseWithCovariance)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_type_support_handle.typesupport_identifier) {
    sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sick_scan_xd__msg__RadarObject__rosidl_typesupport_introspection_c__RadarObject_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
