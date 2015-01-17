#ifndef JOYSTICK_WRAPPER_HPP
#define JOYSTICK_WRAPPER_HPP

#include <WPILib.h>
#include <iostream>
#include <array>
#include "Button.hpp"

class JoystickWrapper
{
public:
	void pollJoystick();
	const std::array<Button, 12>& getStates();
	JoystickWrapper();

private:
	Joystick joystick;
	std::array<Button, 12> joyButtons;
};

#endif
