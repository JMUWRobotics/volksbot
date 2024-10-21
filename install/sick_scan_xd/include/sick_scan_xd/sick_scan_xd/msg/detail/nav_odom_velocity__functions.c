// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/NAVOdomVelocity.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/nav_odom_velocity__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sick_scan_xd__msg__NAVOdomVelocity__init(sick_scan_xd__msg__NAVOdomVelocity * msg)
{
  if (!msg) {
    return false;
  }
  // vel_x
  // vel_y
  // omega
  // timestamp
  // coordbase
  return true;
}

void
sick_scan_xd__msg__NAVOdomVelocity__fini(sick_scan_xd__msg__NAVOdomVelocity * msg)
{
  if (!msg) {
    return;
  }
  // vel_x
  // vel_y
  // omega
  // timestamp
  // coordbase
}

bool
sick_scan_xd__msg__NAVOdomVelocity__are_equal(const sick_scan_xd__msg__NAVOdomVelocity * lhs, const sick_scan_xd__msg__NAVOdomVelocity * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vel_x
  if (lhs->vel_x != rhs->vel_x) {
    return false;
  }
  // vel_y
  if (lhs->vel_y != rhs->vel_y) {
    return false;
  }
  // omega
  if (lhs->omega != rhs->omega) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // coordbase
  if (lhs->coordbase != rhs->coordbase) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__NAVOdomVelocity__copy(
  const sick_scan_xd__msg__NAVOdomVelocity * input,
  sick_scan_xd__msg__NAVOdomVelocity * output)
{
  if (!input || !output) {
    return false;
  }
  // vel_x
  output->vel_x = input->vel_x;
  // vel_y
  output->vel_y = input->vel_y;
  // omega
  output->omega = input->omega;
  // timestamp
  output->timestamp = input->timestamp;
  // coordbase
  output->coordbase = input->coordbase;
  return true;
}

sick_scan_xd__msg__NAVOdomVelocity *
sick_scan_xd__msg__NAVOdomVelocity__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVOdomVelocity * msg = (sick_scan_xd__msg__NAVOdomVelocity *)allocator.allocate(sizeof(sick_scan_xd__msg__NAVOdomVelocity), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__NAVOdomVelocity));
  bool success = sick_scan_xd__msg__NAVOdomVelocity__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__NAVOdomVelocity__destroy(sick_scan_xd__msg__NAVOdomVelocity * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__NAVOdomVelocity__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__NAVOdomVelocity__Sequence__init(sick_scan_xd__msg__NAVOdomVelocity__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVOdomVelocity * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__NAVOdomVelocity *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__NAVOdomVelocity), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__NAVOdomVelocity__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__NAVOdomVelocity__fini(&data[i - 1]);
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
sick_scan_xd__msg__NAVOdomVelocity__Sequence__fini(sick_scan_xd__msg__NAVOdomVelocity__Sequence * array)
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
      sick_scan_xd__msg__NAVOdomVelocity__fini(&array->data[i]);
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

sick_scan_xd__msg__NAVOdomVelocity__Sequence *
sick_scan_xd__msg__NAVOdomVelocity__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVOdomVelocity__Sequence * array = (sick_scan_xd__msg__NAVOdomVelocity__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__NAVOdomVelocity__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__NAVOdomVelocity__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__NAVOdomVelocity__Sequence__destroy(sick_scan_xd__msg__NAVOdomVelocity__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__NAVOdomVelocity__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__NAVOdomVelocity__Sequence__are_equal(const sick_scan_xd__msg__NAVOdomVelocity__Sequence * lhs, const sick_scan_xd__msg__NAVOdomVelocity__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__NAVOdomVelocity__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__NAVOdomVelocity__Sequence__copy(
  const sick_scan_xd__msg__NAVOdomVelocity__Sequence * input,
  sick_scan_xd__msg__NAVOdomVelocity__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__NAVOdomVelocity);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__NAVOdomVelocity * data =
      (sick_scan_xd__msg__NAVOdomVelocity *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__NAVOdomVelocity__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__NAVOdomVelocity__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__NAVOdomVelocity__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
