// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/RadarPreHeaderEncoderBlock.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__init(sick_scan_xd__msg__RadarPreHeaderEncoderBlock * msg)
{
  if (!msg) {
    return false;
  }
  // udiencoderpos
  // iencoderspeed
  return true;
}

void
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__fini(sick_scan_xd__msg__RadarPreHeaderEncoderBlock * msg)
{
  if (!msg) {
    return;
  }
  // udiencoderpos
  // iencoderspeed
}

bool
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__are_equal(const sick_scan_xd__msg__RadarPreHeaderEncoderBlock * lhs, const sick_scan_xd__msg__RadarPreHeaderEncoderBlock * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // udiencoderpos
  if (lhs->udiencoderpos != rhs->udiencoderpos) {
    return false;
  }
  // iencoderspeed
  if (lhs->iencoderspeed != rhs->iencoderspeed) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__copy(
  const sick_scan_xd__msg__RadarPreHeaderEncoderBlock * input,
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock * output)
{
  if (!input || !output) {
    return false;
  }
  // udiencoderpos
  output->udiencoderpos = input->udiencoderpos;
  // iencoderspeed
  output->iencoderspeed = input->iencoderspeed;
  return true;
}

sick_scan_xd__msg__RadarPreHeaderEncoderBlock *
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock * msg = (sick_scan_xd__msg__RadarPreHeaderEncoderBlock *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock));
  bool success = sick_scan_xd__msg__RadarPreHeaderEncoderBlock__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__destroy(sick_scan_xd__msg__RadarPreHeaderEncoderBlock * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__RadarPreHeaderEncoderBlock__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__init(sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__RadarPreHeaderEncoderBlock *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__RadarPreHeaderEncoderBlock__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__RadarPreHeaderEncoderBlock__fini(&data[i - 1]);
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
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__fini(sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * array)
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
      sick_scan_xd__msg__RadarPreHeaderEncoderBlock__fini(&array->data[i]);
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

sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence *
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * array = (sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__destroy(sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__are_equal(const sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * lhs, const sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__copy(
  const sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * input,
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__RadarPreHeaderEncoderBlock);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__RadarPreHeaderEncoderBlock * data =
      (sick_scan_xd__msg__RadarPreHeaderEncoderBlock *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__RadarPreHeaderEncoderBlock__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
