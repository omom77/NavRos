#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int8.h>
#include <std_msgs/msg/int8.h>

std_msgs__msg__Int8 msg;
std_msgs__msg__Int8 left_motor_msg;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

rcl_subscription_t motor_control_subscriber;
rcl_publisher_t motor_feedback_publisher;

#define LED_PIN 13

#define mB1 32
#define mB2 33
#define mBEn 25
 
#define mA1 12
#define mA2 14
#define mAEn 26

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}


void error_loop(){
  while(1){
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}

void forward(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);
 
  digitalWrite(mA1, HIGH);
  digitalWrite(mA2, LOW);
   
  digitalWrite(mB1, HIGH);
  digitalWrite(mB2, LOW);
  delay(1000); 
   
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
}
void reverse(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);

  digitalWrite(mA1, LOW);
  digitalWrite(mA2, HIGH);
  
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
  delay(1000);

  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
}

void left(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);
  
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
 
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
  delay(1000);

  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
}

void right(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);
  
  digitalWrite(mA1, HIGH);
  digitalWrite(mA2, LOW);

  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
  delay(1000);

  digitalWrite(mA1,LOW);
  digitalWrite(mA2,LOW);
  digitalWrite(mB1,LOW);
  digitalWrite(mB2,LOW);
}

void subscription_callback(const void * msgin)
{  
  const std_msgs__msg__Int8 * msg = (const std_msgs__msg__Int8 *)msgin;
  // digitalWrite(LED_PIN, (msg->data == 0) ? LOW : HIGH);  
  int8_t value = msg->data;
  switch (value) {
    case 1:
      forward(200, 200);
      break;
    case 2:
      reverse(200, 200);
      break;
    case 3:
      left(200, 200);
      break;
    case 4:
      right(200, 200);
      break;
  }
}

void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
  RCSOFTCHECK(rcl_publish(&motor_feedback_publisher, &left_motor_msg, NULL));
  left_motor_msg.data++;
}

void setup() {
  set_microros_transports();
  // set_microros_wifi_transports("Airtel network", "greenfield", "192.168.1.24", 8888);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  

  pinMode(mA1,OUTPUT);
  pinMode(mA2,OUTPUT);
  pinMode(mAEn,OUTPUT);

  pinMode(mB1,OUTPUT);
  pinMode(mB2,OUTPUT);
  pinMode(mBEn,OUTPUT);
  
  delay(2000);

  allocator = rcl_get_default_allocator();

  // Create support object
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node "node_name"
  RCCHECK(rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support));

  // Create motor_control_subscriber topic
  RCCHECK(rclc_subscription_init_default(
    &motor_control_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
    "navros_motor_control"));
  
  // Create motor_feedback_publisher topic
  RCCHECK(rclc_publisher_init_default(
    &motor_feedback_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
    "navros_motor_feedback"));

  // Create timer
  const unsigned int timer_timeout = 1000;
  RCCHECK(rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(timer_timeout),
    timer_callback));

  // Add Timer

  // create executor
  // Dont need executor for publisher
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &motor_control_subscriber, &msg, &subscription_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));

  // Initialize feedback message
  left_motor_msg.data = 1;
}

void loop() {
  delay(100);
  RCCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
}

  // Try the below code in the motor_control_subscriber if something goes wrong
  // int pwmA = 200;
  // analogWrite(mAEn, pwmA);
  // digitalWrite(mA1, HIGH);
  // digitalWrite(mA2, LOW);  
  // delay(200);
  // digitalWrite(mA1, LOW);  
  // digitalWrite(mA2, LOW);
