#include "rclcpp/rclcpp.hpp"
#include "stdio.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "sys/time.h"

#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>

#define KEYCODE_R 0x43 
#define KEYCODE_L 0x44
#define KEYCODE_U 0x41
#define KEYCODE_D 0x42
#define KEYCODE_Q 0x71
#define KEYCODE_A 0x61
#define KEYCODE_Y 0x79

#include "kbcontrol.h"

namespace volksbot {

kbcontrol::kbcontrol() : Node("kbcontrol_node") {

  //initilize client and request pointer
  client_ = this->create_client<volksbot::srv::Velocities>("kbcontrol_client");
  velocity_ = std::make_shared<volksbot::srv::Velocities::Request>();

  velocity_->left = 0;
  velocity_->right = 0;
  speed_ = 0.0;
  kfd_ = 0;
}

void kbcontrol::setVelocity(char c) {
    switch(c)
    {
      case KEYCODE_L:
        velocity_->left = -speed_;
        velocity_->right = speed_;
        break;
      case KEYCODE_R:
        velocity_->left = speed_;
        velocity_->right = -speed_;
        break;
      case KEYCODE_U:
        velocity_->left = -speed_;
        velocity_->right = -speed_;
        break;
      case KEYCODE_D:
        velocity_->left = speed_;
        velocity_->right = speed_;
        break;
      case KEYCODE_Q:
        speed = 0;
        velocity_->left = speed_;
        velocity_->right = speed_;
        break;
    }
}

void kbcontrol::run() {
  char c,previous;
  previous = KEYCODE_Q;
  struct termios cooked;
  tcgetattr(kfd_, &cooked);
  cooked.c_lflag &=~ (ICANON | ECHO);
  // Setting a new line, then end of file                         
  cooked.c_cc[VEOL] = 1;
  cooked.c_cc[VEOF] = 2;
  tcsetattr(kfd_, TCSANOW, &cooked);
  
  rclcpp::Rate loop_rate(5);

  while (rclcpp::ok() ) {
    c = KEYCODE_Q;
    read(kfd_, &c, 1);
    
    switch(c)
    {
      case KEYCODE_A:
        speed_ += 10;
        if (speed_ > 100.0) speed_ = 100.0;
        setVelocity(previous);
        break;
      case KEYCODE_Y:
        speed_ *= 0.9;
        setVelocity(previous);
        break;
      default:
        previous = c;
        break;
    }
    setVelocity(c);
    printf("Call servic: %f %f\n", velocity_->left, velocity_->right);
    //FIXME: migrate service call to ros2
    ros::service::call("Controls", velocity_);
    
    //FIXME: error spin_some
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
}

}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto controller = std::make_shared<volksbot::kbcontrol>();
  controller->run();
	return 0;
}
