#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32MultiArray
from geometry_msgs.msg import Twist

class NavrosRobotControllerComms(Node):

    def __init__(self):
        super().__init__("navros_robot_controller_comms")

        self.get_logger().info("Initializing Communications...")

        # Create subscription to receive quadrant data
        self.navros_vel_sub_ = self.create_subscription(
            Int32MultiArray, "/cone_detection/quadrant", self.subCallback, 10)

        # Publisher to send velocity commands
        self.cmd_vel_publisher_ = self.create_publisher(
            Twist, "/diff_cont/cmd_vel_unstamped", 10)

        self.get_logger().info("Node Ready: Communications Established!")

    def subCallback(self, msg):
        self.get_logger().info(f"Received quadrant values: {msg.data}")

        # Iterate over the received commands and send appropriate velocities
        for value in msg.data:
            self.pubCallback(value)

    def pubCallback(self, quadrant):
        twist = Twist()

        if quadrant == 1:  # Forward
            twist.linear.x = 1.0
            twist.angular.z = 0.0
        elif quadrant == 2:  # Reverse
            twist.linear.x = -1.0
            twist.angular.z = 0.0
        elif quadrant == 3:  # Left
            twist.linear.x = 0.0
            twist.angular.z = 1.0
        elif quadrant == 4:  # Right
            twist.linear.x = 0.0
            twist.angular.z = -1.0
        else:  # Default stop
            twist.linear.x = 0.0
            twist.angular.z = 0.0

        # Publish the Twist message
        self.cmd_vel_publisher_.publish(twist)
        self.get_logger().info(f"Sent velocity command: {twist}")

def main(args=None):
    rclpy.init(args=args)
    node = NavrosRobotControllerComms()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
