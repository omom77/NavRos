#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from serial_motor_demo_msgs.msg import FeedbackMotor    


class NavrosVelPub(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("navros_test_feedback_motor") # Executable MODIFY NAME
        self.get_logger().info("Initializing Communications....")

        self.navros_test_sub = self.create_subscription()

        self.navros_vel_pub_ = self.create_publisher(FeedbackMotor, "test_feedback_motor", 10)
        self.timer_ = self.create_timer(1.0, self.publish_vel)

        self.get_logger().info("Publishing to hardware_status_publisher")
        self.get_logger().info("Communication Established!")

    motor_reading = 360

    def publish_vel(self):
        test_feedback_msg = FeedbackMotor()
        
        self.m1_f = self.motor_reading + 180
        self.m2_f = self.motor_reading + 180
        test_feedback_msg.m_feedback = self.motor_reading
        self.navros_vel_pub_.publish(test_feedback_msg)

def main(args=None):
    rclpy.init(args=args)
    node = NavrosVelPub() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()