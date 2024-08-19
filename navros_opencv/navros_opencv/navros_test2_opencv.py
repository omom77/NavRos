#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO
import cv2
import numpy as np
import math
class NavrosConeDetector(Node):
        def __init__(self):
            super().__init__('cone_detector')
            self.publisher_ = self.create_publisher(Image, 'cone_detection', 10)
            self.timer = self.create_timer(0.5, self.timer_callback)
            self.bridge = CvBridge()

            self.model = YOLO('/home/om/navros_ws/src/navros_opencv/yolov8_weights/best.pt') 

            self.width = 640
            self.height = 480

            # Initialize camera stream
            self.cap = cv2.VideoCapture(0)
            self.cap.set(3, self.width)
            self.cap.set(4, self.height)

            self.fontScale = 1
            self.font = cv2.FONT_HERSHEY_SIMPLEX
            self.thickness = 2
            self.color = (255, 0, 0)

            # // for integer division
            # { "quadrant_n: [(x1, y1), (x2, y2), "text coordinates"]"}
            self.quadrants = {
            "q1": [(self.width//2, 0), 
                    (self.width, self.height//2), 
                    (0, 255, 0), 
                    ((self.width//2), 30)],
            "q2": [(0, 0), 
                    (self.width//2, self.height//2), 
                    (255, 255, 0), 
                    (0, 30)],
            "q3": [(0, self.height//2), 
                    (self.width//2, self.height-100), 
                    (0, 0, 255), 
                    (0, (self.height//2)+30)],
            "q4": [(self.width//2, self.height//2), 
                    (self.width, self.height-100), 
                    (255,0,0), 
                    (self.width//2, (self.height//2)+30)],
            "q5": [(0, self.height-100), 
                    (self.width, self.height), 
                    (0,255, 255),
                    (0, self.height-20)]
            }

        # publisher callback function
        def timer_callback(self):
            ret, img = self.cap.read()
            if not ret:
                self.get_logger().error("Failed to capture image")
                return
            
            # Perform inference
            results = self.model(img)

            # Create the 4 Quadrants
            for i, (key, coords) in enumerate(self.quadrants.items()):
                cv2.rectangle(
                    img, 
                    coords[0], 
                    coords[1], 
                    coords[2]
                    )
                # print quadrant number - i+1
                cv2.putText(
                    img, 
                    str(i+1), 
                    coords[3], 
                    self.font, 
                    self.fontScale, 
                    self.color, 
                    self.thickness
                    )
                
            for r in results:
                boxes = r.boxes

                for box in boxes:
                    # Bounding box coordinates
                    x1, y1, x2, y2 = box.xyxy[0]
                    x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)

                    # Midpoint of the bounding box
                    bb_center = [(x1 + x2) / 2, (y1 + y2) / 2]

                    # Assign quadrant to the detected cone
                    for i, (key, coords) in enumerate(self.quadrants.items()):
                        x1_y1_top = coords[0]
                        x2_y2_bottom = coords[1]
                        if (x1_y1_top[0] <= bb_center[0] < x2_y2_bottom[0]) and (
                            x1_y1_top[1] <= bb_center[1] < x2_y2_bottom[1]):
                            print(f"Cone in Quadrant: {i + 1}")

                    # Draw bounding box and label
                    cv2.rectangle(img, (x1, y1), (x2, y2), (255, 0, 255), 3)

                    confidence = math.ceil((box.conf[0] * 100)) / 100
                    print(f"Confidence: {confidence}")

                    cls = int(box.cls[0])
                    class_name = "cone"
                    print(f"Class name: {class_name}")

                    cv2.putText(
                        img, 
                        class_name, 
                        (x1, y1), 
                        self.font, 
                        self.fontScale, 
                        self.color, 
                        self.thickness
                        )


            # Annotate image with bounding boxes
            # annotated_img = results[0].plot()

            # Convert to ROS2 Image message and publish
            ros_image = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
            self.publisher_.publish(ros_image)
                
def main(args=None):
    rclpy.init(args=args)
    node = NavrosConeDetector() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()