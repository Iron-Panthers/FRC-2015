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

private:
	//EventRelay relay;
	//Autonomous auton;
	DriveAuto autoDrive;
	void mapJoystick()
	{

	}

public:
	Robot() {}

	void RobotInit()
	{
		//EventRelay relay;
	}

	void AutonomousInit()
	{
		autoDrive.move(52, .5);
	}

	void AutonomousPeriodic()
	{
		autoDrive.update();
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
