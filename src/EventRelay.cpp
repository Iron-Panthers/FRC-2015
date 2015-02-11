#include "EventRelay.hpp"
#include "ActionMap.hpp"

EventRelay::EventRelay()
	: actionMap()
	, joyWrap()
{
	std::cout << "Yeeeee... That Event Relay online" << std::endl;
	DriveAuto::get();
	RobotDrive driveRobot(DriveAuto::get()->getLeftMotors(), DriveAuto::get()->getRightMotors());
}

void EventRelay::checkStates()
{
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
