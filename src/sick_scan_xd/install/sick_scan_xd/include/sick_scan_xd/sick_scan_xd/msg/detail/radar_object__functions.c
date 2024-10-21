// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/RadarObject.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/radar_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `tracking_time`
// Member `last_seen`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist_with_covariance__functions.h"
// Member `bounding_box_center`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `bounding_box_size`
// Member `object_box_size`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `object_box_center`
#include "geometry_msgs/msg/detail/pose_with_covariance__functions.h"
// Member `contour_points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
sick_scan_xd__msg__RadarObject__init(sick_scan_xd__msg__RadarObject * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // tracking_time
  if (!builtin_interfaces__msg__Time__init(&msg->tracking_time)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // last_seen
  if (!builtin_interfaces__msg__Time__init(&msg->last_seen)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistWithCovariance__init(&msg->velocity)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // bounding_box_center
  if (!geometry_msgs__msg__Pose__init(&msg->bounding_box_center)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // bounding_box_size
  if (!geometry_msgs__msg__Vector3__init(&msg->bounding_box_size)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // object_box_center
  if (!geometry_msgs__msg__PoseWithCovariance__init(&msg->object_box_center)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // object_box_size
  if (!geometry_msgs__msg__Vector3__init(&msg->object_box_size)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  // contour_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->contour_points, 0)) {
    sick_scan_xd__msg__RadarObject__fini(msg);
    return false;
  }
  return true;
}

void
sick_scan_xd__msg__RadarObject__fini(sick_scan_xd__msg__RadarObject * msg)
{
  if (!msg) {
    return;
  }
  // id
  // tracking_time
  builtin_interfaces__msg__Time__fini(&msg->tracking_time);
  // last_seen
  builtin_interfaces__msg__Time__fini(&msg->last_seen);
  // velocity
  geometry_msgs__msg__TwistWithCovariance__fini(&msg->velocity);
  // bounding_box_center
  geometry_msgs__msg__Pose__fini(&msg->bounding_box_center);
  // bounding_box_size
  geometry_msgs__msg__Vector3__fini(&msg->bounding_box_size);
  // object_box_center
  geometry_msgs__msg__PoseWithCovariance__fini(&msg->object_box_center);
  // object_box_size
  geometry_msgs__msg__Vector3__fini(&msg->object_box_size);
  // contour_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->contour_points);
}

bool
sick_scan_xd__msg__RadarObject__are_equal(const sick_scan_xd__msg__RadarObject * lhs, const sick_scan_xd__msg__RadarObject * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // tracking_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->tracking_time), &(rhs->tracking_time)))
  {
    return false;
  }
  // last_seen
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->last_seen), &(rhs->last_seen)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistWithCovariance__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // bounding_box_center
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->bounding_box_center), &(rhs->bounding_box_center)))
  {
    return false;
  }
  // bounding_box_size
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->bounding_box_size), &(rhs->bounding_box_size)))
  {
    return false;
  }
  // object_box_center
  if (!geometry_msgs__msg__PoseWithCovariance__are_equal(
      &(lhs->object_box_center), &(rhs->object_box_center)))
  {
    return false;
  }
  // object_box_size
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->object_box_size), &(rhs->object_box_size)))
  {
    return false;
  }
  // contour_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->contour_points), &(rhs->contour_points)))
  {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__RadarObject__copy(
  const sick_scan_xd__msg__RadarObject * input,
  sick_scan_xd__msg__RadarObject * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // tracking_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->tracking_time), &(output->tracking_time)))
  {
    return false;
  }
  // last_seen
  if (!builtin_interfaces__msg__Time__copy(
      &(input->last_seen), &(output->last_seen)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistWithCovariance__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // bounding_box_center
  if (!geometry_msgs__msg__Pose__copy(
      &(input->bounding_box_center), &(output->bounding_box_center)))
  {
    return false;
  }
  // bounding_box_size
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->bounding_box_size), &(output->bounding_box_size)))
  {
    return false;
  }
  // object_box_center
  if (!geometry_msgs__msg__PoseWithCovariance__copy(
      &(input->object_box_center), &(output->object_box_center)))
  {
    return false;
  }
  // object_box_size
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->object_box_size), &(output->object_box_size)))
  {
    return false;
  }
  // contour_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->contour_points), &(output->contour_points)))
  {
    return false;
  }
  return true;
}

sick_scan_xd__msg__RadarObject *
sick_scan_xd__msg__RadarObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarObject * msg = (sick_scan_xd__msg__RadarObject *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__RadarObject));
  bool success = sick_scan_xd__msg__RadarObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__RadarObject__destroy(sick_scan_xd__msg__RadarObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__RadarObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__RadarObject__Sequence__init(sick_scan_xd__msg__RadarObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarObject * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__RadarObject *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__RadarObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__RadarObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__RadarObject__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sick_scan_xd__msg__RadarObject__Sequence__fini(sick_scan_xd__msg__RadarObject__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sick_scan_xd__msg__RadarObject__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sick_scan_xd__msg__RadarObject__Sequence *
sick_scan_xd__msg__RadarObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarObject__Sequence * array = (sick_scan_xd__msg__RadarObject__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__RadarObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__RadarObject__Sequence__destroy(sick_scan_xd__msg__RadarObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__RadarObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__RadarObject__Sequence__are_equal(const sick_scan_xd__msg__RadarObject__Sequence * lhs, const sick_scan_xd__msg__RadarObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__RadarObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__RadarObject__Sequence__copy(
  const sick_scan_xd__msg__RadarObject__Sequence * input,
  sick_scan_xd__msg__RadarObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__RadarObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__RadarObject * data =
      (sick_scan_xd__msg__RadarObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__RadarObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__RadarObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__RadarObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
