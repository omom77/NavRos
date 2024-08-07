// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serial_motor_demo_msgs:srv/RunMotor.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/srv/detail/run_motor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `motor_state`
#include "rosidl_runtime_c/string_functions.h"

bool
serial_motor_demo_msgs__srv__RunMotor_Request__init(serial_motor_demo_msgs__srv__RunMotor_Request * msg)
{
  if (!msg) {
    return false;
  }
  // motor_state
  if (!rosidl_runtime_c__String__init(&msg->motor_state)) {
    serial_motor_demo_msgs__srv__RunMotor_Request__fini(msg);
    return false;
  }
  return true;
}

void
serial_motor_demo_msgs__srv__RunMotor_Request__fini(serial_motor_demo_msgs__srv__RunMotor_Request * msg)
{
  if (!msg) {
    return;
  }
  // motor_state
  rosidl_runtime_c__String__fini(&msg->motor_state);
}

bool
serial_motor_demo_msgs__srv__RunMotor_Request__are_equal(const serial_motor_demo_msgs__srv__RunMotor_Request * lhs, const serial_motor_demo_msgs__srv__RunMotor_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->motor_state), &(rhs->motor_state)))
  {
    return false;
  }
  return true;
}

bool
serial_motor_demo_msgs__srv__RunMotor_Request__copy(
  const serial_motor_demo_msgs__srv__RunMotor_Request * input,
  serial_motor_demo_msgs__srv__RunMotor_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_state
  if (!rosidl_runtime_c__String__copy(
      &(input->motor_state), &(output->motor_state)))
  {
    return false;
  }
  return true;
}

serial_motor_demo_msgs__srv__RunMotor_Request *
serial_motor_demo_msgs__srv__RunMotor_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__srv__RunMotor_Request * msg = (serial_motor_demo_msgs__srv__RunMotor_Request *)allocator.allocate(sizeof(serial_motor_demo_msgs__srv__RunMotor_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_demo_msgs__srv__RunMotor_Request));
  bool success = serial_motor_demo_msgs__srv__RunMotor_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
serial_motor_demo_msgs__srv__RunMotor_Request__destroy(serial_motor_demo_msgs__srv__RunMotor_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    serial_motor_demo_msgs__srv__RunMotor_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__init(serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__srv__RunMotor_Request * data = NULL;

  if (size) {
    data = (serial_motor_demo_msgs__srv__RunMotor_Request *)allocator.zero_allocate(size, sizeof(serial_motor_demo_msgs__srv__RunMotor_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_demo_msgs__srv__RunMotor_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_demo_msgs__srv__RunMotor_Request__fini(&data[i - 1]);
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
serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__fini(serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * array)
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
      serial_motor_demo_msgs__srv__RunMotor_Request__fini(&array->data[i]);
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

serial_motor_demo_msgs__srv__RunMotor_Request__Sequence *
serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * array = (serial_motor_demo_msgs__srv__RunMotor_Request__Sequence *)allocator.allocate(sizeof(serial_motor_demo_msgs__srv__RunMotor_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__destroy(serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__are_equal(const serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * lhs, const serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!serial_motor_demo_msgs__srv__RunMotor_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
serial_motor_demo_msgs__srv__RunMotor_Request__Sequence__copy(
  const serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * input,
  serial_motor_demo_msgs__srv__RunMotor_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(serial_motor_demo_msgs__srv__RunMotor_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    serial_motor_demo_msgs__srv__RunMotor_Request * data =
      (serial_motor_demo_msgs__srv__RunMotor_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!serial_motor_demo_msgs__srv__RunMotor_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          serial_motor_demo_msgs__srv__RunMotor_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!serial_motor_demo_msgs__srv__RunMotor_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
serial_motor_demo_msgs__srv__RunMotor_Response__init(serial_motor_demo_msgs__srv__RunMotor_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
serial_motor_demo_msgs__srv__RunMotor_Response__fini(serial_motor_demo_msgs__srv__RunMotor_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
serial_motor_demo_msgs__srv__RunMotor_Response__are_equal(const serial_motor_demo_msgs__srv__RunMotor_Response * lhs, const serial_motor_demo_msgs__srv__RunMotor_Response * rhs)
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
serial_motor_demo_msgs__srv__RunMotor_Response__copy(
  const serial_motor_demo_msgs__srv__RunMotor_Response * input,
  serial_motor_demo_msgs__srv__RunMotor_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

serial_motor_demo_msgs__srv__RunMotor_Response *
serial_motor_demo_msgs__srv__RunMotor_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__srv__RunMotor_Response * msg = (serial_motor_demo_msgs__srv__RunMotor_Response *)allocator.allocate(sizeof(serial_motor_demo_msgs__srv__RunMotor_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_demo_msgs__srv__RunMotor_Response));
  bool success = serial_motor_demo_msgs__srv__RunMotor_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
serial_motor_demo_msgs__srv__RunMotor_Response__destroy(serial_motor_demo_msgs__srv__RunMotor_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    serial_motor_demo_msgs__srv__RunMotor_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__init(serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__srv__RunMotor_Response * data = NULL;

  if (size) {
    data = (serial_motor_demo_msgs__srv__RunMotor_Response *)allocator.zero_allocate(size, sizeof(serial_motor_demo_msgs__srv__RunMotor_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_demo_msgs__srv__RunMotor_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_demo_msgs__srv__RunMotor_Response__fini(&data[i - 1]);
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
serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__fini(serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * array)
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
      serial_motor_demo_msgs__srv__RunMotor_Response__fini(&array->data[i]);
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

serial_motor_demo_msgs__srv__RunMotor_Response__Sequence *
serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * array = (serial_motor_demo_msgs__srv__RunMotor_Response__Sequence *)allocator.allocate(sizeof(serial_motor_demo_msgs__srv__RunMotor_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__destroy(serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__are_equal(const serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * lhs, const serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!serial_motor_demo_msgs__srv__RunMotor_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
serial_motor_demo_msgs__srv__RunMotor_Response__Sequence__copy(
  const serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * input,
  serial_motor_demo_msgs__srv__RunMotor_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(serial_motor_demo_msgs__srv__RunMotor_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    serial_motor_demo_msgs__srv__RunMotor_Response * data =
      (serial_motor_demo_msgs__srv__RunMotor_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!serial_motor_demo_msgs__srv__RunMotor_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          serial_motor_demo_msgs__srv__RunMotor_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!serial_motor_demo_msgs__srv__RunMotor_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
