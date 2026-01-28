
#include "CVmc.h"

#ifdef REAL_TIME
#include <sys/mman.h>
#include <native/task.h>
#include <native/timer.h>
#endif


namespace VMC {
	const int CVmc::MOTOR_RPM= 0;
	const int CVmc::MOTOR_PWM= 1;
	const int CVmc::MOTOR_CURRENT= 2;
	const int CVmc::MOTOR_TICKS_ABSOLUTE= 3;
	const int CVmc::MOTOR_TICKS_RELATIVE= 4;
	//const int CVmc::MOTOR_POWER= 5;
	//const int CVmc::MOTOR_TEMPERATURE= 6;
	const int CVmc::BATTERY_VOLTAGE= 7;
	const int CVmc::VMC_ERROR= 0x80000000;

	static constexpr int MOTOR_INDEX_RIGHT = 1;
	static constexpr int MOTOR_INDEX_LEFT  = 2;


	bool CVmc::connect( const char* port ) { init( port ); return isConnected(); }
	void CVmc::disconnect() {
		///////////////////////////////////// @@@
		//  fclose(file );


		_apiObject->printAllErrors();

		if(_isConnected) {
			_pwmOut1= 0;
			_pwmOut2= 0;
			_pwmOut3= 0;

			wait(_cycleTime);
			wait(_cycleTime);
			wait(_cycleTime);
			wait(_cycleTime);

			_isConnected= 0;
			wait(_cycleTime);
			wait(_cycleTime);

			_apiObject->closeDevice();

#ifdef WIN32
			DeleteCriticalSection(&_cs);
#elif REAL_TIME
			rt_task_delete(&vmc_thread);
#else
			pthread_mutex_destroy(&_mutex);
#endif
		}
		delete _apiObject;
	}
	bool CVmc::is_connected() { return isConnected(); }

	void CVmc::reset_ticks() { resetMotorTicks(); }
	void CVmc::set_max_RPM( int maxRPM ) { setMaximumRPM( maxRPM ); }
	int  CVmc::get_max_RPM() { return _maxRpm; }

	void CVmc::set_speeds( float left, float right ) { 
		setMotorVelocity( MOTOR_INDEX_LEFT,  left );
		setMotorVelocity( MOTOR_INDEX_RIGHT, right );
	}
	void CVmc::get_ticks( int& left, int& right ) {
		left  = getMotorValue( MOTOR_INDEX_LEFT,  VMC::CVmc::MOTOR_TICKS_ABSOLUTE );
		right = getMotorValue( MOTOR_INDEX_RIGHT, VMC::CVmc::MOTOR_TICKS_ABSOLUTE );
	}



#ifdef WIN32
	DWORD WINAPI vmcThreadFunction(LPVOID param)
#elif REAL_TIME
	void vmcThreadFunction(void* param)
#else
	void* vmcThreadFunction(void* param)
#endif
	{
#ifdef REAL_TIME
		rt_task_set_periodic(NULL, TM_NOW, 40000000);
#endif

		CVmc* pThread = (CVmc*)param;  // typecast

		pThread->clearResponseList();
		pThread->addStateToResponseList(CVmc::MOTOR_TICKS_ABSOLUTE);

		while(pThread->isConnected()) {
			pThread->enterCriticalSection();
			// old setting motor values could crash because of wrong mutex use
			//    pThread->_apiObject->useVMC().MotorRPMs.Set(pThread->_pwmOut1,
			//        pThread->_pwmOut2, pThread->_pwmOut3);

			CStorage store = pThread->_apiObject->useVMC();
			store.MotorRPMs.Set( pThread->_pwmOut1, pThread->_pwmOut2, pThread->_pwmOut3 );
			
			pThread->leaveCriticalSection();

			if(pThread->_digitalInputUpdate) {
				pThread->_apiObject->useVMC().DigitalIN.Update();
			}

#ifdef REAL_TIME
			rt_task_wait_period(NULL);
#else
			pThread->wait(pThread->_cycleTime);
#endif
		}
#ifndef REAL_TIME
		return 0;
#endif
	}

