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
	//Autonomous auton;
	Shifter shifter;
	//Vision vision;
	Talon *one, *two, *three, *four;
	ToteLifter lifter;
public:
	Robot() : shifter(0, 1)
	{
		//RobotLocation::get(); //construct the gyro
	}

	void RobotInit()
	{
		JoyButton triggerButton(true, false, false, ButtonNames::Trigger);
		std::function<void()> callback(std::bind(&ToteLifter::setToteLevel1, &lifter));
		Action<void()> action(callback, 0);
		relay.getMap().associate(triggerButton, action);

		JoyButton sideButton(true, false, false, ButtonNames::SideButton);
		std::function<void()> callback2(std::bind(&ToteLifter::setToteLevel2, &lifter));
		Action<void()> action2(callback2, 0);
		relay.getMap().associate(sideButton, action2);

		JoyButton threeButton(true, false, false, ButtonNames::BottomLeft);
		std::function<void()> callback3(std::bind(&ToteLifter::setToteLevel3, &lifter));
		Action<void()> action3(callback3, 0);
		relay.getMap().associate(threeButton, action3);

		JoyButton bottomRight(true, false, false, ButtonNames::BottomRight);
		std::function<void()> callback4(std::bind(&ToteLifter::setToteLevel4, &lifter));
		Action<void()> action4(callback4, 0);
		relay.getMap().associate(bottomRight, action4);

		JoyButton button9(true, false, false, ButtonNames::Button9);
		std::function<void()> callbackManualUp(std::bind(&ToteLifter::manualUp, &lifter));
		Action<void()> actionManualUp(callbackManualUp, 0);
		relay.getMap().associate(button9, actionManualUp);

		JoyButton button11(true, false, false, ButtonNames::Button11);
		std::function<void()> callbackManualStop(std::bind(&ToteLifter::manualStop, &lifter));
		Action<void()> actionManualStop(callbackManualStop, 0);
		relay.getMap().associate(button11, actionManualStop);

		JoyButton button10(true, false, false, ButtonNames::Button10);
		std::function<void()> callbackManualDown(std::bind(&ToteLifter::manualDown, &lifter));
		Action<void()> actionManualDown(callbackManualDown, 0);
		relay.getMap().associate(button10, actionManualDown);

		JoyButton button12(true, false, false, ButtonNames::Button12);
		std::function<void()> callbackResumeAuto(std::bind(&ToteLifter::resumeAuto, &lifter));
		Action<void()> actionResumeAuto(callbackResumeAuto, 0);
		relay.getMap().associate(button12, actionResumeAuto);

		JoyButton button(true, false, false, ButtonNames::Button7);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> actionB(callbackShiftLow, 0);
		relay.getMap().associate(button, actionB);

		JoyButton buttonHigh(true, false, false, ButtonNames::Button8);
		std::function<void()> callbackShiftHigh(std::bind(&Shifter::shiftHigh, &shifter));
		Action<void()> actionHigh(callbackShiftHigh, 0);
		relay.getMap().associate(buttonHigh, actionHigh);



	}

	void AutonomousInit()
	{
		//talon1 = new Talon(0);
		//talon2 = new Talon(1);
		//talon3 = new Talon(2);
		//talon4 = new Talon(3);
		//std::cout << "test" << std::endl;
		//DriveAuto::get()->move(90, 0.5);
		//DriveAuto::get()->axisTurn(90);
		//DriveAuto::get()->move(50, 0.1);
	}

	void AutonomousPeriodic()
	{
		//one->Set(.1);
		//two->Set(.1);
		//three->Set(-.1);
		//four->Set(-.1);
		//DriveAuto::get()->update();
		//vision.distanceToBox();
		//std::cout << "Left: " << RobotLocation::get()->getLeftEncoder()->GetRate() << std::endl;
		//std::cout << "Right: " << RobotLocation::get()->getRightEncoder()->GetDistance() << std::endl;

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		//std::cout << input->Get();
		relay.checkStates();
		lifter.update();
		/*one->Set(0.3);
		two->Set(0.3);
		three->Set(0.3);
		four->Set(0.3);
		std::cout << "Left: " << RobotLocation::get()->getLeftEncoder()->GetDistance() << std::endl;
		std::cout << "Right: " << RobotLocation::get()->getRightEncoder()->GetDistance() << std::endl;*/
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
