#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8, Int32
from geometry_msgs.msg import Twist
import time

class NavrosRobotControllerComms(Node):

    def __init__(self):
        super().__init__("navros_robot_controller_comms")

        # Timer time
        n = 0.5
        self.get_logger().info("Initializing Communications....")
        time.sleep(n)
        
        self.get_logger().info("Initializing : /cone_detection/quadrant")
        time.sleep(n)
        
        self.navros_vel_pub_ = self.create_subscription(Int8, 
                                                        "/cone_detection/quadrant", 
                                                        self.subCallback, 
                                                        10)
        
        self.get_logger().info("Communcations Initialized : /cone_detection/quadrant")
        time.sleep(n)

        self.get_logger().info("Initializing /navros_motor_control")

        self.navros_motor_control_ = self.create_publisher(Int32, 
                                                           "/navros_motor_control", 
                                                           10)
        
        self.get_logger().info("Communication Initialized : /navros_motor_feedback")
        time.sleep(n)
        self.get_logger().info("Node Ready : Communications Established !")

        self.quadrant 

    def subCallback(self, msg):
        self.get_logger().info("Recieving Values")
        # twist_msg = Twist()
        quadrant = msg.Int8
        self.get_logger().info("Linear X: " + str(quadrant))

        # Call Publisher 
        self.pubCallback(quadrant)

    def pubCallback(self, quadrant):
        # Unpack Motor State Tuple
        control_command = Int32()

        # Forward
        if quadrant == 1:
            control_command.data = 1

        # Reverse
        elif quadrant == 2:
            control_command.data = 2
        
        # Left
        elif quadrant == 3:
            control_command.data = 3
        
        # Right
        elif quadrant == 4:
            control_command.data = 4

        # Right
        # elif quadrant == 4:
            # control_command.data = 4

        # Publish
        self.navros_motor_control_.publish(control_command)

def main(args=None):
    rclpy.init(args=args)
    node = NavrosRobotControllerComms() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()