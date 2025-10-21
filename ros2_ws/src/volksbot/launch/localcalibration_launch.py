from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='sickcali',
            arguments=['0.12', '0', '0.24', '0', '0', '0', 'base_link', 'front_laser', '100']
        )

        # Node(
        #     package='tf2_ros',
        #     executable='static_transform_publisher',
        #     name='rieglcali',
        #     arguments=['-0.135', '0', '0.4325', '2.0943951', '0', '0', 'base_link', 'riegl', '100']
        # ),
        # Node(
        #     package='tf2_ros',
        #     executable='static_transform_publisher',
        #     name='xsenscali',
        #     arguments=['-0.17', '0', '0.18', '0', '3.14159265', '0', 'base_link', 'xsens', '100']
        # )

    ])