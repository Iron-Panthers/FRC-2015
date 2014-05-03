#include <JoyButton.hpp>

JoyButton::JoyButton()
	: name()
{
	down = false;
	pressed = false;
	up = false;
}

JoyButton::JoyButton(ButtonNames name)
	: name(name)
{
	std::cout << "Button #2" << std::endl;
}

JoyButton::JoyButton(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name)
	: down(wouldBeDown)
	, pressed(wouldBePressed)
	, up(wouldBeUp)
	, name(name)
{
	std::cout << "Button #1" << std::endl;
}

inline bool JoyButton::operator==(const JoyButton& right)
{
	if ((down == right.down) && (pressed == right.pressed) && (up == right.up) && (name == right.name))
		return true;
	else
		return false;
	std::cout << "Operator== JoyButton" << std::endl;
}
