# Expanded Joystick Driver for Volksbot ROS2

This package handles the gamepad input for the volksbot rovers. It dynamically recognizes connected gamepads and communicates the gamepad inputs vie the `gamepad` topic. In addition to that it also directly translates the gamepad inputs into velocity commands and publishes them on the `cmd_vel` topic. This allows for a direct control of the rover via the gamepad without the need for an additional node to translate the volksbot velocity command ROS2 messages. The driver is designed to be flexible and can support multiple types of controllers and can make use of the haptic feedback rumble if implemented in the controllers.

The currently supported controllers are:
- **Logitech F710**
- **Microsoft X-Box One**

## How To Use
To use the gamepad driver, simply run the `gamepad_driver` node:
```bash
ros2 run gamepad_driver gamepad_driver
```

Currently **two** drive modes are implemented to control the rover via the gamepad:
- **Arcade Drive**: The left thumb stick controls the forward and backward movement and left and right steering.
- **Throttle Drive**: The left thumb stick controls the left and right steering, the right trigger controls the forward acceleration and the left trigger controls the backward acceleration. This allows for a more intuitive control of the rover, especially for users familiar with racing games.

<!-- - **Tank Drive**: The left joystick controls the left wheels and the right joystick controls the right wheels. This allows for precise control of the rover and is especially useful for tight maneuvers. -->

The drive modes can be switched by pressing the `START` button on the controller.
In all drive modes the right thumb stick can be used to turn on the spot, where left and right movement of the stick will cause the rover to rotate left and right respectively.
Likewise, pressing the index Buttons `RB` and `LB` will increase or decrease the max speed of the rover, respectively.
 
- Arcade Drive:
```yaml
             / LT \     Switch Mode   / RT \
  Slower--> |  LB  |              |  |  RB  | <--Faster
            |------+--------------V--+------|
            )  ^    Back        Start    Y  (
           / < + >       Logitech      X   A \
          (    v    Mode      Vibrate    B    )
 Accelerate ------> ^               ^         |
   Steering ----> < O >           < O > <---- Rotate <-CCW / CW->
 Decelerate ------> V               V         )
           \      /^^^^^^^^^^^^^^^^^^^\      /
            \-__-/                     \-__-/
```

- Throttle Drive:
```yaml
Decelerate-> / LT \     Switch Mode   / RT \ <--Accelerate
  Slower--> |  LB  |              |  |  RB  | <--Faster
            |------+--------------V--+------|
            )  ^    Back        Start    Y  (
           / < + >       Logitech      X   A \
          (    v    Mode      Vibrate    B    )
          |         ^               ^         |
   Steering ----> < O >           < O > <---- Rotate <-CCW / CW->
          (         V               V         )
           \      /^^^^^^^^^^^^^^^^^^^\      /
            \-__-/                     \-__-/
```



> [!Caution]
> For the **Logitech F710**: Make sure to set the switch on the back of the controller to the **X** mode, otherwise the controller will not be recognized by the driver and that you do not have the **mode** button activated (as indicated by the LED) as it switches the functions from the thumb stick to the D-pad.







# Information for Developer
The new implementation will no longer use the `/dev/input/js*` joystick devices but the more general `/dev/input/event*` event devices.
> It is usually advised to use the general event interface instead of the the more constraint joystick interface.

## Information

To use the general event interface the joysticks event file handle needs to be ruled to a non dynamic device handle. At the moment only the **Logitech F710** and the **Microsoft X-Box One** joysticks are _used_ and fully integrated.
However integrating further joysticks is easily possible by adapting the applied rules and adding the necessary interface implementations.

## Internal Defines and Debug Symbols
The `volksbot_adapter.cpp` contains some internal defines that can be used for debugging and development.
These can be activated by uncommenting the corresponding `#define` statement.
The following are symbols which enable different print outputs to the console for display or debuging, by default the `PRINT_STATE` is activated:
| Symbol | Description | Printed Once | Printed Per Update Loop |
|:-------|:------------|:------------:|:-------------------------:|
| `PRINT_EVIO` | This will print the raw configuration data of the connected gamepad, once the connection is established, can be useful for debugging and setting up new joysticks. | ✅ | ❌ |
| `PRINT_STATE` | This will print a visualization of the gamepad inputs. | ❌ | ✅ |
| `PRINT_EVENT` | This will print every recorded input event. | ❌ | ✅ |
| `PRINT_VEL_CTRL` | This will print debug information for debugging the ACCEL_FORCE_FEEDBACK. | ❌ | ✅ |

> **The following feature is currently unstable and currently disabled**
>
> `ACCEL_FORCE_FEEDBACK` is a feature that emulates force feedback by applying an acceleration to the rover when the trigger buttons are pressed. This can be used to give the user a better feel for the speed of the rover and can be useful for controlling the rover in tight spaces.

## How to use

Unlike the old implementation it is no longer necessary to preemptively define the joysticks `/dev/input/*` Path.
It will now automatically select one of the connected (and implemented) Joysticks.

If multiple implemented joysticks are recognized, the one with the lowest number of its `/dev/input/js*` handle will be selected. This is usually the first connected joystick device.