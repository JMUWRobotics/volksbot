cmake_minimum_required(VERSION 3.8)
project(keyboard_driver)

# include project wide configuration
include(${PROJECT_SOURCE_DIR}/../../cmake/project_config.cmake OPTIONAL)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(volksface REQUIRED)

# Define kbcontrol executable
add_executable(kbcontrol 
  src/kbcontrol.cc
)
set_target_properties(kbcontrol PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(kbcontrol
  std_msgs
  rclcpp
  volksface
)
target_link_libraries(kbcontrol "${cpp_typesupport_target}") 

# install executable
install(TARGETS
  kbcontrol
  DESTINATION lib/${PROJECT_NAME})

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
