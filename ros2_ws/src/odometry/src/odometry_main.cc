#include "odometry/odometry.h"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  bool publish_tf = true;

  if (argc > 1) {
    publish_tf = atoi(argv[1]);
  }

  volksbot::Odometry odo(
      publish_tf); // blocks internally via rclcpp::spin() until shutdown

  // odo.update(70);

  rclcpp::shutdown();

  return 0;
}
