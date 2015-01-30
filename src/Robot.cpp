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
	EventRelay relay;
	//Autonomous auton;
	DriveAuto autoDrive;
	Shifter shifter;
	void mapJoystick()
	{

	}

public:
	Robot() {}

	void RobotInit()
	{
		JoyButton triggerButton(ButtonNames::Trigger);
		std::function<void()> callback(std::bind(&Shifter::shiftHigh, &shifter));
		Action<void()> action(callback, 0);
		relay.getMap().associate(triggerButton, action);
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
		relay.checkStates();
	}

	void DisabledInit()
	{
		JoyButton button(ButtonNames::Button9);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> action(callbackShiftLow, 0);
		EventRelay relay;
		relay.getMap().associate(button, action);
	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
