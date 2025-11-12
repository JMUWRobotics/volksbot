/////////////////////////////////////////////////////////////////////////////
// @file    logging.h
// @brief   generalized logging which allows for logging or console printing
// @author  Nico Schubert
// @date    05.11.2025
/////////////////////////////////////////////////////////////////////////////

#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <errno.h>

#include "rclcpp/rclcpp.hpp"

#ifndef LOGGING_NAME
    #error logging name must be supplied before including logging.h
#endif

#define LOGGER_ENTITY rclcpp::get_logger( LOGGING_NAME )

#ifndef USE_LOGGING
    #define USE_LOGGING 0
#endif

#ifndef USE_COLORED_LOGGING
    #define USE_COLORED_LOGGING 0
#endif

#if USE_LOGGING
    #define LOG_DEBUG( args... ) RCLCPP_DEBUG( LOGGER_ENTITY, args )
    #define LOG_INFO( args... ) RCLCPP_INFO( LOGGER_ENTITY, args )
    #define LOG_WARN( args... ) RCLCPP_WARN( LOGGER_ENTITY, args )
    #define LOG_ERROR( args... ) RCLCPP_ERROR( LOGGER_ENTITY, args )
    #define LOG_FATAL( args... ) RCLCPP_FATAL( LOGGER_ENTITY, args )

    #define LOG_LN_DEBUG( args... ) LOG_DEBUG( args )
    #define LOG_LN_INFO( args... ) LOG_INFO( args )
    #define LOG_LN_WARN( args... ) LOG_WARN( args )
    #define LOG_LN_ERROR( args... ) LOG_ERROR( args )
    #define LOG_LN_FATAL( args... ) LOG_FATAL( args )

    #define DISABLE_CONTROL_CODES 1
    #define DISABLE_COLOR !USE_COLORED_LOGGING

    // only emits when printing to the console
    #define LOG_ANSI( args... )
    // only emits when printing to the console
    #define LOG_LN_ANSI( args... )
    
    // only emits when printing to the console
    #define IF_PRINT( ... )
    
    // only emits when logging
    #define IF_LOG( ... ) __VA_ARGS__
#else
    #define _perror( args... ) fprintf( stderr, args ); fprintf(stderr, ": %s\n", strerror(errno))
    #define LOG_DEBUG( args... ) printf( args )
    #define LOG_INFO( args... ) printf( args )
    #define LOG_WARN( args... ) printf( args )
    #define LOG_ERROR( args... ) _perror( args )
    #define LOG_FATAL( args... ) _perror( args )

    #define LOG_LN_DEBUG( args... ) LOG_DEBUG( args ); LOG_DEBUG( "\n" )
    #define LOG_LN_INFO( args... ) LOG_INFO( args ); LOG_INFO( "\n" )
    #define LOG_LN_WARN( args... ) LOG_WARN( args ); LOG_WARN( "\n" )
    #define LOG_LN_ERROR( args... ) LOG_ERROR( args )
    #define LOG_LN_FATAL( args... ) LOG_FATAL( args )

    #define DISABLE_CONTROL_CODES 0
    #define DISABLE_COLOR 0

    // only emits when printing to the console
    #define LOG_ANSI( args... ) LOG_INFO( args )
    // only emits when printing to the console
    #define LOG_LN_ANSI( args... ) LOG_LN_INFO( args )
    
    // only emits when printing to the console
    #define IF_PRINT( ... ) __VA_ARGS__

    // only emits when logging
    #define IF_LOG( ... )
#endif

#include "ansi.h"

#endif