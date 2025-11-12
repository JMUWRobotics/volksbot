cmake_minimum_required(VERSION 3.8)
project(gamepad_driver)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# include project wide configuration
include(${PROJECT_SOURCE_DIR}/../../cmake/project_config.cmake OPTIONAL)

# dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Threads REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(volksface REQUIRED)

add_executable(gamepad
  src/volksbot_adapter.cpp
  src/device_utils.cpp
  src/gamepad.cpp
  src/logitechf710.cpp
  src/xboxONE.cpp
)
ament_target_dependencies(gamepad rclcpp Threads geometry_msgs volksface)

# target_include_directories(gamepad PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>)
# target_compile_features(gamepad PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS gamepad
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
