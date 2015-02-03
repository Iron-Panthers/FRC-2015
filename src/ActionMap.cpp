#include "WPILib.h"
#include "ActionMap.hpp"
#include <utility>

ActionMap::ActionMap()
{
	std::cout << "ActionMap Online" << std::endl;
}

void ActionMap::associate(JoyButton button, Action<void()> action)
{
	std::cout << "Associate Online" << std::endl;
	std::pair<JoyButton, Action<void()>> buttonPair(button, action);
	buttonMap.insert(buttonPair);
}

bool ActionMap::eventOccurredFor(JoyButton button)
{
	std::cout << "test " << std::endl;

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


