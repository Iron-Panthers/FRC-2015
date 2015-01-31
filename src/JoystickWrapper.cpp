#include "JoystickWrapper.hpp"

//for GetRawNumber() down is true

bool JoystickWrapper::checkDown(JoyButton joyButton, ButtonNames butt)
{
	if(!joyButton.down && !joyButton.pressed && joystick.GetRawButton(butt))
		return true;
	else
		return false;
}

bool JoystickWrapper::checkUp(JoyButton joyButton, ButtonNames butt)
{
	if((joyButton.down || joyButton.pressed) && !joyButton.up && !joystick.GetRawButton(butt))
		return true;
	else
		return false;
}

bool JoystickWrapper::checkPressed(JoyButton joyButton, ButtonNames butt)
{
	if((joyButton.down || joyButton.pressed) && !joyButton.up && !joystick.GetRawButton(butt))
		return true;
	else
		return false;
}

void JoystickWrapper::pollJoystick()
{
	std::cout << "pollJoystick" << std::endl;
	for (int i = 1; i <= joyButtons.size(); i++)
	{
		if(checkDown(joyButtons[i], static_cast<ButtonNames>(i)))
		{
			joyButtons[i].down = true;
		}
		if(checkUp(joyButtons[i], static_cast<ButtonNames>(i)))
		{
			joyButtons[i].up = true;
		}
		if(checkPressed(joyButtons[i], static_cast<ButtonNames>(i)))
		{
			joyButtons[i].pressed = true;
		}

	}
}

const std::array<JoyButton, 12>& JoystickWrapper::getStates()
{
	std::cout << "getStates" << std::endl;
	return joyButtons;
}

JoystickWrapper::JoystickWrapper() : joystick(0), joyButtons()
{
	std::cout << "getStates" << std::endl;
}
