#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32MultiArray, Int32
from geometry_msgs.msg import Twist
import time

# NODE TO CONTROL THE PHYSICAL ROBOT ONLY 
# NOT THE GAZEBO SIMULATION!

class NavrosRobotControllerComms(Node):

    def __init__(self):
        super().__init__("navros_robot_controller_comms")

        # Timer time
        n = 0.5
        
        self.get_logger().info("Initializing Communications....")
        time.sleep(n)
        
        self.get_logger().info("Initializing : /cone_detection/quadrant")
        time.sleep(n)
        
        self.navros_vel_sub_ = self.create_subscription(Int32MultiArray, 
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

        # Call Publisher 
        self.get_logger().info(f"Received quadrant values: {msg.data}")

        # Iterate over the array and send each value as a control command
        for value in msg.data:
            self.pubCallback(value)

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
        self.get_logger().info(f"Sent control command: {control_command.data}")

def main(args=None):
    rclpy.init(args=args)
    node = NavrosRobotControllerComms() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()