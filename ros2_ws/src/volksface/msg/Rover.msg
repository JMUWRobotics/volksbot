# indicates whether a rover was successfully recognized and selected
# true if data is usable else false
bool is_valid

# rover name
string name

# wheels
float32 wheel_diameter  # cm
float32 wheel_base      # cm # distance between wheel center points

# motor controller
uint8 motor_controller          # id of motor controller as noted by enum VB::MCD
string motor_controller_port    # port to be passed to the specified motor controller 

string udev_symlink     # device port mapping (usually: /dev/xyz) as noted in 42-usb-serial-volksbot.rules

# lms
uint32 ip_lms           # static ip of laserscanner
# ip as hex: AA:BB:CC:DD <=> ip as uint32: 0xDDCCBBAA