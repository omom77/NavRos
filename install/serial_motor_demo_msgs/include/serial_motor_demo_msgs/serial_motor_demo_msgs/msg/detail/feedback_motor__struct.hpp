// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from serial_motor_demo_msgs:msg/FeedbackMotor.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__STRUCT_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__serial_motor_demo_msgs__msg__FeedbackMotor __attribute__((deprecated))
#else
# define DEPRECATED__serial_motor_demo_msgs__msg__FeedbackMotor __declspec(deprecated)
#endif

namespace serial_motor_demo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FeedbackMotor_
{
  using Type = FeedbackMotor_<ContainerAllocator>;

  explicit FeedbackMotor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int32_t, 3>::iterator, int32_t>(this->data.begin(), this->data.end(), 0l);
    }
  }

  explicit FeedbackMotor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int32_t, 3>::iterator, int32_t>(this->data.begin(), this->data.end(), 0l);
    }
  }

  // field types and members
  using _data_type =
    std::array<int32_t, 3>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::array<int32_t, 3> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator> *;
  using ConstRawPtr =
    const serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__serial_motor_demo_msgs__msg__FeedbackMotor
    std::shared_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__serial_motor_demo_msgs__msg__FeedbackMotor
    std::shared_ptr<serial_motor_demo_msgs::msg::FeedbackMotor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeedbackMotor_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeedbackMotor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeedbackMotor_

// alias to use template instance with default allocator
using FeedbackMotor =
  serial_motor_demo_msgs::msg::FeedbackMotor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__FEEDBACK_MOTOR__STRUCT_HPP_
