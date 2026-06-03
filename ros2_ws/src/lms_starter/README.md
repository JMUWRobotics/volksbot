# Sick LMS
> [!Note]
> The used version of the SICK LMS library is the [official ROS2 library](https://github.com/SICKAG/sick_scan_xd/tree/master) version 3.5.0 for sick scanners. 

## [Building](https://github.com/SICKAG/sick_scan_xd/blob/master/INSTALL-ROS2.md#summary-for-the-different-build-options)

Building the library for the lms100
```bash
colcon build --packages-select sick_scan_xd --cmake-args " -DROS_VERSION=2" " -DLDMRS=0" " -DSCANSEGMENT_XD=0" --event-handlers console_direct+
```

## [Running / Launching](https://github.com/SICKAG/sick_scan_xd?tab=readme-ov-file#running-the-driver)

Launching the sick driver for the lms100 ! Attention: must set the correct host-ip manually
```bash
ros2 run sick_scan_xd sick_generic_caller ./src/sick_scan_xd/launch/sick_lms_1xx.launch hostname:=192.168.0.XX
```