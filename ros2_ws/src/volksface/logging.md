# Logging
Enter the following line in your terminal to set the logging directory for all logs:
```bash
export ROS_LOG_DIR=./log/latest
```
the logs can then be found under the linked folder `./logs/latest/` where `latest/` is a symlink to the folder of the latest build.

## Logging for Developers and Debugging
The `volksface/logging.h` and `volksface/ansi.h` files define macros that should be used for debugging and logging in this project.

### Base Logging Macros
Five logging levels are defined: `DEBUG`, `INFO`, `WARN`, `ERROR` and `FATAL` with the corresponding macros for logging:
- `LOG_DEBUG( args... )` (and `LOG_LN_DEBUG( args... )`)
- `LOG_INFO( args... )`  (and `LOG_LN_INFO( args... )`)
- `LOG_WARN( args... )`  (and `LOG_LN_WARN( args... )`)
- `LOG_ERROR( args... )` (and `LOG_LN_ERROR( args... )`)
- `LOG_FATAL( args... )` (and `LOG_LN_FATAL( args... )`)

> [!Note]
> To append a new line to the log message (only for console logging as logging to a file will always place individual messages on new lines) you can use the corresponding `LOG_LN_*` macros.

### Logging Configuration
To configure the logging behavior, the following preprocessor defines can be used before including the `logging.h` header:
- `USE_LOGGING`: This symbol defines the target of the logging macros, defaults to `0` (*Log to Console*) if not defined. The two possible versions are:
    - `1` (*Log to File*): All logging calls are directed to the ROS2 logging system, writing the messages to a file in the specified logging directory (`ROS_LOG_DIR`). This should be used if no debugging or direct access to the console is required.
    - `0` (*Log to Console*): If this logging method is selected all logging calls are directed to the standard C print functions, printing the messages directly to the console. It is useful for real-time debugging or explicit console rendering. However, with this method, no log messages will be saved to the log file. In this case use the `ROS_LOG_[LEVEL]` macros for ROS2 logging, but be aware that this may inadvertently cause some the log message to also be printed to the console (depending on the ROS2 logging configuration).

- `USE_COLORED_LOGGING`: This symbol defines whether ANSI escape codes for coloring and special console commands are to be ignored when used in the logging string. `0` will omit any ANSI escape codes in the log messages. `1` will allow the use of ANSI escape codes in the log messages, which can be used for coloring or special console commands (like clearing the console or moving the cursor). Defaults to `0` if not defined.

The concrete logging behavior used by each package is defined in the `project_config.cmake` file. 

### Advanced Logging
The `ansi.h` header defines a set of macros for using ANSI escape codes in the logging strings, which can be used for coloring or special console commands when logging to the console, like clearing the console or moving the cursor. These macros can be used in the logging strings when `USE_COLORED_LOGGING` is set to `1`.

Special ANSI commands that are only meant to be emitted in console logging mode can be used in the `LOG_ANSI( args... )` and `LOG_LN_ANSI( args... )` macros.
Similar the `IF_PRINT( ... )` and `IF_LOG( ... )` macros can be used to conditionally include code only to be included in console logging or file logging mode, respectively.