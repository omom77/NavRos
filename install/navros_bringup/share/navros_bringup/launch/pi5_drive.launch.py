from launch import LaunchDescription
from launch_ros.actions import Node
 
def generate_launch_description():
    ld = LaunchDescription()

    pi_arduino_server = Node(
        package="navros_remote",
        executable="navros_robot_controller_server.py",
        name= "pi_arduino_server"
    )

    pi_arduino_client = Node(
        package= "navros_remote",
        executable= "navros_vel_sub_client.py",
        name= "pi_arduino_client"
    )
    
    ld.add_action(pi_arduino_server)
    ld.add_action(pi_arduino_client)
    return ld

