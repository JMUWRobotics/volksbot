#include "odometry/odometry.h"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
	auto node = std::make_shared<rclcpp::Node>("Odometry");

  bool publish_tf = true;

  if(argc > 1) {
    publish_tf = atoi(argv[1]);
  }

  volksbot::Odometry odo(publish_tf);
  
  // odo.update(70);
  
  rclcpp::spin(node);

  rclcpp::shutdown();

	return 0;
}
