#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
from geometry_msgs.msg import Twist
import time

class NavrosRobotControllerComms(Node):

    def __init__(self):
        super().__init__("navros_robot_controller_comms")

        # Timer time
        n = 0.5
        self.get_logger().info("Initializing Communications....")
        time.sleep(n)
        
        self.get_logger().info("Initializing : /diff_cont/cmd_vel_unstamped")
        time.sleep(n)
        
        self.navros_vel_pub_ = self.create_subscription(Twist, 
                                                        "/diff_cont/cmd_vel_unstamped", 
                                                        self.subCallback, 
                                                        10)
        
        self.get_logger().info("Communcations Initialized : /diff_cont/cmd_vel_unstamped")
        time.sleep(n)

        self.get_logger().info("Initializing /navros_motor_control")

        self.navros_motor_control_ = self.create_publisher(Int8, 
                                                           "/navros_motor_control", 
                                                           10)
        
        self.get_logger().info("Communication Initialized : /navros_motor_feedback")
        time.sleep(n)
        self.get_logger().info("Node Ready : Communications Established !")

        self.lx = 0
        self.az = 0

    def subCallback(self, msg):
        self.get_logger().info("Recieving Values")
        # twist_msg = Twist()
        lx = msg.linear.x
        az = msg.angular.z
        self.get_logger().info("Linear X: " + str(lx))
        self.get_logger().info("Angular Z: " + str(az))

        # Call Publisher 
        self.pubCallback(motor_state= (lx, az))

    def pubCallback(self, motor_state):
        # Unpack Motor State Tuple
        lx, az = motor_state
        control_command = Int8()

        # Forward
        if lx > 0:
            control_command.data = 1

        # Reverse
        elif lx < 0:
            control_command.data = 2
        
        # Left
        elif az > 0:
            control_command.data = 3
        
        # Right
        elif az < 0:
            control_command.data = 4

        # Publish
        self.navros_motor_control_.publish(control_command)

def main(args=None):
    rclpy.init(args=args)
    node = NavrosRobotControllerComms() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()