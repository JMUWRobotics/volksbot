cmake_minimum_required(VERSION 3.5)
project(volksbot)
find_package(ament_cmake REQUIRED)
set(INCLUDE_DIRS ${ament_cmake_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})
set(LIBRARY_DIRS ${ament_cmake_LIBRARIES})
set(LIBS ${ament_cmake_LIBRARIES})

# Add support for C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

rosbuild_add_library(VMCLIB CCommunicationLayer.cpp CTranslationLayer.cpp
  CvmcAPI.cpp CVmc.cpp)

ament_export_dependencies(ament_cmake)
ament_export_include_directories(${INCLUDE_DIRS})

ament_package()
