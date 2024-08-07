// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from serial_motor_demo_msgs:srv/RunMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__TRAITS_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "serial_motor_demo_msgs/srv/detail/run_motor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace serial_motor_demo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const RunMotor_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_state
  {
    out << "motor_state: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RunMotor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_state: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RunMotor_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace serial_motor_demo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use serial_motor_demo_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const serial_motor_demo_msgs::srv::RunMotor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  serial_motor_demo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use serial_motor_demo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const serial_motor_demo_msgs::srv::RunMotor_Request & msg)
{
  return serial_motor_demo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<serial_motor_demo_msgs::srv::RunMotor_Request>()
{
  return "serial_motor_demo_msgs::srv::RunMotor_Request";
}

template<>
inline const char * name<serial_motor_demo_msgs::srv::RunMotor_Request>()
{
  return "serial_motor_demo_msgs/srv/RunMotor_Request";
}

template<>
struct has_fixed_size<serial_motor_demo_msgs::srv::RunMotor_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<serial_motor_demo_msgs::srv::RunMotor_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<serial_motor_demo_msgs::srv::RunMotor_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace serial_motor_demo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const RunMotor_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RunMotor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RunMotor_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace serial_motor_demo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use serial_motor_demo_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const serial_motor_demo_msgs::srv::RunMotor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  serial_motor_demo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use serial_motor_demo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const serial_motor_demo_msgs::srv::RunMotor_Response & msg)
{
  return serial_motor_demo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<serial_motor_demo_msgs::srv::RunMotor_Response>()
{
  return "serial_motor_demo_msgs::srv::RunMotor_Response";
}

template<>
inline const char * name<serial_motor_demo_msgs::srv::RunMotor_Response>()
{
  return "serial_motor_demo_msgs/srv/RunMotor_Response";
}

template<>
struct has_fixed_size<serial_motor_demo_msgs::srv::RunMotor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<serial_motor_demo_msgs::srv::RunMotor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<serial_motor_demo_msgs::srv::RunMotor_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<serial_motor_demo_msgs::srv::RunMotor>()
{
  return "serial_motor_demo_msgs::srv::RunMotor";
}

template<>
inline const char * name<serial_motor_demo_msgs::srv::RunMotor>()
{
  return "serial_motor_demo_msgs/srv/RunMotor";
}

template<>
struct has_fixed_size<serial_motor_demo_msgs::srv::RunMotor>
  : std::integral_constant<
    bool,
    has_fixed_size<serial_motor_demo_msgs::srv::RunMotor_Request>::value &&
    has_fixed_size<serial_motor_demo_msgs::srv::RunMotor_Response>::value
  >
{
};

template<>
struct has_bounded_size<serial_motor_demo_msgs::srv::RunMotor>
  : std::integral_constant<
    bool,
    has_bounded_size<serial_motor_demo_msgs::srv::RunMotor_Request>::value &&
    has_bounded_size<serial_motor_demo_msgs::srv::RunMotor_Response>::value
  >
{
};

template<>
struct is_service<serial_motor_demo_msgs::srv::RunMotor>
  : std::true_type
{
};

template<>
struct is_service_request<serial_motor_demo_msgs::srv::RunMotor_Request>
  : std::true_type
{
};

template<>
struct is_service_response<serial_motor_demo_msgs::srv::RunMotor_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERIAL_MOTOR_DEMO_MSGS__SRV__DETAIL__RUN_MOTOR__TRAITS_HPP_
