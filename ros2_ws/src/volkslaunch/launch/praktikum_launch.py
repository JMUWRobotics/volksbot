import os
from launch import LaunchDescription
from launch_ros.actions import Node # located at /opt/ros/humble/share
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    
    # volksbot node is started separately

    # volksbot_nodes = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([os.path.join(
    #         get_package_share_directory('volksbot'), 'launch'),
    #         '/volksbot_launch.py']
    #     )
    # ),

    gamepad_nodes = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('gamepad_driver'), 'launch'),
            '/gamepad_driver_launch.py']
        )
    )

    lms_nodes = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('lms_starter'), 'launch'),
            '/lms_starter_launch.py']
        )
    )

    motor_controller_nodes = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('motor_controller'), 'launch'),
            '/motor_controller_launch.py']
        )
    )

    return LaunchDescription([

        # launch files
        gamepad_nodes,
        lms_nodes,
        motor_controller_nodes

    ])