#include <WPILib.h>
#include "EventRelay.hpp"
#include "Autonomous.hpp"
#include "Action.hpp"
#include "JoyButton.hpp"
#include "DriveAuto.hpp"
#include "JoystickWrapper.hpp"
#include "RobotLocation.hpp"
#include "TwoMotorGroup.hpp"
#include "VisionClass.hpp"
#include "ActionMap.hpp"


class Robot: public IterativeRobot
{
	DoubleSolenoid *one;
	Talon *talon;

private:
	EventRelay relay;
	Autonomous auton;
	void mapJoystick()
	{

	}

public:
	Robot() : one(new DoubleSolenoid(0, 1)), talon(new Talon(1)) {}

	void RobotInit()
	{
		//EventRelay relay;
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
		talon->Set(0.4);
		one->Set(DoubleSolenoid::kForward);
		Wait(10);
		one->Set(DoubleSolenoid::kReverse);
		Wait(10);
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{

	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
