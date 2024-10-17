cmake_minimum_required(VERSION 3.5)
project(lms100)

find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(
  include
)

add_executable(scanlistener src/scanlistener.cc)
ament_target_dependencies(scanlistener rclcpp sensor_msgs)

add_executable(sicksensor src/sicksensor.cc src/lms100_cola.cc)
ament_target_dependencies(sicksensor rclcpp sensor_msgs)

ament_export_dependencies(sensor_msgs message_runtime)
ament_package()
