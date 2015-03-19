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
{
private:
	EventRelay relay;
	ToteLifter lifter;
	Shifter shifter;
	JoyTest joyTest;
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
						  , ButtonNames::Button11
						  , std::bind(&ToteLifter::manualStop, &lifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button7
						  , std::bind(&Shifter::shiftLow, &shifter)
						  , joyMap);

		createButtonMapping(true, false, false
						  , ButtonNames::Button8
						  , std::bind(&Shifter::shiftHigh, &shifter)
						  , joyMap);

		//up down z button respectively on gcn
		createButtonMapping(false, true, false
						  , ButtonNames::Button9
						  , std::bind(&ToteLifter::manualUp, &lifter)
						  , gcnMap);

		createButtonMapping(false, true, false
					      , ButtonNames::Button10
					      , std::bind(&ToteLifter::manualDown, &lifter)
						  , gcnMap);

		createButtonMapping(true, false, false
					      , ButtonNames::SideButton
						  , std::bind(&DriveAuto::panic, DriveAuto::get())
						  , gcnMap);

		createButtonMapping(true, false, false
				  	  	  , ButtonNames::SideButton
						  , std::bind(&DriveAuto::toteAlign, DriveAuto::get())
						  , joyMap);
	}

	void AutonomousInit()
	{
	}

	void AutonomousPeriodic()
	{
		Timer timer;

		auto rl = RobotLocation::get();
		timer.Start();
		std::cout << rl->getEast()->getDistance() << std::endl;
		timer.Stop();

		std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << timer.Get() << std::endl;

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		relay.checkStates();
		shifter.shiftUpdate();
		lifter.update();
		int dist = RobotLocation::get()->getEast()->getDistance();
		std::cout << dist << std::endl;
		std::cout << "\t" << RobotLocation::get()->getNorth()->getDistance() << std::endl;
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
