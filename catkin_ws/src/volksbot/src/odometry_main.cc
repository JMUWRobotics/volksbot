#include "volksbot/odometry.h"

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("Odometry");

  bool publish_tf = true;

  if(argc > 1) {
    publish_tf = atoi(argv[1]);
  }

  volksbot::Odometry odo(publish_tf);
  rclcpp::spin(node);
  //odo.update(70);

	return 0;
}
