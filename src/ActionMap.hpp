#ifndef ACTIONMAP_HPP
#define ACTIONMAP_HPP

#include <vector>
#include <utility>
#include "../src/Action.hpp"
#include "../src/JoyButton.hpp"

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
