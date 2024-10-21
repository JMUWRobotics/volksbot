// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sick_scan_xd:msg/RadarPreHeaderDeviceBlock.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__FUNCTIONS_H_
#define SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sick_scan_xd/msg/rosidl_generator_c__visibility_control.h"

#include "sick_scan_xd/msg/detail/radar_pre_header_device_block__struct.h"

/// Initialize msg/RadarPreHeaderDeviceBlock message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock
 * )) before or use
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init(sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg);

/// Finalize msg/RadarPreHeaderDeviceBlock message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini(sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg);

/// Create msg/RadarPreHeaderDeviceBlock message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
sick_scan_xd__msg__RadarPreHeaderDeviceBlock *
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__create();

/// Destroy msg/RadarPreHeaderDeviceBlock message.
/**
 * It calls
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__destroy(sick_scan_xd__msg__RadarPreHeaderDeviceBlock * msg);

/// Check for msg/RadarPreHeaderDeviceBlock message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__are_equal(const sick_scan_xd__msg__RadarPreHeaderDeviceBlock * lhs, const sick_scan_xd__msg__RadarPreHeaderDeviceBlock * rhs);

/// Copy a msg/RadarPreHeaderDeviceBlock message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__copy(
  const sick_scan_xd__msg__RadarPreHeaderDeviceBlock * input,
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock * output);

/// Initialize array of msg/RadarPreHeaderDeviceBlock messages.
/**
 * It allocates the memory for the number of elements and calls
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__init(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array, size_t size);

/// Finalize array of msg/RadarPreHeaderDeviceBlock messages.
/**
 * It calls
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__fini(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array);

/// Create array of msg/RadarPreHeaderDeviceBlock messages.
/**
 * It allocates the memory for the array and calls
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence *
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__create(size_t size);

/// Destroy array of msg/RadarPreHeaderDeviceBlock messages.
/**
 * It calls
 * sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__destroy(sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * array);

/// Check for msg/RadarPreHeaderDeviceBlock message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__are_equal(const sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * lhs, const sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * rhs);

/// Copy an array of msg/RadarPreHeaderDeviceBlock messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence__copy(
  const sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * input,
  sick_scan_xd__msg__RadarPreHeaderDeviceBlock__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__RADAR_PRE_HEADER_DEVICE_BLOCK__FUNCTIONS_H_
