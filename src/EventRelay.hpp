#ifndef EVENT_RELAY_HPP
#define EVENT_RELAY_HPP

#include <WPILib.h>
#include "ActionMap.hpp"
#include "JoystickWrapper.hpp"
#include "MovingAverage.hpp"
#include <iostream>

class EventRelay
{
private:
	ActionMap actionMapJoy;
	ActionMap actionMapGCN;
	JoystickWrapper joyWrap;
	JoystickWrapper gamecube;
	MovingAverage<double> movingAverageDrive;
	MovingAverage<double> movingAverageTwist;

	bool onlyFB_GCN;
	Timer zeroMotorTimer;

public:
	void checkStates();
	ActionMap& getMapJoy();
	ActionMap& getMapGCN();

	void setFBGCN();
	void zeroMotors();

	EventRelay();

	RobotDrive driveRobot;
};

#endif
