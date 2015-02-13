#include <WPILib.h>
#include "EventRelay.hpp"
#include "Autonomous.hpp"
#include "Action.hpp"
#include "JoyButton.hpp"
#include "DriveAuto.hpp"
#include "JoystickWrapper.hpp"
#include "RobotLocation.hpp"
#include "TwoMotorGroup.hpp"
//#include "Vision.hpp"
#include "ActionMap.hpp"
#include "Shifter.hpp"


class Robot: public IterativeRobot
{

private:
	EventRelay relay;
	//Autonomous auton;
	//Shifter shifter;
	//Vision vision;

public:
	Robot()
	{
		RobotLocation::get(); //construct the gyro
	}

	void RobotInit()
	{
		/*JoyButton triggerButton(true, false, false, ButtonNames::Trigger);
		std::function<void()> callback(std::bind(&Shifter::shiftHigh, &shifter));
		Action<void()> action(callback, 0);
		relay.getMap().associate(triggerButton, action);

		JoyButton button(true, false, false, ButtonNames::Button9);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> actionB(callbackShiftLow, 0);
		relay.getMap().associate(button, actionB);*/
	}

	void AutonomousInit()
	{
		//talons = new Talon(2);
		//talond = new Talon(3);
		DriveAuto::get()->move(30, 0.2);
	}

	void AutonomousPeriodic()
	{
		//talons->Set(.5);
		//talond->Set(.5);
		DriveAuto::get()->update();
		//vision.distanceToBox();
		std::cout << "Left: " << RobotLocation::get()->getLeftEncoder()->GetDistance() << std::endl;
		std::cout << "Right: " << RobotLocation::get()->getRightEncoder()->GetDistance() << std::endl;
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		//std::cout << input->Get();
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
