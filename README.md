# Expanded Joystick Driver for Volksbot ROS2

This branch is used to convert the old joystick backend into a new and expanded ROS2 implementation. It will expand the useability and agility of the original implementation to allow easier project integration and force feedback.

The new implementation will no longer use the `/dev/input/js*` joystick devices but the more general `/dev/input/event*` event devices.
> It is usually advised to use the general event interface instead of the the more constraint joystick interface.


### Information

To use the general event interface the joysticks event file handle needs to be ruled to a non dynamic device handle. At the moment only the **Logitech F710** joystick is used and will be fully integrated. Therefor the backend will currently only implement this joystick.

However integrating further joysticks is possible by adapting the applied rules and adding the necessary interface implementations.


### Instructions


### Details


### TODOs