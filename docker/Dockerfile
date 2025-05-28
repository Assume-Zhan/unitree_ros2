FROM osrf/ros:humble-desktop-full

LABEL org.opencontainers.image.authors="assume0701@gmail.com"

ARG USERNAME=user

#############################################
# --- Basic setup ---
RUN apt-get update && apt-get install -y \
    sudo \
    vim \
    curl \
    tree \
    tmux && \
    rm -rf /var/lib/apt/lists/*

# Add user with default bash
RUN adduser --disabled-password --gecos '' --shell /bin/bash ${USERNAME} && \
    adduser ${USERNAME} sudo && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

#############################################
# --- Install ros packages ---
RUN apt-get update && apt-get install -y \
    ros-$ROS_DISTRO-joint-state-broadcaster \
    ros-$ROS_DISTRO-imu-tools \
    ros-$ROS_DISTRO-pointcloud-to-laserscan \
    ros-$ROS_DISTRO-realsense2-camera \
    ros-$ROS_DISTRO-pcl-ros \
    ros-$ROS_DISTRO-rmw-cyclonedds-cpp \
    ros-$ROS_DISTRO-rosidl-generator-dds-idl && \
    rm -rf /var/lib/apt/lists/*

# Login with user
USER ${USERNAME}

# Copy bashrc
COPY .bashrc /home/${USERNAME}/.bashrc

CMD ["bash"]