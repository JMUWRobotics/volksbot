#ifndef EPOS2_H
#define EPOS2_H

#include "Definitions.h"
#include <pthread.h>
#include <stdint.h>
#include <cmath>
#include <chrono>
#include <thread>
#include "rclcpp/rclcpp.hpp"
#include "volksface/msg/ticks.hpp"
#include "volksface/srv/velocities.hpp"
#include <std_srvs/srv/empty.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "volksface/msg/vel.hpp"

#define MAX_RPM 4000 // MOTOR MAX IS REALLY 12000 BUT IS TOO FAST!!!

// 148000 tics per rev, 26 cm diameter, 81.68 cm per rev, 1811.9178 tics/cm

class EPOS2 : public rclcpp::Node{

public:

	// constructor with default port
	EPOS2();

	// constructor with custom port
	EPOS2(const char* port);

	// deconstructor
	~EPOS2();

	bool isConnected();

private:

	//ROS2 Callback Functions
	void callback(const std::shared_ptr<const volksface::srv::Velocities::Request> vel, std::shared_ptr<volksface::srv::Velocities::Response> response);
	void Vcallback(const volksface::msg::Vel::ConstSharedPtr vel);
	void CVcallback(const geometry_msgs::msg::Twist::ConstSharedPtr cmd_vel);

	//Thread Loop Function
	static void* threadFunction(void* param);

	//ROS2 Node Variables
	rclcpp::Publisher<volksface::msg::Ticks>::SharedPtr pub_;
    rclcpp::Subscription<volksface::msg::Vel>::SharedPtr sub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
	rclcpp::Service<volksface::srv::Velocities>::SharedPtr service_;

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
