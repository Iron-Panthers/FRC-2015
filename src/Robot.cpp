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
#include "JoyTest.hpp"
#include "ContainerLifter.hpp"

void createButtonMapping(bool down, bool pressed, bool up,
						 ButtonNames buttonName,
						 std::function<void()> callback,
						 ActionMap &map)
{
	JoyButton button(down, pressed, up, buttonName);
	Action<void()> action(callback, 0);
	map.associate(button, action);
}

class Robot : public IterativeRobot
	//: Lidar(new LidarI2C(0x62f))
{
private:
	EventRelay relay;
	ToteLifter lifter;
	Shifter shifter;
	JoyTest joyTest;
	//LidarI2C *Lidar;
	ContainerLifter cLifter;
	Timer timer;

public:
	Robot() : shifter(0, 1), cLifter(2, 3)
	{

	}

	void RobotInit()
	{
		auto &joyMap = relay.getMapJoy();
		auto &gcnMap = relay.getMapGCN();

		createButtonMapping(true, false, false
				          , ButtonNames::BottomRight
						  , std::bind(&ToteLifter::manualDown, &lifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::TopRight
						  , std::bind(&ToteLifter::manualUp, &lifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button7
						  , std::bind(&Shifter::shiftLow, &shifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button8
						  , std::bind(&Shifter::shiftHigh, &shifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button11
						  , std::bind(&ContainerLifter::extendPiston, &cLifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button12
						  , std::bind(&ContainerLifter::retractPiston, &cLifter)
						  , joyMap);

		//y
		createButtonMapping(false, true, false
						  , ButtonNames::BottomRight
						  , std::bind(&ToteLifter::manualUp, &lifter)
						  , gcnMap);

		//b
		createButtonMapping(false, true, false
					      , ButtonNames::SideButton
					      , std::bind(&ToteLifter::manualDown, &lifter)
						  , gcnMap);
		//down
		createButtonMapping(true, false, false
					      , ButtonNames::Button10
						  , std::bind(&DriveAuto::panic, DriveAuto::get())
						  , gcnMap);

		//a
		createButtonMapping(true, false, false
						  , ButtonNames::Trigger
						  , std::bind(&ContainerLifter::extendPiston, &cLifter)
						  , gcnMap);

		//x
		createButtonMapping(true, false, false
						  , ButtonNames::BottomLeft
						  , std::bind(&ContainerLifter::retractPiston, &cLifter)
						  , gcnMap);

		//up
		createButtonMapping(true, false, false
						, ButtonNames::Button9
						, std::bind(&ToteLifter::limitOverride, &lifter)
						, gcnMap);

		//start
		createButtonMapping(true, false, false
						, ButtonNames::Button8
						, std::bind(&EventRelay::setFBGCN, &relay)
						, gcnMap);

		//z
		createButtonMapping(true, false, false
						, ButtonNames::TopLeft
						, std::bind(&EventRelay::zeroMotors, &relay)
						, gcnMap);
	}

	void AutonomousInit()
	{
		/*
		DriveAuto::get()->move(72, 0.5);
		Timer timer;
		timer.Start();
		while (timer.Get() < 3.00)
			lifter.moveUp();
		Wait(2);
		DriveAuto::get()->axisTurn(90);
		DriveAuto::get()->wait(1);
		DriveAuto::get()->move(100, 0.75);
		*/
		shifter.shiftLow();
		//Timer timer;
		//timer.Start();
		//DriveAuto::get()->wait(2.0);
		std::cout << "cato" << std::endl;
		cLifter.extendPiston();
		//Wait(2);
		//DriveAuto::get()->wait(2.0);
		//cLifter.retractPiston();
		//DriveAuto::get()->move(5, 0.5);
		std::cout << "cat" << std::endl;
		//DriveAuto::get()->getLeftMotors()->Set(0.6);
		//DriveAuto::get()->getRightMotors()->Set(0.6);
	}

	void AutonomousPeriodic()
	{
		/*
		 if(timer.Get() > 3)
		{
			cLifter.retractPiston();
		}
		*/
		DriveAuto::get()->update();
	}

	void TeleopInit()
	{
		RobotLocation::get()->getLeftEncoder()->Reset();
		RobotLocation::get()->getRightEncoder()->Reset();
		DriveAuto::get()->panic();
		shifter.shiftLow();
	}

	void TeleopPeriodic()
	{
		relay.checkStates();
		shifter.shiftUpdate();
		lifter.update();
		//std::cout << "left" << RobotLocation::get()->getLeftEncoder()->GetDistance() << std::endl;
		//std::cout << "right" << RobotLocation::get()->getRightEncoder()->GetDistance() << std::endl;
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
