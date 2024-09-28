# Navros
Differential Drive Robot for Data Collection and Monitoring

## Index
1. [Overview](#overview)
2. [Hardware Setup](#hardware-setup)
3. [Circuit Diagram](#circuit-diagram)
4. [ROS2 Nodes](#ros2-nodes)
5. [Launch NavRos](#launch-navros)
6. [Additional Nodes](#additional-nodes)

## Overview
NavRos is a **differential drive robot** built for **real-time data collection and monitoring**, aimed at **improving the debugging experience** and providing better insights into system performance.

## Hardware Setup
- 2x N20 DC Motors
- TB6612FNG Dual Motor Driver
- ESP32
- Rasperry Pi 5
- 2x Wheels
- 3D Printed Chassis

# Circuit Diagram
<img src="images/circuit_diagram.png" width="50%" />

## ROS2 Nodes
Topics and Services for data monitoring
1. navros_motor_control
2. navros_motor_feedback
3. /diff_cont/cmd_vel_unstamped
4. /cone_detection/quadrant
5. /cone_detection/image
6. YOLOV8 OpenCV Cone Detection

<img src="https://github.com/omom77/NavRos/blob/cb0c5e8dab49c8249e7086d39273cd6f7c4299f5/images/cone_detected.png" width="50%"/>
5. Keyboard Controller
- Sub to this Topic: **/diff_cont/cmd_vel_unstamped**
- Control navros using keyboard

  # Circuit Diagram
  <img src="images/circuit_diagram.png" width="50%" />

# Launch Navros
**Step by step guide**
1. **Launch the Gazebo+Robot Simulation**
```
ros2 launch navros_bringup navros_drive.launch.xml 
```
2. **Keyboard Control**
```
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/diff_cont/cmd_vel_unstamped
```
# Additional Nodes
- **Cone Detection Model**
```
ros2 run navros_opencv navros_test2_opencv.py
```
ros2 run navros_remote navros_vel_sub_client.py 
```
### Subscriber to Read values from the DC Motor Encoder
```
ros2 run navros_remote navros_encoder_sub.py
```
