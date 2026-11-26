#include "rclcpp/executors.hpp"
#include "rclcpp/rclcpp.hpp"
#include "stdio.h"

#include "sys/time.h"
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <signal.h>
#include <stdexcept>
#include <termios.h>
#include <unistd.h>

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

  // initilize client and request pointer
  client_ = this->create_client<srv::VelCmd>("Controls");
  velocity_ = std::make_shared<srv::VelCmd::Request>();

  velocity_->left = 0;
  velocity_->right = 0;
  speed_ = 0.0;
  kfd_ = 0;
}

void kbcontrol::setVelocity(char c) {
  switch (c) {
  // if 'L' is pressed, send request to service to set speed as below
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
    speed_ = 0;
    velocity_->left = speed_;
    velocity_->right = speed_;
    break;
  }
}

void kbcontrol::run() {
  char c, previous;
  previous = KEYCODE_Q;
  struct termios cooked;
  tcgetattr(kfd_, &cooked);
  cooked.c_lflag &= ~(ICANON | ECHO);
  // Setting a new line, then end of file
  cooked.c_cc[VEOL] = 1;
  cooked.c_cc[VEOF] = 2;
  tcsetattr(kfd_, TCSANOW, &cooked);

  rclcpp::Rate loop_rate(5);
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(this->shared_from_this());

  while (rclcpp::ok()) {
    c = KEYCODE_Q;
    ssize_t n = read(kfd_, &c, 1);
    (void)n;

    switch (c) {
    case KEYCODE_A:
      speed_ += 10;
      if (speed_ > 100.0)
        speed_ = 100.0;
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
    LOG_LN_INFO("Call service: %f %f", velocity_->left, velocity_->right);

    // Check if service is active
    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      // If ROS is shutdown before the service is activated, show this error
      if (!rclcpp::ok()) {
        LOG_LN_ERROR(
            COL(FG_BRIGHT_RED, "Interrupted while waiting for the service."));
        return;
      }
      LOG_LN_WARN(COL(FG_BRIGHT_YELLOW, "Service not available"));
    }
    // Send request to service
    auto feedback = client_->async_send_request(velocity_);

    // blocks the thread until feedback is received -> synchronous service call
    if (rclcpp::spin_until_future_complete(this->shared_from_this(),
                                           feedback) ==
        rclcpp::FutureReturnCode::SUCCESS) {
      LOG_LN_INFO("Service call succeeded.");
    } else {
      LOG_LN_ERROR(COL(FG_BRIGHT_RED, "Service call failed."));
    }

    executor.spin_some();
    loop_rate.sleep();
  }
}

} // namespace volksbot

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto controller = std::make_shared<volksbot::kbcontrol>();
  controller->run();
  return 0;
}
