#include "EventRelay.hpp"

#include <WPILib.h>
#include <iostream>
#include "ActionMap.hpp"
EventRelay::EventRelay()
	: actionMap()
	, joyWrap()
{
	std::cout << "Yeeeee... That Event Relay online" << std::endl;
}

void EventRelay::checkStates()
{
	std::array<JoyButton, 12>& buttonStates = joyWrap.getStates();
	std::cout << "Mmmmmm... That check states Doge..." << std::endl;

	for (std::array<JoyButton, 12>& buttonStates; buttonStates < 12; buttonStates++)
	{

	}
}


ActionMap EventRelay::getMap()
{
	std::cout << "Got that map... You \'na\' me?" << std::endl;
	return actionMap;
}
