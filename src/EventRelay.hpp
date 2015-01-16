#ifndef EVENT_RELAY_HPP
#define EVENT_RELAY_HPP

#include <WPILib.h>

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
