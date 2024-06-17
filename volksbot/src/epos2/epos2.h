#ifndef EPOS2_H
#define EPOS2_H

#include "Definitions.h"
#include <pthread.h>
#include <stdint.h>
#include <cmath>
#include "ros/ros.h"
#include "volksbot/ticks.h"
#include "volksbot/velocities.h"
#include "std_srvs/Empty.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "volksbot/vels.h"

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
	bool callback(volksbot::velocities::Request& vel, volksbot::velocities::Response& response);
	void Vcallback(const volksbot::velsConstPtr& vel);
	void CVcallback(const geometry_msgs::Twist::ConstPtr& cmd_vel);

	//Thread Loop Function
	static void* threadFunction(void* param);

	//ROS Node Variables
	ros::NodeHandle n;
	ros::Publisher pub;
	ros::Subscriber sub;
	ros::Subscriber cmd_vel_sub_;
	ros::ServiceServer service;

	ros::Time lastcommand;

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
