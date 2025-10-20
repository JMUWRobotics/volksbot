from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='keyboard_driver',
            executable='kbcontrol',
            output='log',
            name='kbcontrol'
        )
    ])