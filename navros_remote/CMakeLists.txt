cmake_minimum_required(VERSION 3.8)
project(navros_remote)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(serial_motor_demo_msgs REQUIRED)
find_package(PkgConfig)
# find_package(functools)
pkg_check_modules(SERIAL libserial)
# find_package(tf2 REQUIRED)

install(PROGRAMS
  ${PROJECT_NAME}/navros_vel_pub.py
  ${PROJECT_NAME}/navros_robot_controller_pub.py
  ${PROJECT_NAME}/navros_robot_controller_server.py
  ${PROJECT_NAME}/navros_vel_sub_client.py
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch  
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
