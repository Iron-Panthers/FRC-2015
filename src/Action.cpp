#include "Action.hpp"
#include <functional>
#include <iostream>

template <typename T>
Action<T>::Action(std::function<T> func, int cost)
	: callback(func)
	, cost(cost)
{
}

template <typename T>
void Action<T>::run() const
{
	callback();
}

template class Action<void()>;
