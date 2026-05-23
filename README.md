# Volksbot ROS2
This project is an adaptation of the original code to the modern ROS2 alternative for the Volksbot rovers (the original ROS version can be found under the branch [ROS](https://github.com/JMUWRobotics/volksbot/tree/ROS1)).

---
# Prerequisits
- Ubuntu 22.04 or Ubuntu 24.04
- GCC 11.0 or greater
- [ROS2 humble](https://docs.ros.org/en/humble/index.html)

> [!Warning]
> Other Linux distributions may or may not work correctly. Therefore, it is recommented to use one of the distributions mentioned above.
> Please let us know your experience and success with other systems.

> [!Important]
> If you use Ubuntu 24.04, you will probably encounter a `Permission Denied` error when trying to run the `volksbot` node.
> To fix this error regard the section [Trouble Shooting - Permission Denied](#permission-denied).

# Quickstart
> [!Note]
> For advanced build options regard the section [How To Build - Advanced](#how-to-build---advanced).

## How To Build
1. clone the repository locally
    ```bash
    git clone git@github.com:JMUWRobotics/volksbot.git
    ```
2. change to the `ros2_ws` directory
    ```bash
    cd volksbot/ros2_ws
    ```
2. set the udev rules (once) so that the motor controllers are recognized by the code.
    Copy the `42-usb-serial-volksbot.rules` from the `motor_controller` package into your udev rules:
    ```bash
    sudo cp src/motor_controller/42-usb-serial-volksbot.rules /etc/udev/rules.d/
    ```
    Afterwards, either restart or reset the udev server to load the new rules:
   ```bash
   udevadm control --reload-rules && udevadm trigger
   ```
4.  
    a) *on your **initial** build*: source the global ros2 environment:
    ```bash
    source ${ros2_distro}
    ```
    
    b) ***else*** source the ROS2 workspace:
    ```bash
    source ./install/setup.bash
    ```
5. build the project with the build script `volksbuild.sh`:
    ```bash 
    ./volksbuild.sh
    ```

> [!Tip]
> You can run the build with a set number of concurrent worker threads by supplying an argument to the build script.
> This is usefull when your system is limited in RAM or your OS freezes while building. (building with 2-4 threads should work on any system):
> ```bash
> ./volksbuild.sh n
> ```

## How to Run
The `volksbot` node from the `volksbot` package must always be started as this node determines the connected rover and comunicates the configureation over the `rover` topic to all other nodes:
```bash
ros2 run volksbot volksbot
```

> [!Tip]
> If you want to select a specific rover supply the name of the rover as an argument:
> ```bash
> ros2 run volksbot volksbot [RoverName]
> ```

In an other terminal you can run any node or the default launch script `praktikum_launch.py` of the package `volkslaunch`, which launches the remaining (not your customs) nodes.
```bash
ros2 launch volkslaunch praktikum_launch.py
```

> [!Caution]
> When playing back rosbags while connected to the rover you may want to comment out the `gamepad_driver` node from the launch script to avoid unwanted velocity commands to the motors with the recorded data.

---

# Documentation & more Information
Regard the following documentation markdowns for further information on usage and configuration of the project: 
- [Gamepad Driver](gamepad_driver/README.md): Information on how to use the gamepad and the different drive modes.
- [Logging](logging.md): Information on how to set up logging for the packages and how to use the logging macros for debugging and development and console prints.

---
# Trouble Shooting
## Permission Denied
If you are running the `volksbot` node on Ubuntu 24, you might encounter a `Permission Denied` error during the selection process. 
This happens because the program attempts to use ICMP sockets for pinging, which requires specific kernel permissions.
By default, some Ubuntu configurations set the allowed group range to `1 0`, meaning only the root user is permitted to open these sockets.

To allow all users to use ICMP sockets, you have to type in the command:
```bash
sudo sysctl -w net.ipv4.ping_group_range="0 2147483647"
```
To make this setting permanent, you have to edit your `/etc/sysctl.conf` and add the line `net.ipv4.ping_group_range=0 2147483647`.

## maxon EPSO4 connection failure
> [!Note]
> This problem may only be temporary as it will be corrected by this [issue](https://github.com/JMUWRobotics/volksbot/issues/7).

If the maxon epos4 motor controller gets recognized under the correct `/dev/` device directive but you get any of the errors:
> `0x10000003`, `0x10000005`, `0x10000007`, `0x10000008`

you may need to set the correct USB port in the [rovers.yaml]().
Usually it is: `USB0`, `USB1`, `USB2`, `USB3` or `USB4`

---
# Bugs or Issues?
Any Bugs or Issues, please open an [issue](https://docs.github.com/en/issues/tracking-your-work-with-issues/learning-about-issues/quickstart) on this [repository](https://github.com/JMUWRobotics/volksbot/issues) or conntact us directly.

---
# How To Build - Advanced
> [!Tip]
> When your OS freezes on building consider using less parallel workers by adding ```--parallel-workers n``` to the colcon build command (2-4 should usually work for everyone).

## When building for the first time:
1. source global ros2 environment
    ```bash
    source ${ros2_distro}
    ```
2. only build the SICK LMS package
    ```bash
    colcon build --packages-select sick_scan_xd --cmake-args " -DROS_VERSION=2" " -DLDMRS=0" " -DSCANSEGMENT_XD=0" --event-handlers console_direct+
    ```
3. source the ros2 workspace
    ```bash
    source ./install/setup.bash
    ```
4. build the remaining packages
    ```bash
    colcon build --packages-ignore sick_scan_xd
    ```

## Regular building:
> [!Caution]
> Make sure you are sourced into the workspace with
> ```bash
> source ./install/setup.bash
> ```

```bash
colcon build --packages-ignore sick_scan_xd
```
or just a subset of the packages:
```bash
colcon build --packages-select [package1] [package2] [package3] [...]
```
