# Use the official ROS 2 Humble base image
FROM ros:humble

# Set environment variables
ENV ROS_DOMAIN_ID=0
ENV ROS_NAMESPACE=pi5_drive

# Create a workspace directory
RUN mkdir -p /opt/navros_ws/src

# Set the working directory
WORKDIR /opt/navros_ws/src

# Copy your package files into the container (assumes local package is in the context)
COPY . .

# Update apt repositories and install necessary dependencies
RUN apt-get update && apt-get install -y \
    python3-rosdep \
    && rm -rf /var/lib/apt/lists/*

# Initialize rosdep, removing the default sources list file if it exists
RUN rm -f /etc/ros/rosdep/sources.list.d/20-default.list && \
    rosdep init && \
    rosdep update

# Install the package dependencies
RUN rosdep install -y --from-paths . --ignore-src

# Build the ROS 2 workspace
WORKDIR /opt/navros_ws
RUN . /opt/ros/humble/setup.sh && colcon build --symlink-install

# Source the setup script
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "source /opt/navros_ws/install/setup.bash" >> ~/.bashrc

# Set the entrypoint to the ros2 command
ENTRYPOINT ["/ros_entrypoint.sh"]

# Run the command to launch the desired ROS 2 launch file
CMD ["ros2", "launch", "navros_bringup", "pi5_drive.launch.xml"]
