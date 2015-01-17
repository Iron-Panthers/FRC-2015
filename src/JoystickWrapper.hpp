#ifndef JOYSTICKWRAPPER_HPP
#define JOYSTICKWRAPPER_HPP

#include <WPILib.h>
#include <iostream>
#include <array>

class JoystickWrapper
{
public:
	void pollJoystick();
	const std::array<Button>& getStates();
	JoystickWrapper();

private:
	Joystick joystick;
	std::array<Button> joyButtons;
};

#endif
