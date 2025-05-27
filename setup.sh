#!/bin/bash
echo "Setup unitree ros2 environment"
source /opt/ros/humble/setup.bash
source $HOME/workspace/cyclonedds_ws/install/setup.bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export CYCLONEDDS_URI='<CycloneDDS><Domain><General><Interfaces>
                            <NetworkInterface name="enp4s0" priority="100" multicast="default" />
                        </Interfaces></General></Domain></CycloneDDS>'

# # Debug for CyCloneDDS settings
# export CYCLONEDDS_URI='<CycloneDDS><Domain>
#                          <General><Interfaces>
#                            <NetworkInterface name="enp4s0" priority="3" multicast="default" />
#                          </Interfaces></General>
#                          <Tracing>
#                            <Verbosity>finest</Verbosity>
#                          </Tracing>
#                        </Domain></CycloneDDS>'