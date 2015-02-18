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
	std::array<JoyButton, 12> buttonJoy;
	bool checkDown(JoyButton joyButton, ButtonNames butt, Joystick* joy);
	bool checkUp(JoyButton joyButton, ButtonNames butt, Joystick* joy);
	bool checkPressed(JoyButton joyButton, ButtonNames butt, Joystick* joy);
};

#endif
