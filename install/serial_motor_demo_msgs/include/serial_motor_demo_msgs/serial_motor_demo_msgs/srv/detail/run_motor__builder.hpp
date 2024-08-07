// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serial_motor_demo_msgs:srv/RunMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__BUILDER_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serial_motor_demo_msgs/srv/detail/run_motor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serial_motor_demo_msgs
{

namespace srv
{

namespace builder
{

class Init_RunMotor_Request_motor_state
{
public:
  Init_RunMotor_Request_motor_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serial_motor_demo_msgs::srv::RunMotor_Request motor_state(::serial_motor_demo_msgs::srv::RunMotor_Request::_motor_state_type arg)
  {
    msg_.motor_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_demo_msgs::srv::RunMotor_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_demo_msgs::srv::RunMotor_Request>()
{
  return serial_motor_demo_msgs::srv::builder::Init_RunMotor_Request_motor_state();
}

}  // namespace serial_motor_demo_msgs


namespace serial_motor_demo_msgs
{

namespace srv
{

namespace builder
{

class Init_RunMotor_Response_success
{
public:
  Init_RunMotor_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serial_motor_demo_msgs::srv::RunMotor_Response success(::serial_motor_demo_msgs::srv::RunMotor_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_demo_msgs::srv::RunMotor_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_demo_msgs::srv::RunMotor_Response>()
{
  return serial_motor_demo_msgs::srv::builder::Init_RunMotor_Response_success();
}

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__BUILDER_HPP_
