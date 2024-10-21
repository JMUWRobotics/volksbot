// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/LIDoutputstateMsg.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/li_doutputstate_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `output_state`
// Member `output_count`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
sick_scan_xd__msg__LIDoutputstateMsg__init(sick_scan_xd__msg__LIDoutputstateMsg * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    sick_scan_xd__msg__LIDoutputstateMsg__fini(msg);
    return false;
  }
  // version_number
  // system_counter
  // output_state
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->output_state, 0)) {
    sick_scan_xd__msg__LIDoutputstateMsg__fini(msg);
    return false;
  }
  // output_count
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->output_count, 0)) {
    sick_scan_xd__msg__LIDoutputstateMsg__fini(msg);
    return false;
  }
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
sick_scan_xd__msg__LIDoutputstateMsg__fini(sick_scan_xd__msg__LIDoutputstateMsg * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // version_number
  // system_counter
  // output_state
  rosidl_runtime_c__uint8__Sequence__fini(&msg->output_state);
  // output_count
  rosidl_runtime_c__uint32__Sequence__fini(&msg->output_count);
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
sick_scan_xd__msg__LIDoutputstateMsg__are_equal(const sick_scan_xd__msg__LIDoutputstateMsg * lhs, const sick_scan_xd__msg__LIDoutputstateMsg * rhs)
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
  // version_number
  if (lhs->version_number != rhs->version_number) {
    return false;
  }
  // system_counter
  if (lhs->system_counter != rhs->system_counter) {
    return false;
  }
  // output_state
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->output_state), &(rhs->output_state)))
  {
    return false;
  }
  // output_count
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->output_count), &(rhs->output_count)))
  {
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
sick_scan_xd__msg__LIDoutputstateMsg__copy(
  const sick_scan_xd__msg__LIDoutputstateMsg * input,
  sick_scan_xd__msg__LIDoutputstateMsg * output)
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
  // version_number
  output->version_number = input->version_number;
  // system_counter
  output->system_counter = input->system_counter;
  // output_state
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->output_state), &(output->output_state)))
  {
    return false;
  }
  // output_count
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->output_count), &(output->output_count)))
  {
    return false;
  }
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

sick_scan_xd__msg__LIDoutputstateMsg *
sick_scan_xd__msg__LIDoutputstateMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__LIDoutputstateMsg * msg = (sick_scan_xd__msg__LIDoutputstateMsg *)allocator.allocate(sizeof(sick_scan_xd__msg__LIDoutputstateMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__LIDoutputstateMsg));
  bool success = sick_scan_xd__msg__LIDoutputstateMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__LIDoutputstateMsg__destroy(sick_scan_xd__msg__LIDoutputstateMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__LIDoutputstateMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__LIDoutputstateMsg__Sequence__init(sick_scan_xd__msg__LIDoutputstateMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__LIDoutputstateMsg * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__LIDoutputstateMsg *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__LIDoutputstateMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__LIDoutputstateMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__LIDoutputstateMsg__fini(&data[i - 1]);
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
sick_scan_xd__msg__LIDoutputstateMsg__Sequence__fini(sick_scan_xd__msg__LIDoutputstateMsg__Sequence * array)
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
      sick_scan_xd__msg__LIDoutputstateMsg__fini(&array->data[i]);
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

sick_scan_xd__msg__LIDoutputstateMsg__Sequence *
sick_scan_xd__msg__LIDoutputstateMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__LIDoutputstateMsg__Sequence * array = (sick_scan_xd__msg__LIDoutputstateMsg__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__LIDoutputstateMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__LIDoutputstateMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__LIDoutputstateMsg__Sequence__destroy(sick_scan_xd__msg__LIDoutputstateMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__LIDoutputstateMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__LIDoutputstateMsg__Sequence__are_equal(const sick_scan_xd__msg__LIDoutputstateMsg__Sequence * lhs, const sick_scan_xd__msg__LIDoutputstateMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__LIDoutputstateMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__LIDoutputstateMsg__Sequence__copy(
  const sick_scan_xd__msg__LIDoutputstateMsg__Sequence * input,
  sick_scan_xd__msg__LIDoutputstateMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__LIDoutputstateMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__LIDoutputstateMsg * data =
      (sick_scan_xd__msg__LIDoutputstateMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__LIDoutputstateMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__LIDoutputstateMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__LIDoutputstateMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
