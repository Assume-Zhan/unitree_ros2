#!/bin/bash -e

SCRIPT_DIR=$(dirname "$0")
CYCLONEDDS_WS_DIR="/home/user/workspace/cyclonedds_ws"
EXAMPLE_WS_DIR="/home/user/workspace/example"
SETUP_SCRIPT="/home/user/workspace/setup.sh"

# Cloning CycloneDDS repository
if [ -d "/home/user/workspace/cyclonedds_ws/src/cyclonedds" ]; then
    echo "[CYCLONEDDS_WS]: Directory cyclonedds exists, skipping clone."
else
    echo "[CYCLONEDDS_WS]: Directory cyclonedds does not exist, cloning..."
    cd "$CYCLONEDDS_WS_DIR/src"
    git clone https://github.com/eclipse-cyclonedds/cyclonedds -b releases/0.10.x 
fi

# Cloning RMW CycloneDDS repository
if [ -d "/home/user/workspace/cyclonedds_ws/src/rmw_cyclonedds" ]; then
    echo "[CYCLONEDDS_WS]: Directory rmw_cyclonedds exists, skipping clone."
else
    echo "[CYCLONEDDS_WS]: Directory rmw_cyclonedds does not exist, cloning..."
    cd "$CYCLONEDDS_WS_DIR/src"
    git clone https://github.com/ros2/rmw_cyclonedds -b humble
fi

# Building CycloneDDS workspace
if [ -d "$CYCLONEDDS_WS_DIR/install" ]; then
    echo "[CYCLONEDDS_WS]: CycloneDDS package already built, skipping build."
else
    echo "[CYCLONEDDS_WS]: Building CycloneDDS workspace..."
    cd "$CYCLONEDDS_WS_DIR"
    colcon build --packages-select cyclonedds
fi

# Sourcing ROS2 environment
source /opt/ros/humble/setup.bash

# Build the remaining packages in the CycloneDDS workspace
if [ -d "$CYCLONEDDS_WS_DIR/install/unitree_api" ]; then
    echo "[CYCLONEDDS_WS]: CycloneDDS workspace already built, skipping build."
else
    echo "[CYCLONEDDS_WS]: Building remaining packages in CycloneDDS workspace..."
    cd "$CYCLONEDDS_WS_DIR"
    colcon build
fi

# Source the setup script
if [ -f "$SETUP_SCRIPT" ]; then
    echo "[SETUP]: Sourcing setup script..."
    source "$SETUP_SCRIPT"
else
    echo "[SETUP]: Setup script not found, skipping sourcing."
fi

# Build the example workspace
if [ -d "$EXAMPLE_WS_DIR/build" ]; then
    echo "[EXAMPLE_WS]: Example workspace already built, skipping build."
else
    echo "[EXAMPLE_WS]: Building example workspace..."
    cd "$EXAMPLE_WS_DIR"
    colcon build
fi