cmake_minimum_required(VERSION 3.5)
project(volksbot)

find_package(rosidl_default_generators REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 1 4)

rosidl_generate_interfaces(
    ${PROJECT_NAME}
        srv/velocities.srv
        msg/vels.msg
        msg/pose2d.msg
        msg/ticks.msg
    DEPENDENCIES
        
)

include_directories(
  include
)

add_library(EPOS2
  src/epos2/epos2.cpp
)

ament_target_dependencies(EPOS2
  ${EPOS2_CMD_LIBRARY}
)

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
 

add_library(odo
  src/odometry.cc
)
 

add_executable(volksbot src/volksbot.cc)
set_target_properties(volksbot PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(volksbot
  "tf2_ros"
  "std_msgs"
  "geometry_msgs"
  "std_srvs"
  "rclcpp"
  "sensor_msgs"
  "nav_msgs"
  VMCLIB
  EPOS2
)
 

add_executable(kbcontrol src/kbcontrol.cc)
set_target_properties(kbcontrol PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(kbcontrol
  "tf2_ros"
  "std_msgs"
  "geometry_msgs"
  "std_srvs"
  "rclcpp"
  "sensor_msgs"
  "nav_msgs"
)

add_executable(odometry 
  src/odometry.cc 
  src/odometry_main.cc
)
set_target_properties(odometry PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(odometry
  "tf2_ros"
  "std_msgs"
  "geometry_msgs"
  "std_srvs"
  "rclcpp"
  "sensor_msgs"
  "nav_msgs"
)

add_executable(calibration src/calibration.cc)
set_target_properties(calibration PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(calibration
  "tf2_ros"
  "std_msgs"
  "geometry_msgs"
  "std_srvs"
  "rclcpp"
  "sensor_msgs"
  "nav_msgs"
)

add_executable(jscontrol
  src/joystick/jscontrol.cc
  src/joystick/joystick.cc
  src/joystick/firejet.cc
  src/joystick/predator.cc
  src/joystick/logitechf710.cc
)
set_target_properties(jscontrol PROPERTIES LINK_FLAGS "-pthread")
ament_target_dependencies(jscontrol
  "tf2_ros"
  "std_msgs"
  "geometry_msgs"
  "std_srvs"
  "rclcpp"
  "sensor_msgs"
  "nav_msgs"
)
ament_export_include_directories(include)
ament_export_dependencies(std_msgs message_runtime rclcpp)
ament_package()
install(FILES ${EPOS2_CMD_LIBRARY} DESTINATION lib)

#install(DIRECTORY include/${PROJECT_NAME}
#	DESTINATION ${CATKIN_DEVEL_PREFIX}/include/
#	PATTERN ".svn" EXCLUDE)

#DESTINATION ${CATKIN_DEVEL_PREFIX}/include/${PROJECT_NAME}/
#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}/volksbot
#)

install(TARGETS odo VMCLIB DESTINATION lib EXPORT volksbot-targets)
install(EXPORT volksbot-targets DESTINATION lib/volksbot)

link_directories(
  launch
)

# Automatically detect archtitecture and link correct libEposCmd version
include(cmake/TargetArch.cmake)
target_architecture(TARGET_ARCH)
message("Detected architecture: ${TARGET_ARCH}")
if(${TARGET_ARCH} STREQUAL "x86_64")
  set(EPOS2_CMD_LIBRARY "${PROJECT_SOURCE_DIR}/libEposCmd/x86_64/libEposCmd.so")
  set(EPOS2_CMD_LIBRARY "${PROJECT_SOURCE_DIR}/libEposCmd/x86/libEposCmd.so")
  set(EPOS2_CMD_LIBRARY "${PROJECT_SOURCE_DIR}/libEposCmd/armv7hf/libEposCmd.so")
  set(EPOS2_CMD_LIBRARY "EposCmd" PARENT_SCOPE)
elseif(${TARGET_ARCH} STREQUAL "i386")
elseif(${TARGET_ARCH} STREQUAL "armv7")
else()
  message("Unsupported architecture for libEposCmd!")
endif()
message("Using EposCmd library: ${EPOS2_CMD_LIBRARY}")
message("${CATKIN_PACKAGE_LIB_DESTINATION}")

MESSAGE(STATUS "STATUS: ${CATKIN_PACKAGE_INCLUDE_DESTINATION}")
MESSAGE(STATUS "STATUS: ${CATKIN_GLOBAL_INCLUDE_DESTINATION}")
MESSAGE(STATUS "STATUS: include/${PROJECT_NAME}")
MESSAGE(STATUS "STATUS: ${CATKIN_DEVEL_PREFIX}/include/")
