#ifndef EPOS2_H
#define EPOS2_H

#include "Definitions.h"
#include <pthread.h>
#include <stdint.h>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "volksbot/msg/ticks.hpp"
#include "volksbot/srv/velocities.hpp"
#include <std_srvs/srv/empty.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "volksbot/msg/vels.hpp"

#define MAX_RPM 4000 // MOTOR MAX IS REALLY 12000 BUT IS TOO FAST!!!

// 148000 tics per rev, 26 cm diameter, 81.68 cm per rev, 1811.9178 tics/cm

class EPOS2 {

public:

	EPOS2();
	EPOS2(const char* port);
	~EPOS2();

	bool isConnected();

private:

	//ROS Callback Functions
	bool callback(volksbot::srv::velocities::Request& vel, volksbot::srv::velocities::Response& response);
	void Vcallback(const volksbot::msg::vels::ConstSharedPtr& vel);
	void CVcallback(const geometry_msgs::msg::Twist::ConstSharedPtr& cmd_vel);

	//Thread Loop Function
	static void* threadFunction(void* param);

	//ROS Node Variables
	rclcpp::Node n;
	ros::Publisher pub;
	ros::Subscriber sub;
	ros::Subscriber cmd_vel_sub_;
	ros::ServiceServer service;

	rclcpp::Time lastcommand;

	//Other Variables
	pthread_t threadId;
	double leftvel;
	double rightvel;
	double vx;
	double vth;

	//EPOS2 Functions
	void init(const char* port);
	bool openEPOSDevice();
	bool closeEPOSDevice();
	bool prepareEPOSDevice(int g_usNodeId);

	//EPOS2 Variables
	void* g_pKeyHandle;
	char g_DeviceName[100];
	char g_ProtocolStackName[100];
	char g_InterfaceName[100];
	char g_PortName[100];
	int g_baudrate;
	unsigned int g_pErrorCode;
	bool g_isConnected;

};

#endif
