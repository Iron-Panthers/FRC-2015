#include <WPILib.h>
#include "EventRelay.hpp"
#include "Autonomous.hpp"
#include "Action.hpp"
#include "JoyButton.hpp"
#include "DriveAuto.hpp"
#include "JoystickWrapper.hpp"
#include "RobotLocation.hpp"
#include "TwoMotorGroup.hpp"
#include "Vision.hpp"
#include "ActionMap.hpp"


class Robot: public IterativeRobot
{
	DoubleSolenoid *one;
	Talon *talon;

private:
	EventRelay relay;
	Autonomous auton;
	DriveAuto autoDrive;
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
		autoDrive.move(52, .5);
		autoDrive.axisTurn(360);

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
