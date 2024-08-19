// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from serial_motor_demo_msgs:msg/FeedbackMotor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "serial_motor_demo_msgs/msg/detail/feedback_motor__rosidl_typesupport_introspection_c.h"
#include "serial_motor_demo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "serial_motor_demo_msgs/msg/detail/feedback_motor__functions.h"
#include "serial_motor_demo_msgs/msg/detail/feedback_motor__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  serial_motor_demo_msgs__msg__FeedbackMotor__init(message_memory);
}

void serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_fini_function(void * message_memory)
{
  serial_motor_demo_msgs__msg__FeedbackMotor__fini(message_memory);
}

size_t serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__size_function__FeedbackMotor__data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__get_const_function__FeedbackMotor__data(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__get_function__FeedbackMotor__data(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__fetch_function__FeedbackMotor__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__get_const_function__FeedbackMotor__data(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__assign_function__FeedbackMotor__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__get_function__FeedbackMotor__data(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(serial_motor_demo_msgs__msg__FeedbackMotor, data),  // bytes offset in struct
    NULL,  // default value
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__size_function__FeedbackMotor__data,  // size() function pointer
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__get_const_function__FeedbackMotor__data,  // get_const(index) function pointer
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__get_function__FeedbackMotor__data,  // get(index) function pointer
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__fetch_function__FeedbackMotor__data,  // fetch(index, &value) function pointer
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__assign_function__FeedbackMotor__data,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_members = {
  "serial_motor_demo_msgs__msg",  // message namespace
  "FeedbackMotor",  // message name
  1,  // number of fields
  sizeof(serial_motor_demo_msgs__msg__FeedbackMotor),
  serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_member_array,  // message members
  serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_init_function,  // function to initialize message memory (memory has to be allocated)
  serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_type_support_handle = {
  0,
  &serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_serial_motor_demo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serial_motor_demo_msgs, msg, FeedbackMotor)() {
  if (!serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_type_support_handle.typesupport_identifier) {
    serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &serial_motor_demo_msgs__msg__FeedbackMotor__rosidl_typesupport_introspection_c__FeedbackMotor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
