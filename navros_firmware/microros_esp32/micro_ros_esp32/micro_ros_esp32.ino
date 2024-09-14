#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>
#include <std_msgs/msg/int32_multi_array.h>


rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

rcl_publisher_t motor_feedback_publisher;
std_msgs__msg__Int32MultiArray feedback_msg;
rclc_executor_t executor_pub;
rcl_timer_t timer;

rcl_subscription_t motor_control_subscriber;
std_msgs__msg__Int32 msg;
rclc_executor_t executor_sub;


#define LED_PIN 13


#define mB1 32
#define mB2 33
#define mBEn 25
#define ENCODERB_A 16 // Pin for EncoderB A
#define ENCODERB_B 17 // Pin for EncoderB B
 
// Global variable for storing the encoder position
volatile int A_encoder_value = 0;
volatile int B_encoder_value = 0;

#define mA1 12
#define mA2 14
#define mAEn 26
#define ENCODERA_A 18 // Pin for EncoderB A
#define ENCODERA_B 19 // Pin for EncoderB B

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
   
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
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
  
  digitalWrite(mB1, HIGH);
  digitalWrite(mB2, LOW);
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

void encoder_isr_A() {
  // Reading the current state of encoder A and B
  int A = digitalRead(ENCODERA_A);
  int B = digitalRead(ENCODERA_B);
  // If the state of A changed, it means the encoder has been rotated
  if ((A == HIGH) != (B == LOW)) {
    A_encoder_value--;
  } else {
    A_encoder_value++;
  }
}

void encoder_isr_B() {
  // Reading the current state of encoder A and B
  int A = digitalRead(ENCODERB_A);
  int B = digitalRead(ENCODERB_B);
  // If the state of A changed, it means the encoder has been rotated
  if ((A == HIGH) != (B == LOW)) {
    B_encoder_value--;
  } else {
    B_encoder_value++;
  }
}

void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  RCLC_UNUSED(last_call_time);
  if (timer != NULL)
  {
    feedback_msg.data.data[0] = A_encoder_value;
    feedback_msg.data.data[1] = B_encoder_value;
    RCSOFTCHECK(rcl_publish(&motor_feedback_publisher, &feedback_msg, NULL));
  }
}


void subscription_callback(const void * msgin)
{  
  const std_msgs__msg__Int32 * msg = (const std_msgs__msg__Int32 *)msgin;
  // digitalWrite(LED_PIN, (msg->data == 0) ? LOW : HIGH);  
  int32_t value = msg->data;
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

void setup() {
  // set_microros_transports();
  set_microros_wifi_transports("Airtel network", "greenfield", "192.168.1.13", 8888);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  

  pinMode(mA1,OUTPUT);
  pinMode(mA2,OUTPUT);
  pinMode(mAEn,OUTPUT);

  pinMode(ENCODERA_A, INPUT_PULLUP);
  pinMode(ENCODERA_B, INPUT_PULLUP);

  pinMode(mB1,OUTPUT);
  pinMode(mB2,OUTPUT);
  pinMode(mBEn,OUTPUT);

  pinMode(ENCODERB_A, INPUT_PULLUP);
  pinMode(ENCODERB_B, INPUT_PULLUP);
  
  delay(2000);

  attachInterrupt(digitalPinToInterrupt(ENCODERA_A), encoder_isr_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODERB_A), encoder_isr_B, CHANGE);

  allocator = rcl_get_default_allocator();

  // Create support object, Create Init options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node "node_name"
  RCCHECK(rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support));

  // Create motor_control_subscriber topic
  RCCHECK(rclc_subscription_init_default(
    &motor_control_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "navros_motor_control"));

  // create publisher
  RCCHECK(rclc_publisher_init_default(
      &motor_feedback_publisher,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32MultiArray),
      "navros_motor_feedback"));

  // Initialize the array message with 3 elements
  std_msgs__msg__Int32MultiArray__init(&feedback_msg);
  feedback_msg.data.data = (int32_t*) malloc(2 * sizeof(int32_t));
  feedback_msg.data.size = 2;
  feedback_msg.data.capacity = 2;
  
  // create timer, called every 1000 ms to publish heartbeat
  const unsigned int timer_timeout = 1000;
  RCCHECK(rclc_timer_init_default(
      &timer,
      &support,
      RCL_MS_TO_NS(timer_timeout),
      timer_callback));

  // create executor
  RCCHECK(rclc_executor_init(&executor_pub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor_pub, &timer));

  RCCHECK(rclc_executor_init(&executor_sub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor_sub, &motor_control_subscriber, &msg, &subscription_callback, ON_NEW_DATA));
}

void loop() {
  delay(100);
  RCCHECK(rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(100)));
  RCCHECK(rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(100)));
}

  // Try the below code in the motor_control_subscriber if something goes wrong
  // int pwmA = 200;
  // analogWrite(mAEn, pwmA);
  // digitalWrite(mA1, HIGH);
  // digitalWrite(mA2, LOW);  
  // delay(200);
  // digitalWrite(mA1, LOW);  
  // digitalWrite(mA2, LOW);
