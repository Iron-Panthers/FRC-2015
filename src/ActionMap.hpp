#ifndef ACTIONMAP_HPP
#define ACTIONMAP_HPP

#include <vector>
#include <utility>
#include "Action.hpp"
#include "Button.hpp"

class ActionMap
{
public:
	void associate();
	bool eventOccuredFor();
private:
	std::vector<std::pair<Button, Action>> ButtonMap;
};

#endif
