#ifndef EVENT_RELAY_HPP
#define EVENT_RELAY_HPP

#include <WPILib.h>
#include "ActionMap.hpp"
#include "JoystickWrapper.hpp"
#include <iostream>

class EventRelay
{
private:
	ActionMap actionMap;
	JoystickWrapper joyWrap;
public:
	void checkStates();
	ActionMap& getMap();
	EventRelay();
	RobotDrive driveRobot;
};

#endif
