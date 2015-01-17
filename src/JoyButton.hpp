#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <WPILib.h>
#include <iostream>

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

class JoyButton
{
public:
	bool down;
	bool pressed;
	bool up;
	inline bool operator==(const JoyButton& right);
	JoyButton(ButtonNames name);
	JoyButton(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name);

private:
	ButtonNames name;
};

#endif
