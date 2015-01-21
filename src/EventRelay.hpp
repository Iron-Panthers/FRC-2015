#ifndef EVENT_RELAY_HPP
#define EVENT_RELAY_HPP

#include <WPILib.h>
#include "../src/ActionMap.hpp"
#include "../src/JoystickWrapper.hpp"

class EventRelay
{
private:
	ActionMap actionMap;
	JoystickWrapper joyWrap;
public:
	void checkStates();
	ActionMap getMap();
	EventRelay();
};

#endif
