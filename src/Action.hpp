#ifndef ACTION_HPP
#define ACTION_HPP

#include <functional>

template <typename T>
class Action
{
public:
	const int cost;
	Action(std::function<T> func, int cost);
	{
		std::bind;

	}
	void run() const;
private:
	const std::function<T> callback;
};

#endif
