#include "EventRelay.hpp"
#include "ActionMap.hpp"
#include "DriveAuto.hpp"

EventRelay::EventRelay()
	: actionMapJoy()
	, actionMapGCN()
	, joyWrap(0)
	, gamecube(1)
	, movingAverageDrive(25)
	, movingAverageTwist(25)
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

	zeroMotorTimer.Start();

	driveRobot.SetSafetyEnabled(false);
}

void EventRelay::checkStates()
{
	auto *joyExtreme = joyWrap.getJoystick();
	auto *gcn = gamecube.getJoystick();

	double driveAxis = joyExtreme->GetRawAxis(1);
	double twistAxis = joyExtreme->GetRawAxis(2);

	driveAxis = std::abs(driveAxis) > 0.1 ? driveAxis : 0;
	twistAxis = std::abs(twistAxis) > 0.1 ? twistAxis : 0;

	//std::cout << gcn->GetRawAxis(1) << "\t\t" << gcn->GetRawAxis(0) << std::endl;

	movingAverageDrive.giveRawValue(driveAxis);
	movingAverageTwist.giveRawValue(twistAxis);

	driveAxis = movingAverageDrive.computeAverage();
	twistAxis = movingAverageTwist.computeAverage();

	float turnAxisGCN = onlyFB_GCN ? 0 : gcn->GetRawAxis(0);
	onlyFB_GCN = false;

	//std::cout << "drive" << driveAxis << " twist" << twistAxis << std::endl;

	if (zeroMotorTimer.Get() < 5)
	{
		DriveAuto::get()->getLeftMotors()->Set(0);
		DriveAuto::get()->getRightMotors()->Set(0);
	}
	else
	{
		if (std::abs(gcn->GetRawAxis(1)) > 0.25 || std::abs(turnAxisGCN) > 0.25)
		{
			driveRobot.ArcadeDrive(gcn->GetRawAxis(1) * 0.8, turnAxisGCN * .82);
		}
		else
		{
			driveRobot.ArcadeDrive(driveAxis * 1, twistAxis * 1);
		}

	}

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

void EventRelay::setFBGCN()
{
	onlyFB_GCN = true;
}

void EventRelay::zeroMotors()
{
	zeroMotorTimer.Reset();
}
