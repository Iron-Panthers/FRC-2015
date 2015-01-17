#ifndef JOYSTICK_WRAPPER_HPP
#define JOYSTICK_WRAPPER_HPP

#include <WPILib.h>
#include <iostream>
#include <array>
#include "JoyButton.hpp"

class JoystickWrapper
{
public:
	void pollJoystick();
	const std::array<JoyButton, 12>& getStates();
	JoystickWrapper();

private:
	Joystick joystick;
	std::array<JoyButton, 12> joyButtons;
};

#endif
