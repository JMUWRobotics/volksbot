from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='motor_controller',
            executable='motor_controller',
            output='log',
            name='motor_controller'
        )
    ])