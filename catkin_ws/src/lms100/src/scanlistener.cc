#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/laser_scan.hpp>
#include <stdlib.h>

#include <stdio.h>
FILE * gnup ;

void chatterCallback(const sensor_msgs::msg::LaserScan::ConstSharedPtr& scan )
{
    RCLCPP_INFO(rclcpp::get_logger("Lms100"), "Received scan\n");
    FILE *dat = fopen("/tmp/dat.txt","w");
    for (unsigned int i = 0; i < scan->ranges.size(); i++) {
      fprintf(dat, "%f\n", scan->ranges[i]  );
    }
    
    fprintf(gnup, "plot '/tmp/dat.txt' u 0:1\n");
    fflush(gnup);
}
int main(int argc, char** argv)
{
  gnup = popen("gnuplot","w");
  rclcpp::init(argc, argv);
  auto n = rclcpp::Node::make_shared("listener");
  auto chatter_sub = n.subscribe("LMS100", 1, chatterCallback);
  rclcpp::spin(node);

  pclose(gnup);
}

