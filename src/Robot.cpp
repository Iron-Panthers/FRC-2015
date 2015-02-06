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


class Robot: public IterativeRobot
{

private:
	EventRelay relay;
	//Autonomous auton;
	//DriveAuto autoDrive;

	Shifter shifter;
	DigitalInput* input;
	int x;
	//Talon *talons;
	//Talon *talond;
	/*void mapJoystick()
	{

	}*/

public:
	Robot() : shifter(0, 1), input(new DigitalInput(2))
	{
		RobotLocation::get(); //construct the gyro
	}

	void RobotInit()
	{
		JoyButton triggerButton(true, false, false, ButtonNames::Trigger);
		std::function<void()> callback(std::bind(&Shifter::shiftHigh, &shifter));
		Action<void()> action(callback, 0);
		relay.getMap().associate(triggerButton, action);

		JoyButton button(true, false, false, ButtonNames::Button9);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> actionB(callbackShiftLow, 0);
		relay.getMap().associate(button, actionB);



	}

	void AutonomousInit()
	{
		//autoDrive.move(52, .5);
		//talons = new Talon(0);
		//talond = new Talon(1);
		DriveAuto::get()->move(700, .7);
		DriveAuto::get()->move(100, 0.1);
		DriveAuto::get()->move(1000, 1);
	}

	void AutonomousPeriodic()
	{
	//autoDrive.update();
		//talons->Set(.5);
		//talond->Set(.5);
		DriveAuto::get()->update();
	}

	void TeleopInit()
	{
	}

	void TeleopPeriodic()
	{
		std::cout << input->Get();
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
