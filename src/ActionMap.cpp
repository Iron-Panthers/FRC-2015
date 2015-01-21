#include "../src/ActionMap.hpp"

#include <WPILib.h>

ActionMap::ActionMap()
{
	std::cout << "ActionMap Online" << std::endl;
}

void ActionMap::associate(JoyButton button, Action<void()> action)
{
		std::cout << "Associate Online" << std::endl;
}

bool ActionMap::eventOccuredFor(JoyButton button)
{
	std::cout << "EventOccuredFor Online. BattleDoge" << std::endl;
}

