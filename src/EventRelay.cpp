#include "EventRelay.hpp"
#include "ActionMap.hpp"

EventRelay::EventRelay()
	: actionMap()
	, joyWrap()
{
	std::cout << "Yeeeee... That Event Relay online" << std::endl;
}

void EventRelay::checkStates()
{
	joyWrap.pollJoystick();
	std::array<JoyButton, 12> buttonStates = joyWrap.getStates();
	std::cout << "Mmmmmm... That check states Doge..." << std::endl;

	for(int i = 0; i < buttonStates.size(); i++)
	{
		if(buttonStates[i].pressed || buttonStates[i].up || buttonStates[i].down)
		{
			actionMap.eventOccurredFor(buttonStates[i]);
		}
	}
}


ActionMap EventRelay::getMap()
{
	std::cout << "Got that map... You \'na\' me?" << std::endl;
	return actionMap;
}
