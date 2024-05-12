#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.srv import RunMotor
import serial

class NavrosArdService(Node):

    def __init__(self):
        super().__init__("navros_ard_service")

        self.declare_parameter("port", "/dev/ttyUSB0")
        self.declare_parameter("baudrate", 115200)

        self.port_ = self.get_parameter("port").value
        self.baudrate_ = self.get_parameter("baudrate").value

        self.service_ = self.create_service(RunMotor, "navros_vel_server", self.serviceCallback)
        self.get_logger().info("Navros Hardware Ready To Publish")

        self.arduino_ = serial.Serial(port=self.port_, baudrate=self.baudrate_, timeout=0.1)

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