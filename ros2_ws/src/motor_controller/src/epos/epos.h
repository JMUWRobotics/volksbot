#ifndef __EPOS_H__
#define __EPOS_H__

#include "Definitions.h"
#include "../DriverInterface.h"

#include <pthread.h>


// regard this document for the EPOS4 SDK 
// https://www.maxongroup.com/medias/sys_master/root/9157360353310/EPOS-Command-Library-En.pdf
// Error codes can be found under Section 8 Error Overview
// ------------------------------------------------------------------------------- 25 Nov 2025

namespace EPOS {
	enum class EPOS_VERSION { EPOS2, EPOS4 };

	class EPOS : public mcd::I_MCD {
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
	
	
		EPOS(EPOS_VERSION epv);
	
		~EPOS() override;
	
	private:
		//EPOS2 Functions
		bool openEPOSDevice();
		bool closeEPOSDevice();
		bool prepareEPOSDevice(int g_usNodeId);
		bool reportFault(int g_usNodeId);
	
		//EPOS2 Variables
		EPOS_VERSION controller_version;
		char g_DeviceName[100] = "EPOS";
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
