#include "JoystickWrapper.hpp"

//for getRawNumber() down is true

void JoystickWrapper::pollJoystick()
{
	std::cout << "pollJoystick" << std::endl;
	for (int i = 0; i < joyButtons.size(); i++)
	{
	}
}

const std::array<JoyButton, 12>& JoystickWrapper::getStates()
{
	std::cout << "getStates" << std::endl;
}

JoystickWrapper::JoystickWrapper() : joystick(0), joyButtons()
{
	std::cout << "getStates" << std::endl;
}
/*
 * pollButton()
 * -if down and up and pressed = false, = true etc
 * -returns if down is true or false
 */
