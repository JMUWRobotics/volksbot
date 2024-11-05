cmake_minimum_required(VERSION 3.5)
project(volksbot)

# Add standard ROS 2 compile options
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Set C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find necessary ROS 2 packages
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
#find_package(volksbot REQUIRED)

# Define ROS 2 messages and services
rosidl_generate_interfaces(
    ${PROJECT_NAME}
    srv/Velocities.srv
    msg/Vels.msg
    msg/Pose2d.msg
    msg/Ticks.msg
    DEPENDENCIES std_msgs
)

# Add include directories
include_directories(include)

# Define EPOS2 library
add_library(EPOS2 src/epos2/epos2.cpp)
ament_target_dependencies(EPOS2
  rclcpp
  ${EPOS2_CMD_LIBRARY}
)

# Define VMCLIB library
add_library(VMCLIB
  src/Adapter/CComAdapter.cpp
  src/LayerClasses/CVmc.cpp
  src/SupportClasses/CData.cpp
  src/SupportClasses/CRequest.cpp
  src/LayerClasses/CCommunicationLayer.cpp
  src/StorageClasses/CMotor.cpp
  src/SupportClasses/CError.cpp
  src/SupportClasses/CSendTwo.cpp
  src/LayerClasses/CTranslationLayer.cpp
  src/StorageClasses/CStorage.cpp
  src/SupportClasses/CMessage.cpp
  src/SupportClasses/CTimer.cpp
  src/LayerClasses/CvmcAPI.cpp
  src/SupportClasses/CChannel.cpp
  src/SupportClasses/CMultisend.cpp
  src/SupportClasses/CTimestamp.cpp
)
ament_target_dependencies(VMCLIB rclcpp)

# Define Odo library
add_library(odo src/odometry.cc)
ament_target_dependencies(odo rclcpp)

# Define volksbot_node executable
add_executable(volksbot_node 
  src/volksbot.cc
)
set_target_properties(volksbot_node PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(volksbot_node
  tf2_ros
  std_msgs
  geometry_msgs
  std_srvs
  rclcpp
  sensor_msgs
  nav_msgs
)
target_link_libraries(volksbot_node VMCLIB EPOS2)

# Define kbcontrol executable
add_executable(kbcontrol 
  src/kbcontrol.cc
)
set_target_properties(kbcontrol PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(kbcontrol
  tf2_ros
  std_msgs
  geometry_msgs
  std_srvs
  rclcpp
  sensor_msgs
  nav_msgs
)

# Define odometry executable
add_executable(odometry 
  src/odometry.cc 
  src/odometry_main.cc
)
set_target_properties(odometry PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(odometry
  tf2_ros
  std_msgs
  geometry_msgs
  std_srvs
  rclcpp
  sensor_msgs
  nav_msgs
)

# Define calibration executable
add_executable(calibration 
  src/calibration.cc
)
set_target_properties(calibration PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(calibration
  tf2_ros
  std_msgs
  geometry_msgs
  std_srvs
  rclcpp
  sensor_msgs
  nav_msgs
)

# Define jscontrol executable
add_executable(jscontrol
  src/joystick/jscontrol.cc
  src/joystick/joystick.cc
  src/joystick/firejet.cc
  src/joystick/predator.cc
  src/joystick/logitechf710.cc
)
set_target_properties(jscontrol PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(jscontrol
  tf2_ros
  std_msgs
  geometry_msgs
  std_srvs
  rclcpp
  sensor_msgs
  nav_msgs
)

# Install libraries
install(
  TARGETS EPOS2 VMCLIB odo
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Install executables
install(
  TARGETS volksbot_node kbcontrol odometry calibration jscontrol
  DESTINATION lib/${PROJECT_NAME}
)

# Install directories and files
install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

# Export dependencies and libraries
ament_export_include_directories(include)
ament_export_dependencies(rclcpp std_msgs sensor_msgs nav_msgs tf2_ros)
ament_export_dependencies(rosidl_default_runtime)
ament_package()

install(FILES ${EPOS2_CMD_LIBRARY} DESTINATION lib)
#install(TARGETS odo VMCLIB DESTINATION lib EXPORT volksbot-targets)
#install(EXPORT volksbot-targets DESTINATION lib/volksbot)

link_directories(
  launch
)

# Automatically detect architecture and link correct libEposCmd version
include(cmake/TargetArch.cmake)
target_architecture(TARGET_ARCH)
message("Detected architecture: ${TARGET_ARCH}")
if(${TARGET_ARCH} STREQUAL "x86_64")
  set(EPOS2_CMD_LIBRARY "${PROJECT_SOURCE_DIR}/libEposCmd/x86_64/libEposCmd.so")
elseif(${TARGET_ARCH} STREQUAL "i386")
  set(EPOS2_CMD_LIBRARY "${PROJECT_SOURCE_DIR}/libEposCmd/x86/libEposCmd.so")
elseif(${TARGET_ARCH} STREQUAL "armv7")
  set(EPOS2_CMD_LIBRARY "${PROJECT_SOURCE_DIR}/libEposCmd/armv7hf/libEposCmd.so")
else()
  message("Unsupported architecture for libEposCmd!")
endif()
message("Using EposCmd library: ${EPOS2_CMD_LIBRARY}")
target_link_libraries(EPOS2 ${EPOS2_CMD_LIBRARY})