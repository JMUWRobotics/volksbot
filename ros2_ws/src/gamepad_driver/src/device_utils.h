/////////////////////////////////////////////////////////////////////////////
// @file    device_util.h
// @brief   Simple utility function to automatically find and connect to a gamepad device
// @author  Nico Schubert
// @date    31.03.2025
/////////////////////////////////////////////////////////////////////////////

#ifndef __GAMEPAD_UTIL_H__
#define __GAMEPAD_UTIL_H__

#include <vector>
#include <string>

#include "gamepad.h"


// Macro for ansi console coloring
#define COL(code, str)  "\x1b[" #code "m" str "\x1b[0m"


namespace device_util {
    // get all connected joystick device names /dev/input/js*
    std::vector<std::string> get_input_js_names();

    // get the input event handle of each joystick
    std::vector<std::string> get_event_file_names( const std::vector<std::string> js_names );

    /**
     * @brief Select automatically one of the known joystick connected to the PC.ABS_DISTANCE
     * @brief Selects the first successful match
     * 
     * @return Gamepad* automatically selected gamepad or nullptr if none could be selected
     */
    Gamepad* select_and_connect_gamepad();

    /**
     * @brief tries to reconnect to the previous gamepad device. Can be used when a gamepad was connected but now has_connection() is false
     * 
     * @param gamepad gamepad which was already connected but has lost connection
     * @return true  if reconnection could be established
     * @return false if reconnection could not be established
     */
    bool try_reconnect( Gamepad* gamepad );


    /**
     * @brief Resolves a posix path by following all symlinks
     * 
     * @param path posix path to resolve
     * @param resolved resolved path untouched if unable to resolve
     * @return true if path could be resolved
     * @return false if patch could not be resolved or an error occurred 
     */
    bool resolve_link( const std::string path, std::string& resolved );
    
    /**
     * @brief gets the usb device path of an input event path
     * 
     * @param input_event_path path of an input event file (i.e. `/dev/input/event*`)
     * @param usb_path path to the underlying usb device of the input event
     * @return true  if the underlying usb device path could be found
     * @return false if the underlying usb device path could not be found or an error ocurred
     */
    bool get_usb_device_path( const std::string input_event_path, std::string& usb_path );
    
    /**
     * @brief read the serial number of an usb device
     * 
     * @param usb_device_path path to the usb device directory
     * @param serial_number serial number of this usb device
     * @return true  if the serial number could be read
     * @return false if the serial number could not be read or an error ocurred
     */
    bool get_usb_device_serial_number( const std::string usb_device_path, std::string& serial_number );

    /**
     * @brief read the serial number of the underlying usb device of an input event path
     * 
     * @param input_event_path path of an input event file (i.e. `/dev/input/event*`)
     * @param seriserial_number serial number of this usb deviceal_number
     * @return true  if the serial number could be read
     * @return false if the serial number could not be read or an error ocurred
     */
    bool get_usb_serial_of_input_event( const std::string input_event_path, std::string& serial_number );

}
#endif