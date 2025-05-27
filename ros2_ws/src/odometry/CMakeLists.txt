cmake_minimum_required(VERSION 3.8)
project(odometry)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(volksbot_interfaces REQUIRED)

include_directories(include)

# Define Odo library
add_library(odo src/odometry.cc)
ament_target_dependencies(odo 
  rclcpp 
  nav_msgs 
  geometry_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  volksbot_interfaces
)
target_link_libraries(odo "${cpp_typesupport_target}") 

# Define odometry executable
add_executable(odometry 
  src/odometry.cc 
  src/odometry_main.cc
)
set_target_properties(odometry PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(odometry
  rclcpp
  nav_msgs
  geometry_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  volksbot_interfaces
)
target_link_libraries(odometry "${cpp_typesupport_target}") 

# Install libraries
install(
  TARGETS odo
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# install executable
install(TARGETS
  odometry
  DESTINATION lib/${PROJECT_NAME})

# Install include directory
#install(DIRECTORY include/
#  DESTINATION include/${PROJECT_NAME}
#)

# export include directory
# if other packages includes the 'odometry' package, it automatically gets access to include
#ament_export_include_directories(include)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
