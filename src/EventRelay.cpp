#include "EventRelay.hpp"
#include "ActionMap.hpp"
#include "DriveAuto.hpp"

EventRelay::EventRelay()
	: actionMap()
	, joyWrap()
	, driveRobot(DriveAuto::get()->getLeftMotors()->getTalonOne().get()
			   , DriveAuto::get()->getLeftMotors()->getTalonTwo().get()
			   , DriveAuto::get()->getRightMotors()->getTalonOne().get()
			   , DriveAuto::get()->getRightMotors()->getTalonTwo().get())
{
	std::cout << "Yeeeee... That Event Relay online" << std::endl;
}

void EventRelay::checkStates()
{
	driveRobot.ArcadeDrive(joyWrap.getJoystick());

	joyWrap.pollJoystick();
	std::array<JoyButton, 12> buttonStates = joyWrap.getStates();
	auto button = buttonStates[0];

	std::cout << button.down << button.pressed << button.up << std::endl;

	for(unsigned int i = 0; i < buttonStates.size(); i++)
	{
		if (buttonStates[i].down || buttonStates[i].pressed || buttonStates[i].up)
		{
			actionMap.eventOccurredFor(buttonStates[i]);
		}
	}
}


ActionMap& EventRelay::getMap()
{
	std::cout << "Got that map... You \'na\' me?" << std::endl;
	return actionMap;
}
