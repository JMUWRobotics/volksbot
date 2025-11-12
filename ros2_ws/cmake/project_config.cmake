# Global CMake Config to be included in all packages
#------------------------------------------------------------------------------
# This manages things like compiler flags or cross package C/C++ defines

# Add standard ROS 2 compile options
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

# add definitions
add_compile_definitions(
  # set logging globally
  # set to 1 if logging should be used
  # set to 0 if print to console should be used instead
  USE_LOGGING=1

  # allow colorizing the logging messages
  # set to 1 to enable color escape codes
  # set to 0 to disable color escape codes
  USE_COLORED_LOGGING=1

  # set logging for individual packages, will override the global logging config
  # comment out to use global logging config
  # USE_LOGGING_GAME_PAD=0
  # USE_LOGGING_KEYBOARD=0
  # USE_LOGGING_LMS_STARTER=0
  # USE_LOGGING_MOTOR_CONTROLLER=0
  # USE_LOGGING_ODOMETRY=0
  USE_LOGGING_VOLKSBOT=0
)


# testing
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