// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:msg/RadarPreHeader.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/msg/detail/radar_pre_header__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `radarpreheaderdeviceblock`
#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__functions.h"
// Member `radarpreheaderstatusblock`
#include "sick_scan_xd/msg/detail/radar_pre_header_status_block__functions.h"
// Member `radarpreheadermeasurementparam1block`
#include "sick_scan_xd/msg/detail/radar_pre_header_measurement_param1_block__functions.h"
// Member `radarpreheaderarrayencoderblock`
#include "sick_scan_xd/msg/detail/radar_pre_header_encoder_block__functions.h"

bool
sick_scan_xd__msg__RadarPreHeader__init(sick_scan_xd__msg__RadarPreHeader * msg)
{
  if (!msg) {
    return false;
  }
  // uiversionno
  // radarpreheaderdeviceblock
  if (!sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init(&msg->radarpreheaderdeviceblock)) {
    sick_scan_xd__msg__RadarPreHeader__fini(msg);
    return false;
  }
  // radarpreheaderstatusblock
  if (!sick_scan_xd__msg__RadarPreHeaderStatusBlock__init(&msg->radarpreheaderstatusblock)) {
    sick_scan_xd__msg__RadarPreHeader__fini(msg);
    return false;
  }
  // radarpreheadermeasurementparam1block
  if (!sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block__init(&msg->radarpreheadermeasurementparam1block)) {
    sick_scan_xd__msg__RadarPreHeader__fini(msg);
    return false;
  }
  // radarpreheaderarrayencoderblock
  if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__init(&msg->radarpreheaderarrayencoderblock, 0)) {
    sick_scan_xd__msg__RadarPreHeader__fini(msg);
    return false;
  }
  return true;
}

void
sick_scan_xd__msg__RadarPreHeader__fini(sick_scan_xd__msg__RadarPreHeader * msg)
{
  if (!msg) {
    return;
  }
  // uiversionno
  // radarpreheaderdeviceblock
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(&msg->radarpreheaderdeviceblock);
  // radarpreheaderstatusblock
  sick_scan_xd__msg__RadarPreHeaderStatusBlock__fini(&msg->radarpreheaderstatusblock);
  // radarpreheadermeasurementparam1block
  sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block__fini(&msg->radarpreheadermeasurementparam1block);
  // radarpreheaderarrayencoderblock
  sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__fini(&msg->radarpreheaderarrayencoderblock);
}

bool
sick_scan_xd__msg__RadarPreHeader__are_equal(const sick_scan_xd__msg__RadarPreHeader * lhs, const sick_scan_xd__msg__RadarPreHeader * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // uiversionno
  if (lhs->uiversionno != rhs->uiversionno) {
    return false;
  }
  // radarpreheaderdeviceblock
  if (!sick_scan_xd__msg__RadarPreHeaderDeviceBlock__are_equal(
      &(lhs->radarpreheaderdeviceblock), &(rhs->radarpreheaderdeviceblock)))
  {
    return false;
  }
  // radarpreheaderstatusblock
  if (!sick_scan_xd__msg__RadarPreHeaderStatusBlock__are_equal(
      &(lhs->radarpreheaderstatusblock), &(rhs->radarpreheaderstatusblock)))
  {
    return false;
  }
  // radarpreheadermeasurementparam1block
  if (!sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block__are_equal(
      &(lhs->radarpreheadermeasurementparam1block), &(rhs->radarpreheadermeasurementparam1block)))
  {
    return false;
  }
  // radarpreheaderarrayencoderblock
  if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__are_equal(
      &(lhs->radarpreheaderarrayencoderblock), &(rhs->radarpreheaderarrayencoderblock)))
  {
    return false;
  }
  return true;
}

bool
sick_scan_xd__msg__RadarPreHeader__copy(
  const sick_scan_xd__msg__RadarPreHeader * input,
  sick_scan_xd__msg__RadarPreHeader * output)
{
  if (!input || !output) {
    return false;
  }
  // uiversionno
  output->uiversionno = input->uiversionno;
  // radarpreheaderdeviceblock
  if (!sick_scan_xd__msg__RadarPreHeaderDeviceBlock__copy(
      &(input->radarpreheaderdeviceblock), &(output->radarpreheaderdeviceblock)))
  {
    return false;
  }
  // radarpreheaderstatusblock
  if (!sick_scan_xd__msg__RadarPreHeaderStatusBlock__copy(
      &(input->radarpreheaderstatusblock), &(output->radarpreheaderstatusblock)))
  {
    return false;
  }
  // radarpreheadermeasurementparam1block
  if (!sick_scan_xd__msg__RadarPreHeaderMeasurementParam1Block__copy(
      &(input->radarpreheadermeasurementparam1block), &(output->radarpreheadermeasurementparam1block)))
  {
    return false;
  }
  // radarpreheaderarrayencoderblock
  if (!sick_scan_xd__msg__RadarPreHeaderEncoderBlock__Sequence__copy(
      &(input->radarpreheaderarrayencoderblock), &(output->radarpreheaderarrayencoderblock)))
  {
    return false;
  }
  return true;
}

sick_scan_xd__msg__RadarPreHeader *
sick_scan_xd__msg__RadarPreHeader__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeader * msg = (sick_scan_xd__msg__RadarPreHeader *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarPreHeader), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__msg__RadarPreHeader));
  bool success = sick_scan_xd__msg__RadarPreHeader__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__msg__RadarPreHeader__destroy(sick_scan_xd__msg__RadarPreHeader * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__msg__RadarPreHeader__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__msg__RadarPreHeader__Sequence__init(sick_scan_xd__msg__RadarPreHeader__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeader * data = NULL;

  if (size) {
    data = (sick_scan_xd__msg__RadarPreHeader *)allocator.zero_allocate(size, sizeof(sick_scan_xd__msg__RadarPreHeader), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__msg__RadarPreHeader__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__msg__RadarPreHeader__fini(&data[i - 1]);
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
sick_scan_xd__msg__RadarPreHeader__Sequence__fini(sick_scan_xd__msg__RadarPreHeader__Sequence * array)
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
      sick_scan_xd__msg__RadarPreHeader__fini(&array->data[i]);
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

sick_scan_xd__msg__RadarPreHeader__Sequence *
sick_scan_xd__msg__RadarPreHeader__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__msg__RadarPreHeader__Sequence * array = (sick_scan_xd__msg__RadarPreHeader__Sequence *)allocator.allocate(sizeof(sick_scan_xd__msg__RadarPreHeader__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__msg__RadarPreHeader__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__msg__RadarPreHeader__Sequence__destroy(sick_scan_xd__msg__RadarPreHeader__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__msg__RadarPreHeader__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__msg__RadarPreHeader__Sequence__are_equal(const sick_scan_xd__msg__RadarPreHeader__Sequence * lhs, const sick_scan_xd__msg__RadarPreHeader__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__msg__RadarPreHeader__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__msg__RadarPreHeader__Sequence__copy(
  const sick_scan_xd__msg__RadarPreHeader__Sequence * input,
  sick_scan_xd__msg__RadarPreHeader__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__msg__RadarPreHeader);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__msg__RadarPreHeader * data =
      (sick_scan_xd__msg__RadarPreHeader *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__msg__RadarPreHeader__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__msg__RadarPreHeader__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__msg__RadarPreHeader__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
