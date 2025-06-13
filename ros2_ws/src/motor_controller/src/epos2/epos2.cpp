#include "epos2.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace EPOS;

template< typename T >
static void left_right_mapping( T ileft, T iright, T& oleft, T& oright ) {
	oright =  ileft;
	oleft  = -iright;
}
template< typename T >
static void left_right_mapping( T& left, T& right ) { left_right_mapping(left, right, left, right); }

void* EPOS2::thread_function(void* param) {
	EPOS2* ref = (EPOS2*) param;

	while ( ref->is_connected() ) {
		if ( VCS_MoveWithVelocity( ref->g_pKeyHandle, 1, ref->g_speed_right / 100.0 * ref->g_maxRPM, &ref->g_pErrorCode ) == 0 ||
			 VCS_MoveWithVelocity( ref->g_pKeyHandle, 0, ref->g_speed_left  / 100.0 * ref->g_maxRPM, &ref->g_pErrorCode ) == 0 ) {
			// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Send Move Instruction to EPOS2 Device! (0x%x)", ref->g_pErrorCode);
			printf( "Cannot Send Move Instruction to EPOS2 Device! (0x%x)", ref->g_pErrorCode );
		}
		
		usleep(50000);
	}

	return nullptr;
}

bool EPOS2::connect( const char* port ) {
	g_pKeyHandle  = 0;
	g_isConnected = false;
	strncpy( g_PortName, port, sizeof(g_PortName)-1 );

	if ( !openEPOSDevice() ) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Open EPOS2 Device! (0x%x)", g_pErrorCode);
		printf( "Cannot Open EPOS2 Device! (0x%x)", g_pErrorCode );
		return false;
	}

	if ( !prepareEPOSDevice(0) || !prepareEPOSDevice(1) ) { //R = 0, L = 1
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Error Preparing EPOS2 Device! (0x%x)", g_pErrorCode);
		printf( "Error Preparing EPOS2 Device! (0x%x)", g_pErrorCode );
		return false;
	}

	g_isConnected = true;

	if ( VCS_ActivateProfileVelocityMode( g_pKeyHandle, 0, &g_pErrorCode ) == 0 ||
		 VCS_ActivateProfileVelocityMode( g_pKeyHandle, 1, &g_pErrorCode ) == 0 ) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Activate Velocity Mode in EPOS2 Device! (0x%x)", ref->g_pErrorCode);
		printf( "Cannot Activate Velocity Mode in EPOS2 Device! (0x%x)", g_pErrorCode );
		return false;
	}
	
	reset_ticks();

	pthread_create(&threadId, NULL, &EPOS2::thread_function, this);

	return true;
}
void EPOS2::disconnect() {
	if ( VCS_HaltVelocityMovement( g_pKeyHandle, 1, &g_pErrorCode ) == 0 ||
		 VCS_HaltVelocityMovement( g_pKeyHandle, 0, &g_pErrorCode ) == 0) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Stop Velocity Mode in EPOS2 Device! (0x%x)", ref->g_pErrorCode);
		printf( "Cannot Stop Velocity Mode in EPOS2 Device! (0x%x)", g_pErrorCode );
	}

	VCS_WaitForTargetReached( g_pKeyHandle, 1, 2000, &g_pErrorCode );
	VCS_WaitForTargetReached( g_pKeyHandle, 0, 2000, &g_pErrorCode );

	closeEPOSDevice();
}
bool EPOS2::is_connected() { return g_isConnected; }

void EPOS2::reset_ticks() {
	if ( VCS_GetPositionIs( g_pKeyHandle, 1, &g_ticks_offset_right, &g_pErrorCode) == 0 ||
		 VCS_GetPositionIs( g_pKeyHandle, 0, &g_ticks_offset_left,  &g_pErrorCode) == 0 ) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Get Position of EPOS2 Device! (0x%x)", ref->g_pErrorCode);
		printf( "Cannot Get Position of EPOS2 Device! (0x%x)", g_pErrorCode );
	}
}
void EPOS2::set_max_RPM( int maxRPM ) {
	// max RPM actually is 12000 but this is way to fast!
	// therefor we max it at 6000 for now
	if( maxRPM <= 0 || maxRPM >= 6000 ) return;
	g_maxRPM = maxRPM;
}
int  EPOS2::get_max_RPM() { return g_maxRPM; }

void EPOS2::set_speeds( float left, float right ) {
	left_right_mapping( left, right, g_speed_left, g_speed_right );
}
void EPOS2::get_ticks( int& left, int& right ) {
	if ( VCS_GetPositionIs( g_pKeyHandle, 1, &right, &g_pErrorCode) == 0 ||
		 VCS_GetPositionIs( g_pKeyHandle, 0, &left,  &g_pErrorCode) == 0 ) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Get Position of EPOS2 Device! (0x%x)", ref->g_pErrorCode);
		printf( "Cannot Get Position of EPOS2 Device! (0x%x)", g_pErrorCode );
	}

	right -= g_ticks_offset_right;
	left  -= g_ticks_offset_left;
	left_right_mapping( left, right );
}


EPOS2::EPOS2() { }

EPOS2::~EPOS2() { disconnect(); }


bool EPOS2::openEPOSDevice() {
	g_pKeyHandle = VCS_OpenDevice(g_DeviceName, g_ProtocolStackName, g_InterfaceName, g_PortName, &g_pErrorCode);

	if( g_pKeyHandle == 0 || g_pErrorCode != 0 ) {
		g_pKeyHandle = 0;
		return false;
	}

	unsigned int lBaudrate = 0;
	unsigned int lTimeout = 0;

	if( VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, &g_pErrorCode) == 0 ) { return false; }
	if( VCS_SetProtocolStackSettings(g_pKeyHandle, g_baudrate,  lTimeout, &g_pErrorCode) == 0 ) { return false; }
	if( VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, &g_pErrorCode) == 0 ) { return false; }

	return g_baudrate == (int) lBaudrate;
}

bool EPOS2::prepareEPOSDevice(int g_usNodeId) {
	int oIsFault = 0;
	if ( VCS_GetFaultState(g_pKeyHandle, g_usNodeId, &oIsFault, &g_pErrorCode ) == 0 ) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "GetFaultState");
		printf( "GetFaultState" );
		return false;
	}

	if( oIsFault ) {
		if ( VCS_ClearFault(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0) {
			// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "ClearFault");
			printf( "ClearFault" );
			return false;
		}
	}

	int oIsEnabled = 0;
	if ( VCS_GetEnableState(g_pKeyHandle, g_usNodeId, &oIsEnabled, &g_pErrorCode) == 0 ) {
		// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "GetEnableState");
		printf( "GetEnableState" );
		return false;
	}

	if( !oIsEnabled ) {
		if( VCS_SetEnableState(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0 ) {
			// RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "SetEnableState");
			printf( "SetEnableState" );
			return false;
		}
	}
	
	return true;
}

bool EPOS2::closeEPOSDevice() {
	return VCS_CloseDevice(g_pKeyHandle, &g_pErrorCode) != 0 && g_pErrorCode == 0;
}
