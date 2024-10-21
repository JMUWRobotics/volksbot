// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/RadarScan.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/radar_scan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `radarpreheader`
#include "sick_scan_xd/msg/detail/radar_pre_header__functions.h"
// Member `targets`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"
// Member `objects`
#include "sick_scan_xd/msg/detail/radar_object__functions.h"

bool
sick_scan_xd__msg__RadarScan__init(sick_scan_xd__msg__RadarScan * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    sick_scan_xd__msg__RadarScan__fini(msg);
    return false;
  }
  // radarpreheader
  if (!sick_scan_xd__msg__RadarPreHeader__init(&msg->radarpreheader)) {
    sick_scan_xd__msg__RadarScan__fini(msg);
    return false;
  }
  // targets
  if (!sensor_msgs__msg__PointCloud2__init(&msg->targets)) {
    sick_scan_xd__msg__RadarScan__fini(msg);
    return false;
  }
  // objects
  if (!sick_scan_xd__msg__RadarObject__Sequence__init(&msg->objects, 0)) {
    sick_scan_xd__msg__RadarScan__fini(msg);
    return false;
  }
  return true;
}

void
sick_scan_xd__msg__RadarScan__fini(sick_scan_xd__msg__RadarScan * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // radarpreheader
  sick_scan_xd__msg__RadarPreHeader__fini(&msg->radarpreheader);
  // targets
  sensor_msgs__msg__PointCloud2__fini(&msg->targets);
  // objects
  sick_scan_xd__msg__RadarObject__Sequence__fini(&msg->objects);
}

bool
sick_scan_xd__msg__RadarScan__are_equal(const sick_scan_xd__msg__RadarScan * lhs, const sick_scan_xd__msg__RadarScan * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // radarpreheader
  if (!sick_scan_xd__msg__RadarPreHeader__are_equal(
      &(lhs->radarpreheader), &(rhs->radarpreheader)))
  {
    return false;
  }
  // targets
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->targets), &(rhs->targets)))
  {
    return false;
  }
  // objects
  if (!sick_scan_xd__msg__RadarObject__Sequence__are_equal(
      &(lhs->objects), &(rhs->objects)))
  {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__RadarScan__copy(
  const sick_scan_xd__msg__RadarScan * input,
  sick_scan_xd__msg__RadarScan * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // radarpreheader
  if (!sick_scan_xd__msg__RadarPreHeader__copy(
      &(input->radarpreheader), &(output->radarpreheader)))
  {
    return false;
  }
  // targets
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->targets), &(output->targets)))
  {
    return false;
  }
  // objects
  if (!sick_scan_xd__msg__RadarObject__Sequence__copy(
      &(input->objects), &(output->objects)))
  {
    return false;
  }
  return true;
}

sick_scan_xd__msg__RadarScan *
sick_scan_xd__msg__RadarScan__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarScan * msg = (sick_scan_xd__msg__RadarScan *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarScan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__RadarScan));
  bool success = sick_scan_xd__msg__RadarScan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__RadarScan__destroy(sick_scan_xd__msg__RadarScan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__RadarScan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__RadarScan__Sequence__init(sick_scan_xd__msg__RadarScan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarScan * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__RadarScan *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__RadarScan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__RadarScan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__RadarScan__fini(&data[i - 1]);
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
sick_scan_xd__msg__RadarScan__Sequence__fini(sick_scan_xd__msg__RadarScan__Sequence * array)
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
      sick_scan_xd__msg__RadarScan__fini(&array->data[i]);
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

sick_scan_xd__msg__RadarScan__Sequence *
sick_scan_xd__msg__RadarScan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarScan__Sequence * array = (sick_scan_xd__msg__RadarScan__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarScan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__RadarScan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__RadarScan__Sequence__destroy(sick_scan_xd__msg__RadarScan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__RadarScan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__RadarScan__Sequence__are_equal(const sick_scan_xd__msg__RadarScan__Sequence * lhs, const sick_scan_xd__msg__RadarScan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__RadarScan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__RadarScan__Sequence__copy(
  const sick_scan_xd__msg__RadarScan__Sequence * input,
  sick_scan_xd__msg__RadarScan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__RadarScan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__RadarScan * data =
      (sick_scan_xd__msg__RadarScan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__RadarScan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__RadarScan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__RadarScan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
