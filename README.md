# Volksbot ROS2 branch

This branch contains the in progess migration of the volksbot package to ROS2 after applying the ros-migration-tool. After successful use of the migration tool not all ROS code snippets are converted into ROS2, like the subscriber, publisher and services. This further migration is now done manually.  


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


# Sick LMS
## Info
The library used is the [official ROS2 library](https://github.com/SICKAG/sick_scan_xd/tree/master) version 3.5.0 for sick scanners. 

## [Building](https://github.com/SICKAG/sick_scan_xd/blob/master/INSTALL-ROS2.md#summary-for-the-different-build-options)

Building the library for the lms100

    colcon build --packages-select sick_scan_xd --cmake-args " -DROS_VERSION=2" " -DLDMRS=0" " -DSCANSEGMENT_XD=0" --event-handlers console_direct+

> TODO: (if possible?) add cmake args to the cmake file used for building

## [Running / Launching](https://github.com/SICKAG/sick_scan_xd?tab=readme-ov-file#running-the-driver)

Launching the sick driver for the lms100 ! Attention: must set the correct host-ip manually

    ros2 run sick_scan_xd sick_generic_caller ./src/sick_scan_xd/launch/sick_lms_1xx.launch hostname:=192.168.0.XX

> TODO: configure and add laser specific settings like in the ROS1 volksbot parameter.yaml

# Building
Currently building for the first time requires multiple steps:

```bash
source ${ros2_distro}
colcon build --packages-select sick_scan_xd --cmake-args " -DROS_VERSION=2" " -DLDMRS=0" " -DSCANSEGMENT_XD=0" --event-handlers console_direct+
source ./install/setup.bash
colcon build --packages-ignore sick_scan_xd
```

for regular building, make sure that you are sourced into the workspace 
```bash
colcon build --packages-ignore sick_scan_xd
```