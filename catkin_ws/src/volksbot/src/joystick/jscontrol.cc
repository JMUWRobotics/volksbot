#include "firejet.h"
#include "predator.h"
#include "logitechf710.h"
#include <string.h>

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto n = rclcpp::Node::make_shared("joystick_control");
  std::string device;
  n.param<std::string>("/devices/joystick", device, "/dev/input/js0");
  
  Joystick *js;
  int type;
  if ( n.getParam("/control/joystick/logitechf710", type) && type) {
    js = new LogitechF(device.c_str());
  } else if ( n.getParam("/control/joystick/predator", type) && type) {
    js = new Predator(device.c_str());
  } else if ( n.getParam("/control/joystick/firejet", type) && type) {
    js = new Firejet(device.c_str());
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("Volksbot"), "No joystick type specified!!!\n Aborting joystick-control.\n");
    js = new Predator(device.c_str());
    //return 0;
  }

   // js->waitforevents();
    
  while (rclcpp::ok())
  {
    js->waitforevent();
  }

  delete js;
	return 0;
}
