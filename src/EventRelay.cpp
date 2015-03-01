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
	driveRobot.SetInvertedMotor(static_cast<RobotDrive::MotorType>(0), false);
	driveRobot.SetInvertedMotor(static_cast<RobotDrive::MotorType>(1), false);
	driveRobot.SetInvertedMotor(static_cast<RobotDrive::MotorType>(2), false);
	driveRobot.SetInvertedMotor(static_cast<RobotDrive::MotorType>(3), false);
	//0 3
	//0 2
	driveRobot.SetSafetyEnabled(false);
	std::cout << "Event Relay done" <<std::endl;
}

void EventRelay::checkStates()
{
	driveRobot.ArcadeDrive(joyWrap.getJoystick(), 2);

	joyWrap.pollJoystick();
	std::cout << joyWrap.getJoystick()->GetRawAxis(2) << std::endl;
	std::array<JoyButton, 12> buttonStates = joyWrap.getStates();
	auto button = buttonStates[0];

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
