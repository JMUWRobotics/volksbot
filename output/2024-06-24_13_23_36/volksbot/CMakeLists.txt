cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0048 NEW)
project(volksbot)

# Add support for C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()



set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)






link_directories(launch)

# Automatically detect archtitecture and link correct libEposCmd version
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
  set(EPOS2_CMD_LIBRARY "EposCmd" PARENT_SCOPE)
endif()
message("Using EposCmd library: ${EPOS2_CMD_LIBRARY}")
message("lib")
install(FILES ${EPOS2_CMD_LIBRARY} DESTINATION lib)

add_library(EPOS2 src/epos2/epos2.cpp)
add_dependencies(EPOS2 volksbot_generate_messages_cpp)

add_library(VMCLIB src/Adapter/CComAdapter.cpp src/LayerClasses/CVmc.cpp
  src/SupportClasses/CData.cpp src/SupportClasses/CRequest.cpp
  src/LayerClasses/CCommunicationLayer.cpp src/StorageClasses/CMotor.cpp
  src/SupportClasses/CError.cpp src/SupportClasses/CSendTwo.cpp
  src/LayerClasses/CTranslationLayer.cpp src/StorageClasses/CStorage.cpp
  src/SupportClasses/CMessage.cpp src/SupportClasses/CTimer.cpp
  src/LayerClasses/CvmcAPI.cpp src/SupportClasses/CChannel.cpp
  src/SupportClasses/CMultisend.cpp src/SupportClasses/CTimestamp.cpp)
add_dependencies(VMCLIB volksbot_generate_messages_cpp)
add_library(odo src/odometry.cc)
add_dependencies(odo volksbot_generate_messages_cpp)
add_executable(volksbot src/volksbot.cc)
set_target_properties(volksbot PROPERTIES LINK_FLAGS "-pthread")
add_dependencies(volksbot volksbot_generate_messages_cpp)
add_executable(kbcontrol src/kbcontrol.cc)
set_target_properties(kbcontrol PROPERTIES LINK_FLAGS "-pthread")
add_dependencies(kbcontrol volksbot_generate_messages_cpp)

add_executable(odometry src/odometry.cc src/odometry_main.cc)
set_target_properties(odometry PROPERTIES LINK_FLAGS "-pthread")
add_dependencies(odometry volksbot_generate_messages_cpp)

add_executable(calibration src/calibration.cc)
set_target_properties(calibration PROPERTIES LINK_FLAGS "-pthread")
add_dependencies(calibration volksbot_generate_messages_cpp)

add_executable(jscontrol src/joystick/jscontrol.cc src/joystick/joystick.cc
  src/joystick/firejet.cc src/joystick/predator.cc src/joystick/logitechf710.cc)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(tf2 REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
set(INCLUDE_DIRS ${ament_cmake_INCLUDE_DIRS}
  ${rosidl_default_generators_INCLUDE_DIRS} ${tf2_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS} ${rclcpp_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})
set(LIBRARY_DIRS ${ament_cmake_LIBRARIES} ${rosidl_default_generators_LIBRARIES}
  ${tf2_LIBRARIES} ${std_msgs_LIBRARIES} ${rclcpp_LIBRARIES})
target_link_libraries(volksbot ${LIBRARY_DIRS})
target_link_libraries(kbcontrol ${LIBRARY_DIRS})
target_link_libraries(odometry ${LIBRARY_DIRS})
target_link_libraries(calibration ${LIBRARY_DIRS})
target_link_libraries(jscontrol ${LIBRARY_DIRS})
set(LIBS ${ament_cmake_LIBRARIES} ${rosidl_default_generators_LIBRARIES}
  ${tf2_LIBRARIES} ${std_msgs_LIBRARIES} ${rclcpp_LIBRARIES})
rosidl_generate_interfaces(${PROJECT_NAME} "msg/pose2d.msg" "msg/ticks.msg"
  "msg/vels.msg" "srv/velocities.srv"
  DEPENDENCIES builtin_interfaces std_msgs)
set_target_properties(jscontrol PROPERTIES LINK_FLAGS "-pthread")
add_dependencies(jscontrol volksbot_generate_messages_cpp)


message(STATUS "STATUS: include/${PROJECT_NAME}")
message(STATUS "STATUS: include")
message(STATUS "STATUS: include/${PROJECT_NAME}")
message(STATUS "STATUS: include/")

#install(DIRECTORY include/${PROJECT_NAME}
#	DESTINATION include/
#	PATTERN ".svn" EXCLUDE)

#DESTINATION include/${PROJECT_NAME}/
#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION include/${PROJECT_NAME}/volksbot
#)

install(TARGETS odo VMCLIB DESTINATION lib EXPORT volksbot-targets)
install(EXPORT volksbot-targets DESTINATION lib/volksbot)

ament_export_dependencies(ament_cmake)
ament_export_dependencies(rosidl_default_generators)
ament_export_dependencies(tf2)
ament_export_dependencies(std_msgs)
ament_export_dependencies(rclcpp)
ament_export_include_directories(${INCLUDE_DIRS})
ament_export_libraries(EPOS2 VMCLIB odo ${LIBS})

ament_package()
