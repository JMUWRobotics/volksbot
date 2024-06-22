# ROS2 - Humble Hawksbill

## TODOs for ROS2
- Recherche ROS2 Version für:
    - GMapping
    - lms100
    - Joystick

- Code migrieren
    - Migrate Packages -> Max
    - Migrate Launch Files
    - Migrate Scripts
    - Mirgate Code
 

## Installation Notes
(Official installation guide)[https://docs.ros.org/en/humble/Installation.html] for ROS2 Humble Hawksbill

Generally ROS2 can be installed alongside of ROS without any problems

### For Ubuntu 20.04 Focal Fosse
See official (installation)[https://docs.ros.org/en/humble/Installation/Alternatives/Ubuntu-Development-Setup.html] guide

ROS2 can only be installed over source for Ubuntu 20.04.
If so, just make sure to comment any source commands for ROS1 in your `.bashrc`

Potential Problems:
    - when doing ```sudo apt update && sudo apt install -y ...``` will result in:
    ```E: The repository 'cdrom://Ubuntu 20.04.6 LTS _Focal Fossa_ - Release amd64 (20230316) focal Release' does not have a Release file.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
    ```
    
    Go to `Software & Updates` and disable the option `Cdro with Ubuntu 20.04 'Focal Fossa'`
