#include <WPILib.h>
#include "ActionMap.hpp"

ActionMap::ActionMap()
{
	std::cout << "ActionMap Online" << std::endl;
}

void ActionMap::associate()
{
		std::cout << "Associate Online" << std::endl;
}

bool ActionMap::eventOccuredFor()
{
	std::cout << "EventOccuredFor Online. BattleDoge" << std::endl;
}

