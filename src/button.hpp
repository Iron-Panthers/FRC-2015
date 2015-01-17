#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <WPILib.h>
#include <iostream>

class Button
{
public:
	bool down;
	bool pressed;
	bool up;
	inline bool operator==(const Button& left, const Button& right);
	Button(ButtonNames name);
	Button(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name);

private:
	ButtonNames name;

};

#endif
