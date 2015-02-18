#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <WPILib.h>
#include <iostream>

enum ButtonNames
{
	Trigger = 1,
	SideButton, //2
	BottomLeft, //3
	BottomRight, //4
	TopLeft, //5
	TopRight, //6
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
	ButtonNames name;
	inline bool operator==(const JoyButton& right);
	bool operator<(const JoyButton& right) const;
	JoyButton();
	JoyButton(const JoyButton& button);
	JoyButton(ButtonNames name);
	JoyButton(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name);

};

#endif
