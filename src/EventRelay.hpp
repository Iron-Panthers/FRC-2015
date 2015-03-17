#ifndef EVENT_RELAY_HPP
#define EVENT_RELAY_HPP

#include <WPILib.h>
#include "ActionMap.hpp"
#include "JoystickWrapper.hpp"
#include <iostream>

class EventRelay
{
private:
	ActionMap actionMapJoy;
	ActionMap actionMapGCN;
	JoystickWrapper joyWrap;
	JoystickWrapper gamecube;
public:
	void checkStates();
	ActionMap& getMapJoy();
	ActionMap& getMapGCN();

	EventRelay();

	RobotDrive driveRobot;
};

#endif
