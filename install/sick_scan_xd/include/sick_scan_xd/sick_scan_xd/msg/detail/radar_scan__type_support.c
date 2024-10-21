// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sick_scan_xd:msg/RadarScan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sick_scan_xd/msg/detail/radar_scan__rosidl_typesupport_introspection_c.h"
#include "sick_scan_xd/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sick_scan_xd/msg/detail/radar_scan__functions.h"
#include "sick_scan_xd/msg/detail/radar_scan__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `radarpreheader`
#include "sick_scan_xd/msg/radar_pre_header.h"
// Member `radarpreheader`
#include "sick_scan_xd/msg/detail/radar_pre_header__rosidl_typesupport_introspection_c.h"
// Member `targets`
#include "sensor_msgs/msg/point_cloud2.h"
// Member `targets`
#include "sensor_msgs/msg/detail/point_cloud2__rosidl_typesupport_introspection_c.h"
// Member `objects`
#include "sick_scan_xd/msg/radar_object.h"
// Member `objects`
#include "sick_scan_xd/msg/detail/radar_object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sick_scan_xd__msg__RadarScan__init(message_memory);
}

void sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_fini_function(void * message_memory)
{
  sick_scan_xd__msg__RadarScan__fini(message_memory);
}

size_t sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__size_function__RadarScan__objects(
  const void * untyped_member)
{
  const sick_scan_xd__msg__RadarObject__Sequence * member =
    (const sick_scan_xd__msg__RadarObject__Sequence *)(untyped_member);
  return member->size;
}

const void * sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__get_const_function__RadarScan__objects(
  const void * untyped_member, size_t index)
{
  const sick_scan_xd__msg__RadarObject__Sequence * member =
    (const sick_scan_xd__msg__RadarObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__get_function__RadarScan__objects(
  void * untyped_member, size_t index)
{
  sick_scan_xd__msg__RadarObject__Sequence * member =
    (sick_scan_xd__msg__RadarObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__fetch_function__RadarScan__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sick_scan_xd__msg__RadarObject * item =
    ((const sick_scan_xd__msg__RadarObject *)
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__get_const_function__RadarScan__objects(untyped_member, index));
  sick_scan_xd__msg__RadarObject * value =
    (sick_scan_xd__msg__RadarObject *)(untyped_value);
  *value = *item;
}

void sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__assign_function__RadarScan__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sick_scan_xd__msg__RadarObject * item =
    ((sick_scan_xd__msg__RadarObject *)
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__get_function__RadarScan__objects(untyped_member, index));
  const sick_scan_xd__msg__RadarObject * value =
    (const sick_scan_xd__msg__RadarObject *)(untyped_value);
  *item = *value;
}

bool sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__resize_function__RadarScan__objects(
  void * untyped_member, size_t size)
{
  sick_scan_xd__msg__RadarObject__Sequence * member =
    (sick_scan_xd__msg__RadarObject__Sequence *)(untyped_member);
  sick_scan_xd__msg__RadarObject__Sequence__fini(member);
  return sick_scan_xd__msg__RadarObject__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarScan, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radarpreheader",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarScan, radarpreheader),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "targets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarScan, targets),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sick_scan_xd__msg__RadarScan, objects),  // bytes offset in struct
    NULL,  // default value
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__size_function__RadarScan__objects,  // size() function pointer
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__get_const_function__RadarScan__objects,  // get_const(index) function pointer
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__get_function__RadarScan__objects,  // get(index) function pointer
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__fetch_function__RadarScan__objects,  // fetch(index, &value) function pointer
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__assign_function__RadarScan__objects,  // assign(index, value) function pointer
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__resize_function__RadarScan__objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_members = {
  "sick_scan_xd__msg",  // message namespace
  "RadarScan",  // message name
  4,  // number of fields
  sizeof(sick_scan_xd__msg__RadarScan),
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_member_array,  // message members
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_init_function,  // function to initialize message memory (memory has to be allocated)
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_type_support_handle = {
  0,
  &sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sick_scan_xd
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, msg, RadarScan)() {
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, msg, RadarPreHeader)();
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sick_scan_xd, msg, RadarObject)();
  if (!sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_type_support_handle.typesupport_identifier) {
    sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sick_scan_xd__msg__RadarScan__rosidl_typesupport_introspection_c__RadarScan_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
