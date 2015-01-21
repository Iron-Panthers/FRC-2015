#include "../src/JoystickWrapper.hpp"

//for getRawNumber() down is true

bool JoystickWrapper::checkDown(JoyButton joyButton)
{
	if(joyButton.down == true && joyButton.pressed == false && joyButton.up == false && joystick.GetRawButton())
		return true;
}

bool JoystickWrapper::checkUp()
{

}

bool JoystickWrapper::checkPressed()
{

}

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
	return joyButtons;
}

JoystickWrapper::JoystickWrapper() : joystick(0), joyButtons()
{
	std::cout << "getStates" << std::endl;
}
