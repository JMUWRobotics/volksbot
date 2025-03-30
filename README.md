# Expanded Joystick Driver for Volksbot ROS2

This branch is used to convert the old joystick backend into a new and expanded ROS2 implementation. It will expand the useability and agility of the original implementation to allow easier project integration and force feedback.

The new implementation will no longer use the `/dev/input/js*` joystick devices but the more general `/dev/input/event*` event devices.
> It is usually advised to use the general event interface instead of the the more constraint joystick interface.


### Information

To use the general event interface the joysticks event file handle needs to be ruled to a non dynamic device handle. At the moment only the **Logitech F710** and the **Microsoft X-Box One** joysticks are _used_ and will be fully integrated. Therefor the backend will currently only implement these joysticks.

However integrating further joysticks is easily possible by adapting the applied rules and adding the necessary interface implementations.


### How to use

Unlike the old implementation it is no longer necessary to preemptively define the joysticks `/dev/input/*` Path.
It will now automatically select one of the connected (and implemented) Joysticks.

If multiple implemented joysticks are recognized, the one with the lowest number of its `/dev/input/js*` handle will be selected. This is usually the first connected joystick device.
