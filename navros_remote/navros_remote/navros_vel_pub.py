#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class NavrosVelPub(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("navros_vel_pub") # Executable MODIFY NAME
        self.get_logger().info("Initializing Communications....")
        self.navros_vel_pub_ = self.create_publisher(Twist, "cmd_vel_unstamped", 10)
        self.timer_ = self.create_timer(1.0, self.publish_hw_status)
        self.get_logger().info("Publishing to hardware_status_publisher")
        self.get_logger().info("Communication Established!")
        
    def publish_hw_status(self):
        twist_msg = Twist()
        twist_msg.linear.x= 0.5
        twist_msg.linear.y= 0.0
        twist_msg.linear.z= 0.0
        twist_msg.angular.x= 0.0
        twist_msg.angular.y= 0.0
        twist_msg.angular.z= 0.5 
        self.navros_vel_pub_.publish(twist_msg)

def main(args=None):
    rclpy.init(args=args)
    node = NavrosVelPub() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()