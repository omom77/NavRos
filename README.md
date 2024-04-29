# Launch Simulated Robot
To launch the gazebo & Rviz simulation of the robot
~~~
ros2 launch parrot_v1_bringup simulation.launch.py
~~~

# Launch Real Robot
To launch the gazebo & Rviz simulation of the robot
~~~
ros2 launch parrot_v1_bringup real.launch.py
~~~

# Launch Task server to send commands to the gazebo and real robot
~~~
ros2 service send_goal
~~~

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
