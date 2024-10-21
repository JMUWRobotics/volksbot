// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sick_scan_xd:srv/ECRChangeArrSrv.idl
// generated code does not contain a copyright notice
#include "sick_scan_xd/srv/detail/ecr_change_arr_srv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
sick_scan_xd__srv__ECRChangeArrSrv_Request__init(sick_scan_xd__srv__ECRChangeArrSrv_Request * msg)
{
  if (!msg) {
    return false;
  }
  // active
  return true;
}

void
sick_scan_xd__srv__ECRChangeArrSrv_Request__fini(sick_scan_xd__srv__ECRChangeArrSrv_Request * msg)
{
  if (!msg) {
    return;
  }
  // active
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Request__are_equal(const sick_scan_xd__srv__ECRChangeArrSrv_Request * lhs, const sick_scan_xd__srv__ECRChangeArrSrv_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // active
  if (lhs->active != rhs->active) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Request__copy(
  const sick_scan_xd__srv__ECRChangeArrSrv_Request * input,
  sick_scan_xd__srv__ECRChangeArrSrv_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // active
  output->active = input->active;
  return true;
}

sick_scan_xd__srv__ECRChangeArrSrv_Request *
sick_scan_xd__srv__ECRChangeArrSrv_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__srv__ECRChangeArrSrv_Request * msg = (sick_scan_xd__srv__ECRChangeArrSrv_Request *)allocator.allocate(sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Request));
  bool success = sick_scan_xd__srv__ECRChangeArrSrv_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__srv__ECRChangeArrSrv_Request__destroy(sick_scan_xd__srv__ECRChangeArrSrv_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__srv__ECRChangeArrSrv_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__init(sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__srv__ECRChangeArrSrv_Request * data = NULL;

  if (size) {
    data = (sick_scan_xd__srv__ECRChangeArrSrv_Request *)allocator.zero_allocate(size, sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__srv__ECRChangeArrSrv_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__srv__ECRChangeArrSrv_Request__fini(&data[i - 1]);
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
sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__fini(sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * array)
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
      sick_scan_xd__srv__ECRChangeArrSrv_Request__fini(&array->data[i]);
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

sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence *
sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * array = (sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence *)allocator.allocate(sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__destroy(sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__are_equal(const sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * lhs, const sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__srv__ECRChangeArrSrv_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence__copy(
  const sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * input,
  sick_scan_xd__srv__ECRChangeArrSrv_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__srv__ECRChangeArrSrv_Request * data =
      (sick_scan_xd__srv__ECRChangeArrSrv_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__srv__ECRChangeArrSrv_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__srv__ECRChangeArrSrv_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__srv__ECRChangeArrSrv_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
sick_scan_xd__srv__ECRChangeArrSrv_Response__init(sick_scan_xd__srv__ECRChangeArrSrv_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
sick_scan_xd__srv__ECRChangeArrSrv_Response__fini(sick_scan_xd__srv__ECRChangeArrSrv_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Response__are_equal(const sick_scan_xd__srv__ECRChangeArrSrv_Response * lhs, const sick_scan_xd__srv__ECRChangeArrSrv_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Response__copy(
  const sick_scan_xd__srv__ECRChangeArrSrv_Response * input,
  sick_scan_xd__srv__ECRChangeArrSrv_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

sick_scan_xd__srv__ECRChangeArrSrv_Response *
sick_scan_xd__srv__ECRChangeArrSrv_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__srv__ECRChangeArrSrv_Response * msg = (sick_scan_xd__srv__ECRChangeArrSrv_Response *)allocator.allocate(sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Response));
  bool success = sick_scan_xd__srv__ECRChangeArrSrv_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sick_scan_xd__srv__ECRChangeArrSrv_Response__destroy(sick_scan_xd__srv__ECRChangeArrSrv_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sick_scan_xd__srv__ECRChangeArrSrv_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__init(sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__srv__ECRChangeArrSrv_Response * data = NULL;

  if (size) {
    data = (sick_scan_xd__srv__ECRChangeArrSrv_Response *)allocator.zero_allocate(size, sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sick_scan_xd__srv__ECRChangeArrSrv_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sick_scan_xd__srv__ECRChangeArrSrv_Response__fini(&data[i - 1]);
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
sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__fini(sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * array)
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
      sick_scan_xd__srv__ECRChangeArrSrv_Response__fini(&array->data[i]);
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

sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence *
sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * array = (sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence *)allocator.allocate(sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__destroy(sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__are_equal(const sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * lhs, const sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sick_scan_xd__srv__ECRChangeArrSrv_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence__copy(
  const sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * input,
  sick_scan_xd__srv__ECRChangeArrSrv_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sick_scan_xd__srv__ECRChangeArrSrv_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sick_scan_xd__srv__ECRChangeArrSrv_Response * data =
      (sick_scan_xd__srv__ECRChangeArrSrv_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sick_scan_xd__srv__ECRChangeArrSrv_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sick_scan_xd__srv__ECRChangeArrSrv_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sick_scan_xd__srv__ECRChangeArrSrv_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
