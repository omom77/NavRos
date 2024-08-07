#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.srv import RunMotor
from geometry_msgs.msg import Twist
from functools import partial

class NavrosVelSubClient(Node):

    def __init__(self):
        super().__init__("navros_vel_sub_client")

        self.get_logger().info("Initializing Communications....")
        self.navros_vel_pub_ = self.create_subscription(Twist, 
                                                        "/diff_cont/cmd_vel_unstamped", 
                                                        self.subCallback, 
                                                        10)
        self.get_logger().info("cmd_vel_unstamped : Communcations Initialized")
        
        # Initialize Linear x and Angular y
        self.lx = 0 
        self.az = 0

    def subCallback(self, msg):
        self.get_logger().info("Recieving Values")
        # twist_msg = Twist()
        lx = msg.linear.x
        az = msg.angular.z
        self.get_logger().info("Linear X: " + str(lx))
        self.get_logger().info("Angular Z: " + str(az))
        # self.lx = twist_msg.linear.x
        # self.az = twist_msg.angular.z
        self.clientCallback(motor_state=(lx, az))

    def clientCallback(self, motor_state):
        client = self.create_client(RunMotor, "test_navros_vel_server")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for navros_vel_server...")
        
        # Unpack the motor state tuple
        lx, az = motor_state

        request = RunMotor.Request()
        request.motor_state = "0"
        if(lx > 0):
            request.motor_state = "1"
        elif(lx < 0):
            request.motor_state = "2"
        elif(az > 0):
            request.motor_state = "3"
        elif(az < 0):
            request.motor_state = "4"

        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_client, motor_state=motor_state))

    def callback_client(self, future, motor_state):
        try:
            response = future.result()
            self.get_logger().info("Response: " + str(response.success))
            self.get_logger().info("Motor State Value: " + str(motor_state))
        except Exception as e:
            self.get_logger().error("service call failed %r" % (e,))

def main():
    rclpy.init()

    subscriber_client_server = NavrosVelSubClient()
    rclpy.spin(subscriber_client_server)
    
    subscriber_client_server.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()