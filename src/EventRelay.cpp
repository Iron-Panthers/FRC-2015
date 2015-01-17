#include "EventRelay.hpp"
#include "ActionMap.hpp"
#include <WPILib.h>
#include <iostream>

EventRelay::EventRelay()
{
	std::cout << "Yeeeee... That Event Relay online" << std::endl;
}

void EventRelay::checkStates()
{
	std::cout << "Mmmmmm... That check states Doge..." << std::endl;
	JoystickWrapper::getStates();
	ActionMap::buttonEvent();
}

ActionMap EventRelay::getMap()
{
	std::cout << "Got that map... You 'na me?" << std::endl;
	return actionMap;
}
