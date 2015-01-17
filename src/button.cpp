#include "Button.hpp"

enum ButtonNames
{
	Trigger,
	SideButton,
	BottomLeft,
	BottomRight,
	TopLeft,
	TopRight,
	Button7,
	Button8,
	Button9,
	Button10,
	Button11,
	Button12
};

Button::Button(ButtonNames name)
{
	std::cout << "Button #2" << std::endl;
}

Button::Button(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name)
{
	std::cout << "Button #1" << std::endl;
}
