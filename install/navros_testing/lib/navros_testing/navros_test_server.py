#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.srv import RunMotor
from serial_motor_demo_msgs.msg import FeedbackMotor
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
import serial

class NavrosArdService(Node):

    def __init__(self):
        super().__init__("navros_test_server")

        self.service_ = self.create_service(RunMotor, 
                                            "test_navros_vel_server", 
                                            self.serviceCallback)
        self.get_logger().info("Navros Hardware Ready To Publish")

        # Create publisher to publish the motor command
        self.publish_ = self.create_publisher(FeedbackMotor, "test_navros_motor_feedback", 10)
        self.get_logger().info("test_navros_motor_feedback publisher initialized")

    def serviceCallback(self, req, res):

        # Print the command number and success status
        self.get_logger().info(req.motor_state)
        res.success = True
        self.get_logger().info(str(res.success))

        motor_state = FeedbackMotor()
        motor_state.data = [int(req.motor_state), 0, 0]

        if(int(req.motor_state) == 1):
            motor_state.data = [int(req.motor_state), 180, 180]

        if(int(req.motor_state) == 2):
            motor_state.data = [int(req.motor_state), -180, -180]

        if(int(req.motor_state) == 3):
            motor_state.data = [int(req.motor_state), 90, 180]

        if(int(req.motor_state) == 4):
            motor_state.data = [int(req.motor_state),180, 90]    
        # Publish the executed command number
        self.publish_.publish(motor_state)

        return res


def main():
    rclpy.init()

    simple_service_server = NavrosArdService()
    rclpy.spin(simple_service_server)
    
    simple_service_server.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()