// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serial_motor_demo_msgs:msg/FeedbackMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__STRUCT_H_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FeedbackMotor in the package serial_motor_demo_msgs.
typedef struct serial_motor_demo_msgs__msg__FeedbackMotor
{
  int32_t m_feedback;
} serial_motor_demo_msgs__msg__FeedbackMotor;

// Struct for a sequence of serial_motor_demo_msgs__msg__FeedbackMotor.
typedef struct serial_motor_demo_msgs__msg__FeedbackMotor__Sequence
{
  serial_motor_demo_msgs__msg__FeedbackMotor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_demo_msgs__msg__FeedbackMotor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__STRUCT_H_
