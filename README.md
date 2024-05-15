# Gazebo + Real Robot Simulation using Keyboard Control - NavRos
### Console 1
- Run Gazebo Sim
```
ros2 launch navros_bringup navros_gazebo.launch.xml
```
### Console 2
- Navros Keyboard Control
```
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/diff_cont/cmd_vel_unstamped
```
### Console 3
- Send control requests to ROS-Arduino Bridge
```
ros2 run navros_remote navros_vel_sub_client.py 
```
### Console 4
- Server to communicate between Arduino & ROS using Serial
```
ros2 run navros_remote navros_robot_controller_server.py 
```
