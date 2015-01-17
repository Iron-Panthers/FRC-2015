#include "EventRelay.hpp"
#include "ActionMap.hpp"
#include <WPILib.h>
#include <iostream>

EventRelay::EventRelay()
{
	std::cout << "HeroCat!" << std:endl;
}

void EventRelay::checkStates()
{
	std::cout << "Hello Cat!" << std:endl;
	JoystickWrapper::getStates();
	ActionMap::buttonEvent();
}

ActionMap EventRelay::getMap()
{
	std:cout << "Hello Doge!" << std::endl;
	return actionMap;
}
