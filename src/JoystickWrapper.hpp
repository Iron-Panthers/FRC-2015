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
	Joystick* getJoystick();
	Joystick* getGameCube();

private:
	Joystick joystick;
	Joystick gameCube;
	std::array<JoyButton, 12> joyButtons;
	bool checkDown(JoyButton joyButton, ButtonNames butt);
	bool checkUp(JoyButton joyButton, ButtonNames butt);
	bool checkPressed(JoyButton joyButton, ButtonNames butt);
};

#endif
