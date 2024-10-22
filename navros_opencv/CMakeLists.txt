cmake_minimum_required(VERSION 3.8)
project(navros_opencv)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)

install(PROGRAMS
  ${PROJECT_NAME}/navros_test_opencv.py
  ${PROJECT_NAME}/navros_test2_opencv.py
  ${PROJECT_NAME}/navros_robot_controller_opencv_comms.py
  ${PROJECT_NAME}/navros_robot_controller_gazebo.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
