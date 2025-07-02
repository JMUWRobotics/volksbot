#ifndef EPOS2_H
#define EPOS2_H

#include "Definitions.h"
#include "../DriverInterface.h"

#include <pthread.h>


// regard this document for the EPOS2 SDK 
// https://www.maxongroup.com/medias/sys_master/8823917281310.pdf
// Error codes can be found at page 131
// ------------------------------------------------- 06 June 2025

namespace EPOS {
	class EPOS2 : public mcd::I_MCD {
		public:
		float ticks_per_revolution() override { return 148000; } // 148000 tics per rev, 26 cm diameter, 81.68 cm per rev, 1811.9178 tics/cm
	
		bool connect( const char* port ) override;
		void disconnect() override;
		bool is_connected() override;
	
		void reset_ticks() override;
		void set_max_RPM( int maxRPM ) override;
		int  get_max_RPM() override;
	
		void set_speeds( float left, float right ) override;
		void get_ticks( int& left, int& right ) override;
	
	
		EPOS2();
	
		~EPOS2();
	
	private:
		//EPOS2 Functions
		bool openEPOSDevice();
		bool closeEPOSDevice();
		bool prepareEPOSDevice(int g_usNodeId);
	
		//EPOS2 Variables
		char g_DeviceName[100] = "EPOS2";
		char g_ProtocolStackName[100] = "MAXON SERIAL V2";
		char g_InterfaceName[100] = "USB";
		int  g_baudrate = 1000000;
		
		unsigned int g_pErrorCode;
		void* g_pKeyHandle;
		char  g_PortName[100] = "";
		bool  g_isConnected = false;
		
		int g_maxRPM = 4000;
		int g_ticks_offset_left = 0;
		int g_ticks_offset_right = 0;
		
		float g_speed_left = 0;
		float g_speed_right = 0;


		pthread_t threadId;
		static void* thread_function(void* param);
	};

}

#endif
