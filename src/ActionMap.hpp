#ifndef ACTIONMAP_HPP
#define ACTIONMAP_HPP

#include <Action.hpp>
#include <Button.hpp>
#include <vector>
#include <utility>

class ActionMap
{
public:
	void associate();
	bool eventOccuredFor();
private:
	std::vector<std::pair<Button, Action>> ButtonMap;
};

#endif
