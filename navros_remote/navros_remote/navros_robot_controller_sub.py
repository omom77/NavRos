#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist
import serial

class NavrosArdTransmitter(Node):
    def __init__(self):
        super().__init__("navros_ard_transmitter")

        self.declare_parameter("port", "/dev/ttyUSB0")
        self.declare_parameter("baudrate", 115200)

        self.port_ = self.get_parameter("port").value
        self.baudrate_ = self.get_parameter("baudrate").value

        self.sub_ = self.create_subscription(String, "navros_ard_control", self.msgCallback, 10)
        self.sub_
        self.arduino_ = serial.Serial(port=self.port_, baudrate=self.baudrate_, timeout=0.1)

    def msgCallback(self, msg):
        self.get_logger().info("New message received, publishing on serial: %s" % self.arduino_.name)
        self.get_logger().info(msg.data)
        self.arduino_.write(msg.data.encode("utf-8"))


def main():
    rclpy.init()

    navros_ard_transmitter = NavrosArdTransmitter()
    rclpy.spin(navros_ard_transmitter)
    
    navros_ard_transmitter.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()