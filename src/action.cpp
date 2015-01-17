#include "Action.hpp"
#include <functional>
#include <iostream>

template <typename T>
Action::Action(std::function<T> func, int cost = 0)
{
	std::cout << "Action constructor was called." << std::endl;
}

template <typename T>
void Action::run() const
{
	std::cout << "run was called in Action" << std::endl;
}
