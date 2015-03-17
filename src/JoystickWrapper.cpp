#include "JoystickWrapper.hpp"

//for GetRawNumber() down is true

bool JoystickWrapper::checkDown(JoyButton joyButton, ButtonNames butt)
{
	if(!joyButton.down && !joyButton.pressed && joystick->GetRawButton(butt))
		return true;
	else
		return false;
}

bool JoystickWrapper::checkUp(JoyButton joyButton, ButtonNames butt)
{
	if((joyButton.down || joyButton.pressed) && !joyButton.up && !joystick->GetRawButton(butt))
		return true;
	else
		return false;
}

bool JoystickWrapper::checkPressed(JoyButton joyButton, ButtonNames butt)
{
	if((joyButton.down || joyButton.pressed) && !joyButton.up && joystick->GetRawButton(butt))
		return true;
	else
		return false;
}


void JoystickWrapper::pollJoystick()
{
	for (unsigned int i = 0; i < joyButtons.size(); i++)
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
	return joyButtons;
}

JoystickWrapper::JoystickWrapper(int port)
	: joystick(new Joystick(port))
	, joyButtons()
{
	for(unsigned int i = 0; i < joyButtons.size(); i++)
	{
		joyButtons[i].name = static_cast<ButtonNames>(i + 1);
	}
}

Joystick* JoystickWrapper::getJoystick()
{
	return joystick;
}

JoystickWrapper::~JoystickWrapper()
{
	delete joystick;
}
