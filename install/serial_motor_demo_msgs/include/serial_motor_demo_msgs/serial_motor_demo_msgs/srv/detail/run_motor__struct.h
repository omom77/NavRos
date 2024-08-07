// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serial_motor_demo_msgs:srv/RunMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__STRUCT_H_
#define SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motor_state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RunMotor in the package serial_motor_demo_msgs.
typedef struct serial_motor_demo_msgs__srv__RunMotor_Request
{
  rosidl_runtime_c__String motor_state;
} serial_motor_demo_msgs__srv__RunMotor_Request;

// Struct for a sequence of serial_motor_demo_msgs__srv__RunMotor_Request.
typedef struct serial_motor_demo_msgs__srv__RunMotor_Request__Sequence
{
  serial_motor_demo_msgs__srv__RunMotor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_demo_msgs__srv__RunMotor_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RunMotor in the package serial_motor_demo_msgs.
typedef struct serial_motor_demo_msgs__srv__RunMotor_Response
{
  bool success;
} serial_motor_demo_msgs__srv__RunMotor_Response;

// Struct for a sequence of serial_motor_demo_msgs__srv__RunMotor_Response.
typedef struct serial_motor_demo_msgs__srv__RunMotor_Response__Sequence
{
  serial_motor_demo_msgs__srv__RunMotor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_demo_msgs__srv__RunMotor_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__STRUCT_H_
