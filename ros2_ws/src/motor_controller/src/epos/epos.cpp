#include "epos.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

namespace EPOS {

// logs fault and clears fault. returns true iff fault was present
bool EPOS::reportFault(int g_usNodeId) {
	int oIsFault = 0;
	if ( VCS_GetFaultState(g_pKeyHandle, g_usNodeId, &oIsFault, &g_pErrorCode ) == 0 ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Unable to GetFaultState of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );
		return true;
	}
	
	if( oIsFault ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Fault detected of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );

		if ( VCS_ClearFault(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0) {
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Unable ClearFault of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );
		}
		return true;
	}

	return false;
}

template< typename T >
static void left_right_mapping( T ileft, T iright, T& oleft, T& oright ) {
	oright =  ileft;
	oleft  = -iright;
}
template< typename T >
static void left_right_mapping( T& left, T& right ) { left_right_mapping(left, right, left, right); }

void* EPOS::thread_function(void* param) {
	EPOS* ref = (EPOS*) param;

	static constexpr useconds_t SLEEP_LOOP_NORM =  50'000; 	//  50 ms
	static constexpr useconds_t SLEEP_FAULT 	= 500'000; 	// 500 ms
	
	useconds_t sleep_time;
	while ( ref->is_connected() ) {
		sleep_time = SLEEP_LOOP_NORM;

		if( ref->reportFault(0) || ref->reportFault(1) ) {
			ref->set_speeds(0, 0);
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Force Stop motors due to existing Fault") );
			sleep_time = SLEEP_FAULT;
		}
		
		if ( VCS_MoveWithVelocity( ref->g_pKeyHandle, 1, ref->g_speed_right / 100.0 * ref->g_maxRPM, &ref->g_pErrorCode ) == 0 ||
			 VCS_MoveWithVelocity( ref->g_pKeyHandle, 0, ref->g_speed_left  / 100.0 * ref->g_maxRPM, &ref->g_pErrorCode ) == 0 ) {
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Cannot Send Move Instruction to EPOS Device! (0x%x)"), ref->g_pErrorCode );
			sleep_time = SLEEP_FAULT;
		}
		
		usleep(sleep_time);
	}

	return nullptr;
}

bool EPOS::connect( const char* port ) {
	g_pKeyHandle  = 0;
	g_isConnected = false;
	strncpy( g_PortName, port, sizeof(g_PortName)-1 );

	LOG_LN_DEBUG( "[" COL(FG_BRIGHT_BLUE, "%s") "] trying to connect via port " COL(FG_BRIGHT_BLUE, "%s"), g_DeviceName, g_PortName );

	if ( !openEPOSDevice() ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Cannot Open EPOS Device! (0x%x)"), g_pErrorCode );
		return false;
	}

	if ( !prepareEPOSDevice(0) || !prepareEPOSDevice(1) ) { // R = 0, L = 1
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Error Preparing EPOS Device! (0x%x)"), g_pErrorCode );
		return false;
	}

	g_isConnected = true;

	if ( VCS_ActivateProfileVelocityMode( g_pKeyHandle, 0, &g_pErrorCode ) == 0 ||
		 VCS_ActivateProfileVelocityMode( g_pKeyHandle, 1, &g_pErrorCode ) == 0 ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Cannot Activate Velocity Mode in EPOS Device! (0x%x)"), g_pErrorCode );
		return false;
	}
	
	reset_ticks();

	pthread_create(&threadId, NULL, &EPOS::thread_function, this);

	return true;
}
void EPOS::disconnect() {
	if ( VCS_HaltVelocityMovement( g_pKeyHandle, 1, &g_pErrorCode ) == 0 ||
		 VCS_HaltVelocityMovement( g_pKeyHandle, 0, &g_pErrorCode ) == 0) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Cannot Stop Velocity Mode in EPOS Device! (0x%x), may disregard since we are disconnecting"), g_pErrorCode );
		return;
	}

	VCS_WaitForTargetReached( g_pKeyHandle, 1, 2000, &g_pErrorCode );
	VCS_WaitForTargetReached( g_pKeyHandle, 0, 2000, &g_pErrorCode );

	closeEPOSDevice();
}
bool EPOS::is_connected() { return g_isConnected; }

void EPOS::reset_ticks() {
	if ( VCS_GetPositionIs( g_pKeyHandle, 1, &g_ticks_offset_right, &g_pErrorCode) == 0 ||
		 VCS_GetPositionIs( g_pKeyHandle, 0, &g_ticks_offset_left,  &g_pErrorCode) == 0 ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Cannot Get Position of EPOS Device! (0x%x)"), g_pErrorCode );
	}
}
void EPOS::set_max_RPM( int maxRPM ) {
	// max RPM actually is 12000 but this is way to fast!
	// therefor we max it at 6000 for now
	if( maxRPM <= 0 || maxRPM >= 6000 ) return;
	g_maxRPM = maxRPM;
}
int  EPOS::get_max_RPM() { return g_maxRPM; }

void EPOS::set_speeds( float left, float right ) {
	left_right_mapping( left, right, g_speed_left, g_speed_right );
}
void EPOS::get_ticks( int& left, int& right ) {
	if ( VCS_GetPositionIs( g_pKeyHandle, 1, &right, &g_pErrorCode) == 0 ||
		 VCS_GetPositionIs( g_pKeyHandle, 0, &left,  &g_pErrorCode) == 0 ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Cannot Get Position of EPOS Device! (0x%x)"), g_pErrorCode );
		return;
	}

	right -= g_ticks_offset_right;
	left  -= g_ticks_offset_left;
	left_right_mapping( left, right );
}


EPOS::EPOS(EPOS_VERSION epv) {
	controller_version = epv;

	switch (controller_version) {
		case EPOS_VERSION::EPOS2:
		case_EPOS2:
			g_DeviceName[sizeof("EPOS")-1] = '2';
			break;
		case EPOS_VERSION::EPOS4:
			g_DeviceName[sizeof("EPOS")-1] = '4';
			break;
		
		default:
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Invalid EPOS version, will initialize with EPOS2") );
			goto case_EPOS2;
		break;
	}

	LOG_LN_INFO( "created " COL(FG_BRIGHT_BLUE, "%s") " instance", g_DeviceName );
}

EPOS::~EPOS() { disconnect(); }


bool EPOS::openEPOSDevice() {
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

bool EPOS::prepareEPOSDevice(int g_usNodeId) {
	int oIsFault = 0;
	if ( VCS_GetFaultState(g_pKeyHandle, g_usNodeId, &oIsFault, &g_pErrorCode ) == 0 ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Unable to GetFaultState of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );
		return false;
	}

	if( oIsFault ) {
		if ( VCS_ClearFault(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0) {
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Unable to ClearFault of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );
			return false;
		}
	}

	int oIsEnabled = 0;
	if ( VCS_GetEnableState(g_pKeyHandle, g_usNodeId, &oIsEnabled, &g_pErrorCode) == 0 ) {
		LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Unable to GetEnableState of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );
		return false;
	}

	if( !oIsEnabled ) {
		if( VCS_SetEnableState(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0 ) {
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Unable to SetEnableState of Node [%d] with code (0x%x)"), g_usNodeId, g_pErrorCode );
			return false;
		}
	}
	
	return true;
}

bool EPOS::closeEPOSDevice() {
	return VCS_CloseDevice(g_pKeyHandle, &g_pErrorCode) != 0 && g_pErrorCode == 0;
}

} // namespace EPOS
