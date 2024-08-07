// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serial_motor_demo_msgs:msg/FeedbackMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__BUILDER_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serial_motor_demo_msgs/msg/detail/feedback_motor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serial_motor_demo_msgs
{

namespace msg
{

namespace builder
{

class Init_FeedbackMotor_m_feedback
{
public:
  Init_FeedbackMotor_m_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serial_motor_demo_msgs::msg::FeedbackMotor m_feedback(::serial_motor_demo_msgs::msg::FeedbackMotor::_m_feedback_type arg)
  {
    msg_.m_feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_demo_msgs::msg::FeedbackMotor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_demo_msgs::msg::FeedbackMotor>()
{
  return serial_motor_demo_msgs::msg::builder::Init_FeedbackMotor_m_feedback();
}

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__BUILDER_HPP_
