#include "EventRelay.hpp"
#include "ActionMap.hpp"
#include "DriveAuto.hpp"

EventRelay::EventRelay()
	: actionMapJoy()
	, actionMapGCN()
	, joyWrap(0)
	, gamecube(1)
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

	driveRobot.SetSafetyEnabled(false);
}

void EventRelay::checkStates()
{
	driveRobot.ArcadeDrive(joyWrap.getJoystick(), 1, joyWrap.getJoystick(), 2);

	joyWrap.pollJoystick();
	gamecube.pollJoystick();

	std::array<JoyButton, 12> buttonStatesJoy = joyWrap.getStates();
	std::array<JoyButton, 12> buttonStatesGCN = gamecube.getStates();

	for(unsigned int i = 0; i < buttonStatesJoy.size(); i++)
	{
		if (buttonStatesJoy[i].down || buttonStatesJoy[i].pressed || buttonStatesJoy[i].up)
		{
			actionMapJoy.eventOccurredFor(buttonStatesJoy[i]);
		}
	}

	for(unsigned int i = 0; i < buttonStatesGCN.size(); i++)
	{
		if (buttonStatesGCN[i].down || buttonStatesGCN[i].pressed || buttonStatesGCN[i].up)
		{
			actionMapGCN.eventOccurredFor(buttonStatesGCN[i]);
		}
	}
}


ActionMap& EventRelay::getMapJoy()
{
	return actionMapJoy;
}

ActionMap& EventRelay::getMapGCN()
{
	return actionMapGCN;
}
