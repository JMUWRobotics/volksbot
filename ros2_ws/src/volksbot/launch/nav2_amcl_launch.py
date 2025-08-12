import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    volksbot_dir = get_package_share_directory('volksbot')

    # first bringup map_server then amcl
    lifecycle_nodes = ['map_server', 'amcl']

    # define launch arguments as variables
    map_file = LaunchConfiguration('map')
    params_rovers = LaunchConfiguration('params_rovers')
    amcl_config = LaunchConfiguration('amcl_config')
    log_level = LaunchConfiguration('log_level')

    # declare launch arguments
    declare_map_file_cmd = DeclareLaunchArgument(
        'map',
        default_value=os.path.join(volksbot_dir, 'config', 'map_hallyway.yaml'),
        description='Path to map.yaml file, change to select desired map'
    )
    declare_params_rovers_cmd = DeclareLaunchArgument(
        'params_rovers',
        default_value=os.path.join(volksbot_dir, 'config', 'rovers.yaml'),
        description='Path to the parameters file for the different rovers'
    )
    declare_amcl_config_cmd = DeclareLaunchArgument(
        'amcl_config',
        default_value=os.path.join(volksbot_dir, 'config', 'amcl_config.yaml'),
        description='Path to the AMCL config file'
    )
    declare_log_level_cmd = DeclareLaunchArgument(
        'log_level',
        default_value='info',
        description='Sets logging level meaning which messages are printed on console'
    )

    # Map Server Node
    map_server_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[{'yaml_filename': map_file}],
        arguments=['--ros-args', '--log-level', log_level]
    )
    # AMCL Node
    amcl_node = Node(
        package='nav2_amcl',
        executable='amcl',
        name='amcl',
        output='screen',
        parameters=[params_rovers, amcl_config],
        remappings=[('scan', '/LMS')],
        arguments=['--ros-args', '--log-level', log_level]
    )
    # Lifecycle Manager Node: controls states of other nav2 nodes
    lifecycle_manager_node = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_localization',
        output='screen',
        parameters=[{
            'autostart': True,
            'node_names': lifecycle_nodes
        }],
        arguments=['--ros-args', '--log-level', log_level]
    )

    return LaunchDescription([
        # flushes log message after every line and not only when buffer is full
        SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'),

        # launch the cmds
        declare_map_file_cmd,
        declare_params_rovers_cmd,
        declare_amcl_config_cmd,
        declare_log_level_cmd,

        # launch the nodes
        map_server_node,
        amcl_node,
        lifecycle_manager_node
    ])