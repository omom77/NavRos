// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serial_motor_demo_msgs:msg/FeedbackMotor.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/msg/detail/feedback_motor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
serial_motor_demo_msgs__msg__FeedbackMotor__init(serial_motor_demo_msgs__msg__FeedbackMotor * msg)
{
  if (!msg) {
    return false;
  }
  // data
  return true;
}

void
serial_motor_demo_msgs__msg__FeedbackMotor__fini(serial_motor_demo_msgs__msg__FeedbackMotor * msg)
{
  if (!msg) {
    return;
  }
  // data
}

bool
serial_motor_demo_msgs__msg__FeedbackMotor__are_equal(const serial_motor_demo_msgs__msg__FeedbackMotor * lhs, const serial_motor_demo_msgs__msg__FeedbackMotor * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->data[i] != rhs->data[i]) {
      return false;
    }
  }
  return true;
}

bool
serial_motor_demo_msgs__msg__FeedbackMotor__copy(
  const serial_motor_demo_msgs__msg__FeedbackMotor * input,
  serial_motor_demo_msgs__msg__FeedbackMotor * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  for (size_t i = 0; i < 3; ++i) {
    output->data[i] = input->data[i];
  }
  return true;
}

serial_motor_demo_msgs__msg__FeedbackMotor *
serial_motor_demo_msgs__msg__FeedbackMotor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__msg__FeedbackMotor * msg = (serial_motor_demo_msgs__msg__FeedbackMotor *)allocator.allocate(sizeof(serial_motor_demo_msgs__msg__FeedbackMotor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_demo_msgs__msg__FeedbackMotor));
  bool success = serial_motor_demo_msgs__msg__FeedbackMotor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
serial_motor_demo_msgs__msg__FeedbackMotor__destroy(serial_motor_demo_msgs__msg__FeedbackMotor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    serial_motor_demo_msgs__msg__FeedbackMotor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__init(serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__msg__FeedbackMotor * data = NULL;

  if (size) {
    data = (serial_motor_demo_msgs__msg__FeedbackMotor *)allocator.zero_allocate(size, sizeof(serial_motor_demo_msgs__msg__FeedbackMotor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_demo_msgs__msg__FeedbackMotor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_demo_msgs__msg__FeedbackMotor__fini(&data[i - 1]);
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
serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__fini(serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * array)
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
      serial_motor_demo_msgs__msg__FeedbackMotor__fini(&array->data[i]);
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

serial_motor_demo_msgs__msg__FeedbackMotor__Sequence *
serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * array = (serial_motor_demo_msgs__msg__FeedbackMotor__Sequence *)allocator.allocate(sizeof(serial_motor_demo_msgs__msg__FeedbackMotor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__destroy(serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__are_equal(const serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * lhs, const serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!serial_motor_demo_msgs__msg__FeedbackMotor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
serial_motor_demo_msgs__msg__FeedbackMotor__Sequence__copy(
  const serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * input,
  serial_motor_demo_msgs__msg__FeedbackMotor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(serial_motor_demo_msgs__msg__FeedbackMotor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    serial_motor_demo_msgs__msg__FeedbackMotor * data =
      (serial_motor_demo_msgs__msg__FeedbackMotor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!serial_motor_demo_msgs__msg__FeedbackMotor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          serial_motor_demo_msgs__msg__FeedbackMotor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!serial_motor_demo_msgs__msg__FeedbackMotor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
