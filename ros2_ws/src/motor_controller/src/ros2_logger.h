#ifndef __ROS2_LOGGER_H__
#define __ROS2_LOGGER_H__

#ifdef USE_LOGGING_MOTOR_CONTROLLER
    #undef USE_LOGGING
    #define USE_LOGGING USE_LOGGING_MOTOR_CONTROLLER
#endif

#define LOGGING_NAME "motor_controller"
#include "volksface/logging.h"

#endif