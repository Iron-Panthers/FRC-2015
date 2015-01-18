#include <WPILib.h>
#include "EventRelay.hpp"

class Robot: public IterativeRobot
{
	DoubleSolenoid *one;
	Talon *talon;
public:
	Robot() : one(new DoubleSolenoid(0, 1)), talon(new Talon(1)) {}

private:


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

	void TestPeriodic()
	{
	}
};

START_ROBOT_CLASS(Robot);
