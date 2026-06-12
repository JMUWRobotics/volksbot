#ifndef __ROS2_LOGGER_H__
#define __ROS2_LOGGER_H__

#ifdef USE_LOGGING_GAME_PAD
    #undef USE_LOGGING
    #define USE_LOGGING USE_LOGGING_GAME_PAD
#endif

#define LOGGING_NAME "gamepad_driver"
#include "volksface/logging.h"

#endif