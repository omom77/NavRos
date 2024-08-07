#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.srv import RunMotor
from geometry_msgs.msg import Twist
import serial

class NavrosArdService(Node):

    def __init__(self):
        super().__init__("navros_ard_service")

        self.service_ = self.create_service(RunMotor, 
                                            "test_navros_vel_server", 
                                            self.serviceCallback)
        self.get_logger().info("Navros Hardware Ready To Publish")

        self.publish_ = self.create_publisher(RunMotor, "test_navros_motor_feedback", )


    def serviceCallback(self, req, res):
        self.get_logger().info(req.motor_state)
        res.success = True
        self.arduino_.write(req.motor_state.encode("utf-8"))
        self.get_logger().info(str(res.success))
        return res


def main():
    rclpy.init()

    simple_service_server = NavrosArdService()
    rclpy.spin(simple_service_server)
    
    simple_service_server.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()