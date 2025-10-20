from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gamepad_driver',
            executable='gamepad',
            output='log',
            name='gamepad'
        )
    ])