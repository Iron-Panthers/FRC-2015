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
	auto *joyExtreme = joyWrap.getJoystick();
	auto *gcn = gamecube.getJoystick();

	double driveAxis = joyExtreme->GetRawAxis(1);
	double twistAxis = joyExtreme->GetRawAxis(2);

	driveAxis = std::abs(driveAxis) > 0.1 ? driveAxis : 0;
	twistAxis = std::abs(twistAxis) > 0.1 ? twistAxis : 0;

	std::cout << gcn->GetRawAxis(1) << "\t\t" << gcn->GetRawAxis(0) << std::endl;

	const double MA_LENGTH = 25;
	movingAverageDrive.push_front(driveAxis);
	movingAverageTwist.push_front(twistAxis);
	if (movingAverageDrive.size() > MA_LENGTH) movingAverageDrive.pop_back();
	if (movingAverageTwist.size() > MA_LENGTH) movingAverageTwist.pop_back();

	computedMADrive = 0;
	computedMATwist = 0;
	for (auto e : movingAverageDrive) { computedMADrive += e; }
	for (auto e : movingAverageTwist) { computedMATwist += e; }
	computedMADrive /= MA_LENGTH;
	computedMATwist /= MA_LENGTH;

	driveAxis = computedMADrive;
	twistAxis = computedMATwist;

	if (std::abs(gcn->GetRawAxis(1)) > 0.25 || std::abs(gcn->GetRawAxis(0)) > 0.25)
	{
		driveRobot.ArcadeDrive(gcn->GetRawAxis(1) * 0.5, gcn->GetRawAxis(0) * 0.5);
	}
	else
	{
		driveRobot.ArcadeDrive(driveAxis, twistAxis * 0.75);
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
