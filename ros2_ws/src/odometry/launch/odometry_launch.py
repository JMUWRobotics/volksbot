from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='odometry',
            executable='odometry',
            output='log',
            name='odometry',
            arguments=['1']
        )
    ])