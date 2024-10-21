// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/RadarPreHeaderDeviceBlock.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init(sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg)
{
  if (!msg) {
    return false;
  }
  // uiident
  // udiserialno
  // bdeviceerror
  // bcontaminationwarning
  // bcontaminationerror
  return true;
}

void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg)
{
  if (!msg) {
    return;
  }
  // uiident
  // udiserialno
  // bdeviceerror
  // bcontaminationwarning
  // bcontaminationerror
}

bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__are_equal(const sick_scan_xd__msg__RadarPreHeaderDeviceBlock * lhs, const sick_scan_xd__msg__RadarPreHeaderDeviceBlock * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // uiident
  if (lhs->uiident != rhs->uiident) {
    return false;
  }
  // udiserialno
  if (lhs->udiserialno != rhs->udiserialno) {
    return false;
  }
  // bdeviceerror
  if (lhs->bdeviceerror != rhs->bdeviceerror) {
    return false;
  }
  // bcontaminationwarning
  if (lhs->bcontaminationwarning != rhs->bcontaminationwarning) {
    return false;
  }
  // bcontaminationerror
  if (lhs->bcontaminationerror != rhs->bcontaminationerror) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__copy(
  const sick_scan_xd__msg__RadarPreHeaderDeviceBlock * input,
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock * output)
{
  if (!input || !output) {
    return false;
  }
  // uiident
  output->uiident = input->uiident;
  // udiserialno
  output->udiserialno = input->udiserialno;
  // bdeviceerror
  output->bdeviceerror = input->bdeviceerror;
  // bcontaminationwarning
  output->bcontaminationwarning = input->bcontaminationwarning;
  // bcontaminationerror
  output->bcontaminationerror = input->bcontaminationerror;
  return true;
}

sick_scan_xd__msg__RadarPreHeaderDeviceBlock *
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg = (sick_scan_xd__msg__RadarPreHeaderDeviceBlock *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarPreHeaderDeviceBlock), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__RadarPreHeaderDeviceBlock));
  bool success = sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__destroy(sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__init(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__RadarPreHeaderDeviceBlock *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__RadarPreHeaderDeviceBlock), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(&data[i - 1]);
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
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__fini(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array)
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
      sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(&array->data[i]);
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

sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence *
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array = (sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__destroy(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__are_equal(const sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * lhs, const sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__RadarPreHeaderDeviceBlock__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__copy(
  const sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * input,
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__RadarPreHeaderDeviceBlock);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__RadarPreHeaderDeviceBlock * data =
      (sick_scan_xd__msg__RadarPreHeaderDeviceBlock *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__RadarPreHeaderDeviceBlock__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
