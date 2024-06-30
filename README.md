# ROS2 - Humble Hawksbill

## TODOs for ROS2
- Recherche ROS2 Version für:
    - GMapping
    - lms100
    - Joystick

- Code migrieren
    - Migrate Packages -> Max
    - Migrate Launch Files -> Nico
    - Migrate Scripts
    - Mirgate Code
 

## Installation Notes
[Official installation guide](https://docs.ros.org/en/humble/Installation.html) for ROS2 Humble Hawksbill

Generally ROS2 can be installed along side of ROS without any problems

But make sure to comment out any source commands for ROS1 in your `.bashrc`

- ### [installation guide](https://docs.ros.org/en/humble/Installation/Alternatives/Ubuntu-Development-Setup.html) for Ubuntu 20.04 Focal Fossa

    ROS2 can only be installed by compiling the source locally for Ubuntu 20.04.

    #### Potential problems:
    
    - calling ```sudo apt update && sudo apt install -y ...``` results in:

            E: The repository 'cdrom://Ubuntu 20.04.6 LTS _Focal Fossa_ - Release amd64 (20230316) focal Release' does not have a Release file.
            N: Updating from such a repository can't be done securely, and is therefore disabled by default.
            N: See apt-secure(8) manpage for repository creation and user configuration details.

        > Solution: Go to `Software & Updates` and disable the option `Cdrom with Ubuntu 20.04 'Focal Fossa'`
    
    
    - Building/Compilation fails with an `ICE` (Internal Compiler Error):
        
        > for example a crash of `cc1plus`

        These problems are mostly due to insufficient RAM or other lack of resources. To resove these Problems try the following steps:

        - Step 1: make sure to have a large enough `/swapfile` (rule of thumb: ```size of swapfile == size of RAM```):
            > if not you can follow this [guide](https://askubuntu.com/a/1264577) or other similar guides
        
        - Step 2: build the source with a reduced set of jobs:
            > `$ MAKEFLAGS=-j8 colcon build --parallel-workers=2 --symlink-install`