	bool CVmc::auto_connect() {
char port[20];
		int i;
		int index;

		_isConnected= 0;

#ifdef WIN32	
		port[0]= 'C';
		port[1]= 'O';
		port[2]= 'M';
		i= 1;
		index= 3;
#elif REAL_TIME
		strcpy(port, "rtser");
		i= 0;
		index= 9;
#else
		strcpy(port, "/dev/ttyS");
		i= 0;
		index= 9;
#endif

		while((i<10) && (!_isConnected)) {
			port[index]= i + 48;
			port[index+1]= 0x00;

			init(port);
			i++;
		}

		return _isConnected;
	}

	CVmc::CVmc() {
		_maxRpm= 6000;
		//_cycleTime= 20;
		_cycleTime= 50;    // modified to 20 Hz, because 50 Hz (as before) is incorrect
		_isConnected= 0;

		_pwmOut1= 0;
		_pwmOut2= 0;
		_pwmOut3= 0;

		_digitalOut1= false;
		_digitalOut2= false;
		_digitalOut3= false;

		_digitalInputUpdate= false;

		strcpy(_comPort, "No connection!");
	}

	CVmc::~CVmc() {
		disconnect();
	}

	void CVmc::addStateToResponseList(int state) {
		_apiObject->configRequestMessage(state, true);
		_responseList[state]= true;
	}

	void CVmc::clearResponseList() {
		for(int i=0; i<10; i++) {
			removeStateFromResponseList(i);
		}
	}

	char* CVmc::getComPortString() {
		return _comPort;
	}

	int CVmc::getDigitalValue(int input) {
		if(!_digitalInputUpdate) return VMC_ERROR;
		if((input < 1) || (input > 3)) return VMC_ERROR;

		int bitPattern= (int) _apiObject->useVMC().DigitalIN.getValue();

		switch(input) {
			case 1:

				if(_digitalIO1) return VMC_ERROR;
				if((bitPattern & 0x01) > 0) return 1;
				else return 0;
				break;

			case 2:

				if(_digitalIO2) return VMC_ERROR;
				if((bitPattern & 0x02) > 0) return 1;
				else return 0;
				break;

			case 3:

				if(_digitalIO3) return VMC_ERROR;
				if((bitPattern & 0x04) > 0) return 1;
				else return 0;
				break;

			default:

				return VMC_ERROR;
		}
	}

	int CVmc::getMotorValue(int motor, int state) {
		if((motor < 1) || (motor > 3)) return VMC_ERROR;

		int value= 0;
		motor--;

		if(_responseList[state] == false) {
			return VMC_ERROR;
		}

		switch(state) {
			case MOTOR_RPM:

				value= (int) _apiObject->useVMC().Motor[motor].ActualRPM.getValue();
				break;

			case MOTOR_PWM:

				value= (int) _apiObject->useVMC().Motor[motor].ActualPWM.getValue();
				break;

			case MOTOR_CURRENT:

				value= (int) _apiObject->useVMC().Motor[motor].ActualCurrent.getValue();
				break;

			case MOTOR_TICKS_ABSOLUTE:
				// TODO do this casting everywhere
				value= (int) ((long)_apiObject->useVMC().Motor[motor].AbsolutRotations.getValue());
				break;

			case MOTOR_TICKS_RELATIVE:

				value= (int) _apiObject->useVMC().Motor[motor].EncoderTicksRelativ.getValue();
				break;

				//		case MOTOR_POWER:
				//
				//			value= (int) _apiObject->useVMC().Motor[motor].ActualPowerOutput.getValue();
				//			break;

				//		case MOTOR_TEMPERATURE:
				//
				//			value= (int) apiObject->useVMC().Motor[motor].ActualWindingTemperature.getValue();
				//			break;

			default:
				value= VMC_ERROR;
		}
		return value;
	}
	
	int CVmc::getMotorValueLeft(int state) {
		int value= getMotorValue(2, state);

		if(value == VMC_ERROR) return value;

		if((state == MOTOR_TICKS_ABSOLUTE) ||
		   (state == MOTOR_RPM) ||
		   (state == MOTOR_PWM) ||
		   (state == MOTOR_TICKS_RELATIVE)) value *= -1;

		return value;
	}

	int CVmc::getMotorValueRight(int state) {
		return getMotorValue(1, state);
	}

