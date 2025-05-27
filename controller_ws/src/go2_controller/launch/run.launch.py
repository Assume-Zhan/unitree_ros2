from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.substitutions import Command, PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node, SetParameter
from ament_index_python.packages import get_package_share_directory

ARGUMENTS = [
    DeclareLaunchArgument(
        "use_sim_time",
        default_value="False",
        description="Use simulation time. (Gazebo)",
    ),
    DeclareLaunchArgument(
        "log_level",
        default_value="info",
        description="The ros logging level. Valid levels: debug, info, warn, error, fatal",
    ),
]


def generate_launch_description():

    # Set use_sim_time parameter
    use_sim_time = SetParameter(name="use_sim_time", value=LaunchConfiguration("use_sim_time"))

    remapping = [
        ("/cmd_vel", "/cmd_vel"),
        ("/api/sport/request", "/api/sport/request"),
    ]

    # Spawn Node
    launch_go2_controller_node = Node(
        package="go2_controller",
        executable="go2_controller_node",
        name="go2_controller_node",
        output="screen",
        remappings=remapping,
        arguments=["--ros-args", "--log-level", ["camera_buffer_node:=", LaunchConfiguration("log_level")]],
    )

    ld = LaunchDescription(ARGUMENTS)
    ld.add_action(use_sim_time)
    ld.add_action(launch_go2_controller_node)

    return ld