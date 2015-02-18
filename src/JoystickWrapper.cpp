#include "JoystickWrapper.hpp"

//for GetRawNumber() down is true

bool JoystickWrapper::checkDown(JoyButton joyButton, ButtonNames butt, Joystick* joy)
{
	if(!joyButton.down && !joyButton.pressed && joy->GetRawButton(butt))
		return true;
	else
		return false;
}

bool JoystickWrapper::checkUp(JoyButton joyButton, ButtonNames butt, Joystick* joy)
{
	if((joyButton.down || joyButton.pressed) && !joyButton.up && !joy->GetRawButton(butt))
		return true;
	else
		return false;
}

bool JoystickWrapper::checkPressed(JoyButton joyButton, ButtonNames butt, Joystick* joy)
{
	if((joyButton.down || joyButton.pressed) && !joyButton.up && joy->GetRawButton(butt))
		return true;
	else
		return false;
}


void JoystickWrapper::pollJoystick()
{
	for (int i = 0; i < joyButtons.size(); i++)
	{
		if(checkUp(joyButtons[i], static_cast<ButtonNames>(i + 1), &joystick))
		{
			joyButtons[i].up = true;
		}
		else
		{
			joyButtons[i].up = false;
		}
		if(checkPressed(joyButtons[i], static_cast<ButtonNames>(i + 1), &joystick))
		{
			joyButtons[i].pressed = true;
		}
		else
		{
			joyButtons[i].pressed = false;
		}
		if(checkDown(joyButtons[i], static_cast<ButtonNames>(i + 1), &joystick))
		{
			joyButtons[i].down = true;
		}
		else
		{
			joyButtons[i].down = false;
		}

		if(checkUp(buttonJoy[i], static_cast<ButtonNames>(i + 1), &gameCube))
		{
			buttonJoy[i].up = true;
		}
		else
		{
			buttonJoy[i].up = false;
		}
		if(checkPressed(buttonJoy[i], static_cast<ButtonNames>(i + 1), &gameCube))
		{
			buttonJoy[i].pressed = true;
		}
		else
		{
			buttonJoy[i].pressed = false;
		}
		if(checkDown(buttonJoy[i], static_cast<ButtonNames>(i + 1), &gameCube))
		{
			buttonJoy[i].down = true;
		}
		else
		{
			buttonJoy[i].down = false;
		}
	}
}

const std::array<JoyButton, 12>& JoystickWrapper::getStates()
{
	if (joystick.GetRawButton(1))
		std::cout << std::endl << std::endl << "sdf" << std::endl;
	if (gameCube.GetRawButton(1))
		std::cout << std::endl << std::endl << "gcn" << std::endl;
	return joyButtons;
}

JoystickWrapper::JoystickWrapper()
	: joystick(0)
	, gameCube(1)
	, joyButtons() //Where joystick is plugged in
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

Joystick* JoystickWrapper::getGameCube()
{
	return &gameCube;
}
