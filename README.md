# Gazebo Sim - NavRos
Run the following commands to launch the gazebo and rviz navros simulations
```
ros2 launch navros_bringup navros_gazebo.launch.xml
```
In Another Console

Use the following command to control the navros gazebo simulation using keyboard inputs
```
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/diff_cont/cmd_vel_unstamped
```
