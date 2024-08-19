#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO
import cv2
import numpy as np
class NavrosConeDetector(Node):
        def __init__(self):
            super().__init__('cone_detector')
            self.publisher_ = self.create_publisher(Image, 'cone_detection', 10)
            self.timer = self.create_timer(0.5, self.timer_callback)
            self.bridge = CvBridge()

            self.model = YOLO('/home/om/navros_ws/src/navros_opencv/yolov8_weights/best.pt') 

            # Initialize camera stream
            self.cap = cv2.VideoCapture(0)
            self.cap.set(3, 640)
            self.cap.set(4, 480)

        def timer_callback(self):
            ret, img = self.cap.read()
            if not ret:
                self.get_logger().error("Failed to capture image")
                return
            
            # Perform inference
            results = self.model(img)

            # Annotate image with bounding boxes
            annotated_img = results[0].plot()

            # Convert to ROS2 Image message and publish
            ros_image = self.bridge.cv2_to_imgmsg(annotated_img, encoding="bgr8")
            self.publisher_.publish(ros_image)
                
def main(args=None):
    rclpy.init(args=args)
    node = NavrosConeDetector() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()