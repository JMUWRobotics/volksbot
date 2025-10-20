cmake_minimum_required(VERSION 3.8)
project(keyboard_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

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
