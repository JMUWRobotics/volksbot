// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/NAVReflectorData.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/nav_reflector_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sick_scan_xd__msg__NAVReflectorData__init(sick_scan_xd__msg__NAVReflectorData * msg)
{
  if (!msg) {
    return false;
  }
  // cartesian_data_valid
  // x
  // y
  // polar_data_valid
  // dist
  // phi
  // opt_reflector_data_valid
  // local_id
  // global_id
  // type
  // sub_type
  // quality
  // timestamp
  // size
  // hit_count
  // mean_echo
  // start_index
  // end_index
  // pos_valid
  // pos_x
  // pos_y
  return true;
}

void
sick_scan_xd__msg__NAVReflectorData__fini(sick_scan_xd__msg__NAVReflectorData * msg)
{
  if (!msg) {
    return;
  }
  // cartesian_data_valid
  // x
  // y
  // polar_data_valid
  // dist
  // phi
  // opt_reflector_data_valid
  // local_id
  // global_id
  // type
  // sub_type
  // quality
  // timestamp
  // size
  // hit_count
  // mean_echo
  // start_index
  // end_index
  // pos_valid
  // pos_x
  // pos_y
}

bool
sick_scan_xd__msg__NAVReflectorData__are_equal(const sick_scan_xd__msg__NAVReflectorData * lhs, const sick_scan_xd__msg__NAVReflectorData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cartesian_data_valid
  if (lhs->cartesian_data_valid != rhs->cartesian_data_valid) {
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
  // polar_data_valid
  if (lhs->polar_data_valid != rhs->polar_data_valid) {
    return false;
  }
  // dist
  if (lhs->dist != rhs->dist) {
    return false;
  }
  // phi
  if (lhs->phi != rhs->phi) {
    return false;
  }
  // opt_reflector_data_valid
  if (lhs->opt_reflector_data_valid != rhs->opt_reflector_data_valid) {
    return false;
  }
  // local_id
  if (lhs->local_id != rhs->local_id) {
    return false;
  }
  // global_id
  if (lhs->global_id != rhs->global_id) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // sub_type
  if (lhs->sub_type != rhs->sub_type) {
    return false;
  }
  // quality
  if (lhs->quality != rhs->quality) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // size
  if (lhs->size != rhs->size) {
    return false;
  }
  // hit_count
  if (lhs->hit_count != rhs->hit_count) {
    return false;
  }
  // mean_echo
  if (lhs->mean_echo != rhs->mean_echo) {
    return false;
  }
  // start_index
  if (lhs->start_index != rhs->start_index) {
    return false;
  }
  // end_index
  if (lhs->end_index != rhs->end_index) {
    return false;
  }
  // pos_valid
  if (lhs->pos_valid != rhs->pos_valid) {
    return false;
  }
  // pos_x
  if (lhs->pos_x != rhs->pos_x) {
    return false;
  }
  // pos_y
  if (lhs->pos_y != rhs->pos_y) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__NAVReflectorData__copy(
  const sick_scan_xd__msg__NAVReflectorData * input,
  sick_scan_xd__msg__NAVReflectorData * output)
{
  if (!input || !output) {
    return false;
  }
  // cartesian_data_valid
  output->cartesian_data_valid = input->cartesian_data_valid;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // polar_data_valid
  output->polar_data_valid = input->polar_data_valid;
  // dist
  output->dist = input->dist;
  // phi
  output->phi = input->phi;
  // opt_reflector_data_valid
  output->opt_reflector_data_valid = input->opt_reflector_data_valid;
  // local_id
  output->local_id = input->local_id;
  // global_id
  output->global_id = input->global_id;
  // type
  output->type = input->type;
  // sub_type
  output->sub_type = input->sub_type;
  // quality
  output->quality = input->quality;
  // timestamp
  output->timestamp = input->timestamp;
  // size
  output->size = input->size;
  // hit_count
  output->hit_count = input->hit_count;
  // mean_echo
  output->mean_echo = input->mean_echo;
  // start_index
  output->start_index = input->start_index;
  // end_index
  output->end_index = input->end_index;
  // pos_valid
  output->pos_valid = input->pos_valid;
  // pos_x
  output->pos_x = input->pos_x;
  // pos_y
  output->pos_y = input->pos_y;
  return true;
}

sick_scan_xd__msg__NAVReflectorData *
sick_scan_xd__msg__NAVReflectorData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVReflectorData * msg = (sick_scan_xd__msg__NAVReflectorData *)allocator.allocate(sizeof(sick_scan_xd__msg__NAVReflectorData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__NAVReflectorData));
  bool success = sick_scan_xd__msg__NAVReflectorData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__NAVReflectorData__destroy(sick_scan_xd__msg__NAVReflectorData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__NAVReflectorData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__NAVReflectorData__Sequence__init(sick_scan_xd__msg__NAVReflectorData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVReflectorData * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__NAVReflectorData *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__NAVReflectorData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__NAVReflectorData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__NAVReflectorData__fini(&data[i - 1]);
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
sick_scan_xd__msg__NAVReflectorData__Sequence__fini(sick_scan_xd__msg__NAVReflectorData__Sequence * array)
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
      sick_scan_xd__msg__NAVReflectorData__fini(&array->data[i]);
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

sick_scan_xd__msg__NAVReflectorData__Sequence *
sick_scan_xd__msg__NAVReflectorData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__NAVReflectorData__Sequence * array = (sick_scan_xd__msg__NAVReflectorData__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__NAVReflectorData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__NAVReflectorData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__NAVReflectorData__Sequence__destroy(sick_scan_xd__msg__NAVReflectorData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__NAVReflectorData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__NAVReflectorData__Sequence__are_equal(const sick_scan_xd__msg__NAVReflectorData__Sequence * lhs, const sick_scan_xd__msg__NAVReflectorData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__NAVReflectorData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__NAVReflectorData__Sequence__copy(
  const sick_scan_xd__msg__NAVReflectorData__Sequence * input,
  sick_scan_xd__msg__NAVReflectorData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__NAVReflectorData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__NAVReflectorData * data =
      (sick_scan_xd__msg__NAVReflectorData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__NAVReflectorData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__NAVReflectorData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__NAVReflectorData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
