// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/LFErecFieldMsg.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/lf_erec_field_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sick_scan_xd__msg__LFErecFieldMsg__init(sick_scan_xd__msg__LFErecFieldMsg * msg)
{
  if (!msg) {
    return false;
  }
  // version_number
  // field_index
  // sys_count
  // dist_scale_factor
  // dist_scale_offset
  // angle_scale_factor
  // angle_scale_offset
  // field_result_mrs
  // time_state
  // year
  // month
  // day
  // hour
  // minute
  // second
  // microsecond
  return true;
}

void
sick_scan_xd__msg__LFErecFieldMsg__fini(sick_scan_xd__msg__LFErecFieldMsg * msg)
{
  if (!msg) {
    return;
  }
  // version_number
  // field_index
  // sys_count
  // dist_scale_factor
  // dist_scale_offset
  // angle_scale_factor
  // angle_scale_offset
  // field_result_mrs
  // time_state
  // year
  // month
  // day
  // hour
  // minute
  // second
  // microsecond
}

bool
sick_scan_xd__msg__LFErecFieldMsg__are_equal(const sick_scan_xd__msg__LFErecFieldMsg * lhs, const sick_scan_xd__msg__LFErecFieldMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // version_number
  if (lhs->version_number != rhs->version_number) {
    return false;
  }
  // field_index
  if (lhs->field_index != rhs->field_index) {
    return false;
  }
  // sys_count
  if (lhs->sys_count != rhs->sys_count) {
    return false;
  }
  // dist_scale_factor
  if (lhs->dist_scale_factor != rhs->dist_scale_factor) {
    return false;
  }
  // dist_scale_offset
  if (lhs->dist_scale_offset != rhs->dist_scale_offset) {
    return false;
  }
  // angle_scale_factor
  if (lhs->angle_scale_factor != rhs->angle_scale_factor) {
    return false;
  }
  // angle_scale_offset
  if (lhs->angle_scale_offset != rhs->angle_scale_offset) {
    return false;
  }
  // field_result_mrs
  if (lhs->field_result_mrs != rhs->field_result_mrs) {
    return false;
  }
  // time_state
  if (lhs->time_state != rhs->time_state) {
    return false;
  }
  // year
  if (lhs->year != rhs->year) {
    return false;
  }
  // month
  if (lhs->month != rhs->month) {
    return false;
  }
  // day
  if (lhs->day != rhs->day) {
    return false;
  }
  // hour
  if (lhs->hour != rhs->hour) {
    return false;
  }
  // minute
  if (lhs->minute != rhs->minute) {
    return false;
  }
  // second
  if (lhs->second != rhs->second) {
    return false;
  }
  // microsecond
  if (lhs->microsecond != rhs->microsecond) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__LFErecFieldMsg__copy(
  const sick_scan_xd__msg__LFErecFieldMsg * input,
  sick_scan_xd__msg__LFErecFieldMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // version_number
  output->version_number = input->version_number;
  // field_index
  output->field_index = input->field_index;
  // sys_count
  output->sys_count = input->sys_count;
  // dist_scale_factor
  output->dist_scale_factor = input->dist_scale_factor;
  // dist_scale_offset
  output->dist_scale_offset = input->dist_scale_offset;
  // angle_scale_factor
  output->angle_scale_factor = input->angle_scale_factor;
  // angle_scale_offset
  output->angle_scale_offset = input->angle_scale_offset;
  // field_result_mrs
  output->field_result_mrs = input->field_result_mrs;
  // time_state
  output->time_state = input->time_state;
  // year
  output->year = input->year;
  // month
  output->month = input->month;
  // day
  output->day = input->day;
  // hour
  output->hour = input->hour;
  // minute
  output->minute = input->minute;
  // second
  output->second = input->second;
  // microsecond
  output->microsecond = input->microsecond;
  return true;
}

sick_scan_xd__msg__LFErecFieldMsg *
sick_scan_xd__msg__LFErecFieldMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__LFErecFieldMsg * msg = (sick_scan_xd__msg__LFErecFieldMsg *)allocator.allocate(sizeof(sick_scan_xd__msg__LFErecFieldMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__LFErecFieldMsg));
  bool success = sick_scan_xd__msg__LFErecFieldMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__LFErecFieldMsg__destroy(sick_scan_xd__msg__LFErecFieldMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__LFErecFieldMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__LFErecFieldMsg__Sequence__init(sick_scan_xd__msg__LFErecFieldMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__LFErecFieldMsg * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__LFErecFieldMsg *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__LFErecFieldMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__LFErecFieldMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__LFErecFieldMsg__fini(&data[i - 1]);
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
sick_scan_xd__msg__LFErecFieldMsg__Sequence__fini(sick_scan_xd__msg__LFErecFieldMsg__Sequence * array)
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
      sick_scan_xd__msg__LFErecFieldMsg__fini(&array->data[i]);
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

sick_scan_xd__msg__LFErecFieldMsg__Sequence *
sick_scan_xd__msg__LFErecFieldMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__LFErecFieldMsg__Sequence * array = (sick_scan_xd__msg__LFErecFieldMsg__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__LFErecFieldMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__LFErecFieldMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__LFErecFieldMsg__Sequence__destroy(sick_scan_xd__msg__LFErecFieldMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__LFErecFieldMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__LFErecFieldMsg__Sequence__are_equal(const sick_scan_xd__msg__LFErecFieldMsg__Sequence * lhs, const sick_scan_xd__msg__LFErecFieldMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__LFErecFieldMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__LFErecFieldMsg__Sequence__copy(
  const sick_scan_xd__msg__LFErecFieldMsg__Sequence * input,
  sick_scan_xd__msg__LFErecFieldMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__LFErecFieldMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__LFErecFieldMsg * data =
      (sick_scan_xd__msg__LFErecFieldMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__LFErecFieldMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__LFErecFieldMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__LFErecFieldMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