	int CVmc::getValue(int state) {
		int value= VMC_ERROR;

		switch(state) {
			case BATTERY_VOLTAGE:
				value= (int) _apiObject->useVMC().BatteryVoltage.getValue();
				break;
		}
		return value;
	}

	bool CVmc::isConnected() {
		return _isConnected;
	}

	void CVmc::resetMotorTicks() {
		_apiObject->useVMC().ClearAllAbsolutRotations.Set(0);
	}

	void CVmc::resetMotorTicks(int motor) {
		if((motor < 1) || (motor > 3)) return;

		_apiObject->useVMC().Motor[motor-1].ClearOneAbsolutRotations.Set(0);
	}

	void CVmc::setCycleTime(int milliseconds) {
		if((milliseconds >= 20) && (milliseconds <= 1000)) _cycleTime= milliseconds;
	}

	void CVmc::setDigitalIOConfiguration(bool io1, bool io2, bool io3) {
		int config= 0;
		_digitalInputUpdate= false;

		if(io1) config += 1;
		if(io2) config += 2;
		if(io3) config += 4;

		if(!io1) _digitalInputUpdate= true;
		if(!io2) _digitalInputUpdate= true;
		if(!io3) _digitalInputUpdate= true;

		_digitalIO1= io1;
		_digitalIO2= io2;
		_digitalIO3= io3;
		_apiObject->useVMC().IOPortConfiguration.Set(config);
	}

	void CVmc::setDigitalValue(int output, bool value) {
		if((output < 1) || (output > 3)) return;

		int bitPattern= 0;

		switch(output) {
			case 1:

				if(_digitalIO1) {
					if (value) { bitPattern += 1; _digitalOut1= true; }
					if (_digitalOut2) bitPattern += 2;
					if (_digitalOut3) bitPattern += 4;
				}
				break;

			case 2:

				if(_digitalIO2) {
					if (_digitalOut1) bitPattern += 1;
					if (value) { bitPattern += 2; _digitalOut2= true; }
					if (_digitalOut3) bitPattern += 4;
				}
				break;

			case 3:

				if(_digitalIO3) {
					if (_digitalOut1) bitPattern += 1;
					if (_digitalOut2) bitPattern += 2;
					if (value) { bitPattern += 4; _digitalOut3= true; }
				}
				break;
		}

		_apiObject->useVMC().DigitalOUT.Set(bitPattern);
	}

	void CVmc::setDigitalValues(bool value1, bool value2, bool value3) {
		int bitPattern= 0;

		if(value1 && _digitalOut1) bitPattern += 1;
		if(value2 && _digitalOut2) bitPattern += 2;
		if(value3 && _digitalOut3) bitPattern += 4;

		_apiObject->useVMC().DigitalOUT.Set(bitPattern);
	}

	void CVmc::setMaximumRPM(int rpm) {
		if((rpm >= 0) && (rpm <= 8000)) _maxRpm= rpm;
	}

	void CVmc::setMotorLeft(int velocity) {
		if((velocity < -100) || (velocity > 100)) return;

		setMotorRPM(2, -(velocity*_maxRpm)/100);
	}

	void CVmc::setMotorRight(int velocity) {
		if((velocity < -100) || (velocity > 100)) return;

		setMotorRPM(1, (velocity*_maxRpm)/100);
	}

	void CVmc::setMotorRPM(int motor, int rpm) {
		if((rpm < -1*_maxRpm) || (rpm > _maxRpm)) return;
		if((motor < 1) || (motor > 3)) return;

		enterCriticalSection();

		switch(motor) {
			case 1: _pwmOut1= rpm; break;
			case 2: _pwmOut2= rpm; break;
			case 3: _pwmOut3= rpm; break;
			default: break;
		}

		leaveCriticalSection();
	}

	void CVmc::setMotorVelocity(int motor, int velocity) {
		if((velocity < -100) || (velocity > 100)) return;

		setMotorRPM(motor, (velocity*_maxRpm)/100);
	}

	void CVmc::setMotors(int velocity1, int velocity2, int velocity3) {
		if((velocity1 < -100) || (velocity1 > 100)) return;
		if((velocity2 < -100) || (velocity2 > 100)) return;
		if((velocity3 < -100) || (velocity3 > 100)) return;

		setMotorRPM(1, (velocity1*_maxRpm)/100);
		setMotorRPM(2, (velocity2*_maxRpm)/100);
		setMotorRPM(3, (velocity3*_maxRpm)/100);
	}

