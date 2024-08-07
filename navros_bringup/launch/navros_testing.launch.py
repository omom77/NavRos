from launch import LaunchDescription
from launch_ros.actions import Node
 
def generate_launch_description():
    ld = LaunchDescription()

    navros_test_server = Node(
        package="navros_testing",
        executable="navros_test_server.py",
        name= "navros_test_server"
    )

    navros_test_client = Node(
        package= "navros_testing",
        executable= "navros_test_client.py",
        name= "navros_test_client"
    )

    # navros_test_feedback_motor = Node(
    #     package= "navros_testing",
    #     executable= "navros_test_feedback_motor.py",
    #     name= "navros_test_feedback_motor"
    # )
    
    ld.add_action(navros_test_server)
    ld.add_action(navros_test_client)
    # ld.add_action(navros_test_feedback_motor)
    return ld

