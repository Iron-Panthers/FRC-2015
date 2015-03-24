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
#include "Lidar.hpp"
#include "LidarI2C.hpp"
#include "LidarPWM.hpp"

void createButtonMapping(bool down, bool pressed, bool up,
						 ButtonNames buttonName,
						 std::function<void()> callback,
						 ActionMap &map)
{
	JoyButton button(down, pressed, up, buttonName);
	Action<void()> action(callback, 0);
	map.associate(button, action);
}

class Robot: public IterativeRobot
	:Lidar(new LidarI2(0x62)
{
private:
	EventRelay relay;
	ToteLifter lifter;
	Shifter shifter;
	JoyTest joyTest;
	LidarI2C *Lidar;

public:
	Robot() : shifter(0, 1)
	{
	}

	void RobotInit()
	{
		auto &joyMap = relay.getMapJoy();
		auto &gcnMap = relay.getMapGCN();

		createButtonMapping(true, false, false
				          , ButtonNames::Button9
						  , std::bind(&ToteLifter::manualUp, &lifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button10
						  , std::bind(&ToteLifter::manualDown, &lifter)
						  , joyMap);


		createButtonMapping(true, false, false
						  , ButtonNames::Button7
						  , std::bind(&Shifter::shiftLow, &shifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button8
						  , std::bind(&Shifter::shiftHigh, &shifter)
						  , joyMap);

		//up down dpad
		createButtonMapping(false, true, false
						  , ButtonNames::Button9
						  , std::bind(&ToteLifter::manualUp, &lifter)
						  , gcnMap);

		//z
		createButtonMapping(false, true, false
					      , ButtonNames::Button10
					      , std::bind(&ToteLifter::manualDown, &lifter)
						  , gcnMap);

		//x
		createButtonMapping(true, false, false
						  , ButtonNames::BottomRight
						  , std::bind(&ToteLifter::levelUp, &lifter)
						  , gcnMap);

		//y
		createButtonMapping(true, false, false
					      , ButtonNames::BottomLeft
					      , std::bind(&ToteLifter::levelDown, &lifter)
						  , gcnMap);

		//b
		createButtonMapping(true, false, false
					      , ButtonNames::SideButton
						  , std::bind(&DriveAuto::panic, DriveAuto::get())
						  , gcnMap);


	}

	void AutonomousInit()
	{
		//DriveAuto::get()->move(72, 0.5);
		Timer timer;
		timer.Start();
		while (timer.Get() < 3.00)
			lifter.moveUp();
		Wait(2);
		DriveAuto::get()->axisTurn(90);
		DriveAuto::get()->wait(1);
		DriveAuto::get()->move(100, 0.75);
	}

	void AutonomousPeriodic()
	{
		DriveAuto::get()->update();
		lifter.update();
	}

	void TeleopInit()
	{
		DriveAuto::get()->panic();
		shifter.shiftLow();
	}

	void TeleopPeriodic()
	{
		relay.checkStates();
		shifter.shiftUpdate();
		lifter.update();
		std::cout << "Lidar Get Good" << Lidar.getDistance() << std::endl;
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
