cmake_minimum_required(VERSION 3.8)
project(volksface)

# include project wide configuration
include(${PROJECT_SOURCE_DIR}/../../cmake/project_config.cmake OPTIONAL)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

set(msg_files
  "msg/Gamepad.msg"
  "msg/GpThumbStick.msg"
  "msg/MCTicks.msg"
  "msg/Pose2d.msg"
  "msg/WheelMapping.msg"
  "msg/Rover.msg"
  "msg/VelGP.msg"
)

set(srv_files
  "srv/Rumble.srv"
  "srv/VelCmd.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  DEPENDENCIES std_msgs 
  # DEPENDENCIES geometry_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)

# Install include directory
install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

# Exportiere den include-Pfad
ament_export_include_directories(include)

# Export für andere Packages (z. B. Interfaces)
ament_export_dependencies(rosidl_default_runtime)

ament_package()
