// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sick_scan_xd:msg/ImuExtended.idl
// generated code does not contain a copyright notice

#ifndef SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__FUNCTIONS_H_
#define SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sick_scan_xd/msg/rosidl_generator_c__visibility_control.h"

#include "sick_scan_xd/msg/detail/imu_extended__struct.h"

/// Initialize msg/ImuExtended message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sick_scan_xd__msg__ImuExtended
 * )) before or use
 * sick_scan_xd__msg__ImuExtended__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__ImuExtended__init(sick_scan_xd__msg__ImuExtended * msg);

/// Finalize msg/ImuExtended message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__ImuExtended__fini(sick_scan_xd__msg__ImuExtended * msg);

/// Create msg/ImuExtended message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sick_scan_xd__msg__ImuExtended__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
sick_scan_xd__msg__ImuExtended *
sick_scan_xd__msg__ImuExtended__create();

/// Destroy msg/ImuExtended message.
/**
 * It calls
 * sick_scan_xd__msg__ImuExtended__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__ImuExtended__destroy(sick_scan_xd__msg__ImuExtended * msg);

/// Check for msg/ImuExtended message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__ImuExtended__are_equal(const sick_scan_xd__msg__ImuExtended * lhs, const sick_scan_xd__msg__ImuExtended * rhs);

/// Copy a msg/ImuExtended message.
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
sick_scan_xd__msg__ImuExtended__copy(
  const sick_scan_xd__msg__ImuExtended * input,
  sick_scan_xd__msg__ImuExtended * output);

/// Initialize array of msg/ImuExtended messages.
/**
 * It allocates the memory for the number of elements and calls
 * sick_scan_xd__msg__ImuExtended__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__ImuExtended__Sequence__init(sick_scan_xd__msg__ImuExtended__Sequence * array, size_t size);

/// Finalize array of msg/ImuExtended messages.
/**
 * It calls
 * sick_scan_xd__msg__ImuExtended__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__ImuExtended__Sequence__fini(sick_scan_xd__msg__ImuExtended__Sequence * array);

/// Create array of msg/ImuExtended messages.
/**
 * It allocates the memory for the array and calls
 * sick_scan_xd__msg__ImuExtended__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
sick_scan_xd__msg__ImuExtended__Sequence *
sick_scan_xd__msg__ImuExtended__Sequence__create(size_t size);

/// Destroy array of msg/ImuExtended messages.
/**
 * It calls
 * sick_scan_xd__msg__ImuExtended__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
void
sick_scan_xd__msg__ImuExtended__Sequence__destroy(sick_scan_xd__msg__ImuExtended__Sequence * array);

/// Check for msg/ImuExtended message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sick_scan_xd
bool
sick_scan_xd__msg__ImuExtended__Sequence__are_equal(const sick_scan_xd__msg__ImuExtended__Sequence * lhs, const sick_scan_xd__msg__ImuExtended__Sequence * rhs);

/// Copy an array of msg/ImuExtended messages.
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
sick_scan_xd__msg__ImuExtended__Sequence__copy(
  const sick_scan_xd__msg__ImuExtended__Sequence * input,
  sick_scan_xd__msg__ImuExtended__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SICK_SCAN_XD__MSG__DETAIL__IMU_EXTENDED__FUNCTIONS_H_