	void CVmc::setMotors(int velocityLeft, int velocityRight) {
		if((velocityLeft < -100) || (velocityLeft > 100)) return;
		if((velocityRight < -100) || (velocityRight > 100)) return;

		setMotorLeft(velocityLeft);
		setMotorRight(velocityRight);
	}

	void CVmc::removeStateFromResponseList(int state) {
		_apiObject->configRequestMessage(state, false);
		_responseList[state]= false;
	}

	void CVmc::wait(int milliseconds) {
#ifdef WIN32
		Sleep(milliseconds);
#elif REAL_TIME
		//rt_task_sleep(milliseconds*1000000);
		rt_task_sleep(milliseconds*1000000);
#else
		usleep(milliseconds*1000);
#endif
	}

	void CVmc::enterCriticalSection() {
#ifdef WIN32
		EnterCriticalSection(&_cs);
#elif REAL_TIME
		// no mutex needed
#else
		pthread_mutex_lock(&_mutex);
#endif
	}

	void CVmc::leaveCriticalSection() {
#ifdef WIN32
		LeaveCriticalSection(&_cs);
#elif REAL_TIME
		// no mutex needed
#else
		pthread_mutex_unlock (&_mutex);
#endif
	}

	void CVmc::init(const char* comPort) {
#ifdef WIN32
		DWORD threadId;
#elif REAL_TIME
#else
		pthread_t threadId;
#endif

		_maxRpm= 6000;
		//_cycleTime= 20;
		_cycleTime= 50;    // modified to 20 Hz, because 50 Hz (as before) is incorrect
		_isConnected= 0;

		_pwmOut1= 0;
		_pwmOut2= 0;
		_pwmOut3= 0;

		_digitalOut1= false;
		_digitalOut2= false;
		_digitalOut3= false;

		_digitalInputUpdate= false;

		strcpy(_comPort, "No connection!");

		_apiObject= new VMC::CvmcAPI();

		_apiObject->selectHardwareAdapter(VMC::RS232);
		_apiObject->selectDevice(comPort);

		int isComPortOpened= _apiObject->openDevice();


#ifndef REAL_TIME
		if(isComPortOpened > 0) {
			bool ret = _apiObject->useVMC().BatteryVoltage.Update();
			if( ret ) {
				LOG_LN_INFO("CVmc:: battery voltage updated");
			} else {
				LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "CVmc:: battery voltage update failed") );
			}
			wait(150);
			float voltage = _apiObject->useVMC().BatteryVoltage.getValue();
			
			LOG_LN_INFO("voltage is %f", voltage);
			
			if(voltage == 0) 
				return;
		} else {
			return;
		}

		_isConnected= 1;
		strncpy(_comPort, comPort, 40);
		_comPort[40]= 0x00;

		clearResponseList();
		addStateToResponseList(MOTOR_TICKS_ABSOLUTE);

#ifdef WIN32
		InitializeCriticalSection(&_cs);
		CreateThread( 0,
					  0,
					  (LPTHREAD_START_ROUTINE) vmcThreadFunction,
					  (LPVOID) this,
					  0,
					  &threadId);
#else
		pthread_mutex_init(&_mutex, NULL);
		pthread_create(&threadId, NULL, vmcThreadFunction, (void *)this);
#endif

#else // REAL_TIME
		if(isComPortOpened > 0) {
			LOG_LN_INFO("port opened, entering real time mode...");
		}
		else return;

		_isConnected= 1;
		strncpy(_comPort, comPort, 40);
		_comPort[40]= 0x00;


		LOG_LN_INFO("create task...");
		int err = rt_task_create(&vmc_thread, "vmc_thread", 0, 51, 0);
		if (err) {
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "task creation failed!  %s"), strerror(-err));
			exit(0);
		}

		LOG_LN_INFO("start task...");
		rt_task_start(&vmc_thread, &vmcThreadFunction, (void *)this);
		if (err) {
			LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "task didnt start!") );
			exit(0);
		}

#endif
	}

}  // namespace VMC
