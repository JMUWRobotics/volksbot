// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/NAVPoseData.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/nav_pose_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
sick_scan_xd__msg__NAVPoseData__init(sick_scan_xd__msg__NAVPoseData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    sick_scan_xd__msg__NAVPoseData__fini(msg);
    return false;
  }
  // x
  // y
  // phi
  // opt_pose_data_valid
  // output_mode
  // timestamp
  // mean_dev
  // nav_mode
  // info_state
  // quant_used_reflectors
  // pose_valid
  // pose_x
  // pose_y
  // pose_yaw
  return true;
}

void
sick_scan_xd__msg__NAVPoseData__fini(sick_scan_xd__msg__NAVPoseData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x
  // y
  // phi
  // opt_pose_data_valid
  // output_mode
  // timestamp
  // mean_dev
  // nav_mode
  // info_state
  // quant_used_reflectors
  // pose_valid
  // pose_x
  // pose_y
  // pose_yaw
}

bool
sick_scan_xd__msg__NAVPoseData__are_equal(const sick_scan_xd__msg__NAVPoseData * lhs, const sick_scan_xd__msg__NAVPoseData * rhs)
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
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // phi
  if (lhs->phi != rhs->phi) {
    return false;
  }
  // opt_pose_data_valid
  if (lhs->opt_pose_data_valid != rhs->opt_pose_data_valid) {
    return false;
  }
  // output_mode
  if (lhs->output_mode != rhs->output_mode) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // mean_dev
  if (lhs->mean_dev != rhs->mean_dev) {
    return false;
  }
  // nav_mode
  if (lhs->nav_mode != rhs->nav_mode) {
    return false;
  }
  // info_state
  if (lhs->info_state != rhs->info_state) {
    return false;
  }
  // quant_used_reflectors
  if (lhs->quant_used_reflectors != rhs->quant_used_reflectors) {
    return false;
  }
  // pose_valid
  if (lhs->pose_valid != rhs->pose_valid) {
    return false;
  }
  // pose_x
  if (lhs->pose_x != rhs->pose_x) {
    return false;
  }
  // pose_y
  if (lhs->pose_y != rhs->pose_y) {
    return false;
  }
  // pose_yaw
  if (lhs->pose_yaw != rhs->pose_yaw) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__NAVPoseData__copy(
  const sick_scan_xd__msg__NAVPoseData * input,
  sick_scan_xd__msg__NAVPoseData * output)
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
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // phi
  output->phi = input->phi;
  // opt_pose_data_valid
  output->opt_pose_data_valid = input->opt_pose_data_valid;
  // output_mode
  output->output_mode = input->output_mode;
  // timestamp
  output->timestamp = input->timestamp;
  // mean_dev
  output->mean_dev = input->mean_dev;
  // nav_mode
  output->nav_mode = input->nav_mode;
  // info_state
  output->info_state = input->info_state;
  // quant_used_reflectors
  output->quant_used_reflectors = input->quant_used_reflectors;
  // pose_valid
  output->pose_valid = input->pose_valid;
  // pose_x
  output->pose_x = input->pose_x;
  // pose_y
  output->pose_y = input->pose_y;
  // pose_yaw
  output->pose_yaw = input->pose_yaw;
  return true;
}

sick_scan_xd__msg__NAVPoseData *
sick_scan_xd__msg__NAVPoseData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVPoseData * msg = (sick_scan_xd__msg__NAVPoseData *)allocator.allocate(sizeof(sick_scan_xd__msg__NAVPoseData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__NAVPoseData));
  bool success = sick_scan_xd__msg__NAVPoseData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__NAVPoseData__destroy(sick_scan_xd__msg__NAVPoseData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__NAVPoseData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__NAVPoseData__Sequence__init(sick_scan_xd__msg__NAVPoseData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVPoseData * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__NAVPoseData *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__NAVPoseData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__NAVPoseData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__NAVPoseData__fini(&data[i - 1]);
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
sick_scan_xd__msg__NAVPoseData__Sequence__fini(sick_scan_xd__msg__NAVPoseData__Sequence * array)
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
      sick_scan_xd__msg__NAVPoseData__fini(&array->data[i]);
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

sick_scan_xd__msg__NAVPoseData__Sequence *
sick_scan_xd__msg__NAVPoseData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVPoseData__Sequence * array = (sick_scan_xd__msg__NAVPoseData__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__NAVPoseData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__NAVPoseData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__NAVPoseData__Sequence__destroy(sick_scan_xd__msg__NAVPoseData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__NAVPoseData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__NAVPoseData__Sequence__are_equal(const sick_scan_xd__msg__NAVPoseData__Sequence * lhs, const sick_scan_xd__msg__NAVPoseData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__NAVPoseData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__NAVPoseData__Sequence__copy(
  const sick_scan_xd__msg__NAVPoseData__Sequence * input,
  sick_scan_xd__msg__NAVPoseData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__NAVPoseData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__NAVPoseData * data =
      (sick_scan_xd__msg__NAVPoseData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__NAVPoseData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__NAVPoseData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__NAVPoseData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
