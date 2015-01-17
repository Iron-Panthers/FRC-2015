#ifndef ACTIONMAP_HPP
#define ACTIONMAP_HPP

#include "Action.hpp"
#include "JoyButton.hpp"
#include <vector>
#include <utility>

class ActionMap
{
public:
	ActionMap();

	void associate(JoyButton button, Action<void()> action);
	bool eventOccuredFor(JoyButton button);
private:
	std::vector<std::pair<JoyButton, Action<void()>>> buttonMap;

};

#endif
