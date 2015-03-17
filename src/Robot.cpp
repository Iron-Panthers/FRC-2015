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
#include "Shifter.hpp"
#include "ToteLifter.hpp"


class Robot: public IterativeRobot
{
private:
	EventRelay relay;
	ToteLifter lifter;
	Shifter shifter;
public:
	Robot() : shifter(0, 1)
	{
	}

	void RobotInit()
	{
		JoyButton button9(true, false, false, ButtonNames::Button9);
		std::function<void()> callbackManualUp(std::bind(&ToteLifter::manualUp, &lifter));
		Action<void()> actionManualUp(callbackManualUp, 0);
		relay.getMapJoy().associate(button9, actionManualUp);

		JoyButton button11(true, false, false, ButtonNames::Button11);
		std::function<void()> callbackManualStop(std::bind(&ToteLifter::manualStop, &lifter));
		Action<void()> actionManualStop(callbackManualStop, 0);
		relay.getMapJoy().associate(button11, actionManualStop);

		JoyButton button10(true, false, false, ButtonNames::Button10);
		std::function<void()> callbackManualDown(std::bind(&ToteLifter::manualDown, &lifter));
		Action<void()> actionManualDown(callbackManualDown, 0);
		relay.getMapJoy().associate(button10, actionManualDown);

		JoyButton button(true, false, false, ButtonNames::Button7);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> actionB(callbackShiftLow, 0);
		relay.getMapJoy().associate(button, actionB);

		JoyButton buttonHigh(true, false, false, ButtonNames::Button8);
		std::function<void()> callbackShiftHigh(std::bind(&Shifter::shiftHigh, &shifter));
		Action<void()> actionHigh(callbackShiftHigh, 0);
		relay.getMapJoy().associate(buttonHigh, actionHigh);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
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

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
