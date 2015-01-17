#include "JoystickWrapper.hpp"

//for getRawNumber() down is true

void JoystickWrapper::pollJoystick()
{
	std::cout << "pollJoystick" << std::endl;
	for (int i = 0; i < joyButtons.size(); i++)
	{
		JoyButton &prev = joyButtons[i];
		if (!prev.down && !prev.pressed && !prev.up && joystick.GetRawButton(i))
			prev.down = true;
		if (!prev.down)
		JoyButton button;
		button.down;

	}
}

const std::array<JoyButton, 12>& JoystickWrapper::getStates()
{
	std::cout << "getStates" << std::endl;
}

JoystickWrapper::JoystickWrapper()
{
	std::cout << "getStates" << std::endl;
}
/*
 * pollButton()
 * -if down and up and pressed = false, = true etc
 * -returns if down is true or false
 */
