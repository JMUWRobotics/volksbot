# ROS 2 lms100 test branch

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

