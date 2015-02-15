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
	if((joyButton.down || joyButton.pressed) && !joyButton.up && joystick.GetRawButton(butt))
		return true;
	else
		return false;
}

void JoystickWrapper::pollJoystick()
{
	for (int i = 0; i < joyButtons.size(); i++)
	{
		if(checkUp(joyButtons[i], static_cast<ButtonNames>(i + 1)))
		{
			joyButtons[i].up = true;
		}
		else
		{
			joyButtons[i].up = false;
		}
		if(checkPressed(joyButtons[i], static_cast<ButtonNames>(i + 1)))
		{
			joyButtons[i].pressed = true;
		}
		else
		{
			joyButtons[i].pressed = false;
		}
		if(checkDown(joyButtons[i], static_cast<ButtonNames>(i + 1)))
		{
			joyButtons[i].down = true;
		}
		else
		{
			joyButtons[i].down = false;
		}
	}
}

const std::array<JoyButton, 12>& JoystickWrapper::getStates()
{
	if (joystick.GetRawButton(1))
		std::cout << std::endl << std::endl << "sdf" << std::endl;
	return joyButtons;
}

JoystickWrapper::JoystickWrapper() : joystick(0) , joyButtons() //Where joystick is plugged in
{
	for(int i = 0; i < joyButtons.size(); i++)
	{
		joyButtons[i].name = static_cast<ButtonNames>(i + 1);
	}
}

Joystick* JoystickWrapper::getJoystick()
{
	return &joystick;
}
