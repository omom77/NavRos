// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from serial_motor_demo_msgs:msg/FeedbackMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__TRAITS_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "serial_motor_demo_msgs/msg/detail/feedback_motor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace serial_motor_demo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeedbackMotor & msg,
  std::ostream & out)
{
  out << "{";
  // member: m_feedback
  {
    out << "m_feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.m_feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeedbackMotor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: m_feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m_feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.m_feedback, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeedbackMotor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace serial_motor_demo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use serial_motor_demo_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const serial_motor_demo_msgs::msg::FeedbackMotor & msg,
  std::ostream & out, size_t indentation = 0)
{
  serial_motor_demo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use serial_motor_demo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const serial_motor_demo_msgs::msg::FeedbackMotor & msg)
{
  return serial_motor_demo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<serial_motor_demo_msgs::msg::FeedbackMotor>()
{
  return "serial_motor_demo_msgs::msg::FeedbackMotor";
}

template<>
inline const char * name<serial_motor_demo_msgs::msg::FeedbackMotor>()
{
  return "serial_motor_demo_msgs/msg/FeedbackMotor";
}

template<>
struct has_fixed_size<serial_motor_demo_msgs::msg::FeedbackMotor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<serial_motor_demo_msgs::msg::FeedbackMotor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<serial_motor_demo_msgs::msg::FeedbackMotor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__TRAITS_HPP_
