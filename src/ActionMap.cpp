#include "WPILib.h"
#include "ActionMap.hpp"
#include <utility>

ActionMap::ActionMap()
{
}

void ActionMap::associate(JoyButton button, Action<void()> action)
{
	std::pair<JoyButton, Action<void()>> buttonPair(button, action);
	buttonMap.insert(buttonPair);
}

bool ActionMap::eventOccurredFor(JoyButton button)
{
	if (buttonMap.find(button) == buttonMap.end())
	{
		return false;
	}
	else
	{
		auto action = buttonMap.find(button)->second;
		action.run();
		return true;
	}
}


