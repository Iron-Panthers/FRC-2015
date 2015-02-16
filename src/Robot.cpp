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
	//EventRelay relay;
	//Autonomous auton;
	//Shifter shifter;
	//Vision vision;
	//Talon *one, *two, *three, *four;
	//ToteLifter lifter;
public:
	Robot() //: one(new Talon(0)), two(new Talon(1)), three(new Talon(2)), four(new Talon(3))
	{
		//RobotLocation::get(); //construct the gyro
	}

	void RobotInit()
	{
		//JoyButton triggerButton(true, false, false, ButtonNames::Trigger);
		//std::function<void()> callback(std::bind(&ToteLifter::setToteLevel1, &lifter));
		//std::cout << "crash 3" << std::endl;
		//Action<void()> action(callback, 0);
		//std::cout << "crash 2" << std::endl;
		//relay.getMap().associate(triggerButton, action);

		//std::cout << "crash 1" << std::endl;
		//JoyButton sideButton(true, false, false, ButtonNames::SideButton);
		//std::function<void()> callback2(std::bind(&ToteLifter::setToteLevel2, &lifter));
		//Action<void()> action2(callback2, 0);
		//relay.getMap().associate(sideButton, action2);

		//JoyButton threeButton(true, false, false, ButtonNames::BottomLeft);
		//std::function<void()> callback3(std::bind(&ToteLifter::setToteLevel3, &lifter));
		//Action<void()> action3(callback3, 0);
		//relay.getMap().associate(threeButton, action3);

		/*
		JoyButton button(true, false, false, ButtonNames::Button9);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> actionB(callbackShiftLow, 0);
		relay.getMap().associate(button, actionB);
		*/
	}

	void AutonomousInit()
	{
		//talon1 = new Talon(0);
		//talon2 = new Talon(1);
		//talon3 = new Talon(2);
		//talon4 = new Talon(3);
		DriveAuto::get()->move(30, 0.2);
		DriveAuto::get()->axisTurn(90);
	}

	void AutonomousPeriodic()
	{
		//one->Set(.1);
		//two->Set(.1);
		//three->Set(-.1);
		//four->Set(-.1);
		DriveAuto::get()->update();
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
		//relay.checkStates();
		/*one->Set(0.3);
		two->Set(0.3);
		three->Set(0.3);
		four->Set(0.3);
		std::cout << "Left: " << RobotLocation::get()->getLeftEncoder()->GetDistance() << std::endl;
		std::cout << "Right: " << RobotLocation::get()->getRightEncoder()->GetDistance() << std::endl;*/
		//relay.checkStates();
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
