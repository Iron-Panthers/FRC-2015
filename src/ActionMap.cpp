#include <WPILib.h>
#include "ActionMap.hpp"
#include <utility>

ActionMap::ActionMap()
{
	std::cout << "ActionMap Online" << std::endl;
}

void ActionMap::associate(JoyButton button, Action<void()> action)
{
		std::cout << "Associate Online" << std::endl;
		buttonMap.insert(std::make_pair(button, action));
}

bool ActionMap::eventOccuredFor(JoyButton button)
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


