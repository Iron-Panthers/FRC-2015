#ifndef ACTIONMAP_HPP
#define ACTIONMAP_HPP

#include "Action.hpp"
#include "JoyButton.hpp"
#include <utility>

class ActionMap
{
public:
	ActionMap();

	void associate(JoyButton button, Action<void()> action);
	bool eventOccurredFor(JoyButton button);
private:
	std::map<JoyButton, Action<void()> > buttonMap;
};

#endif
