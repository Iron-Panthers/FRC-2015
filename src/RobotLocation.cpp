#include <WPILib.h>
#include "RobotLocation.hpp"
#include <iostream>
#include <cmath>

const std::pair<float, float> RobotLocation::getPosition()
{
	return pos;
}

const RobotLocation* RobotLocation::get()
{
	if(instance == nullptr)
	{
		instance = new RobotLocation();
	}
	return instance;
}

RobotLocation::RobotLocation()
	: gyro(1)
	, left(0,1)
	, right(0, 1)
{
	std::cout << "Hello World" << std::endl;
}

void RobotLocation::update()
{
	std::pair<DriveAuto::DriveActions, std::vector<float>> action = std::queue::front();
	if(action.first == DriveAuto::DriveActions::Move)
	{
		DriveAuto::leftMotors->TwoMotorGroup::Set(action.second[1]);
		DriveAuto::rightMotors->TwoMotorGroup::Set(action.second[1]);
		float distanceTraveled = left->GetDistance();
		action.second[0] -= distanceTraveled;
		if(action.second[0] == 0)
		{
			DriveAuto::actionQueues.pop();
		}
	}
	if(action.first == DriveAuto::DriveActions::Turn)
	{
		if(action.second[0] < 0)
		{
			DriveAuto::leftMotors->TwoMotorGroup::Set(-1);
			DriveAuto::rightMotors->TwoMotorGroup::Set(1);
			if(action.second[0] == gyro->GetAngle())
			{
				DriveAuto::leftMotors->TwoMotorGroup::Set(0);
				DriveAuto::rightMotors->TwoMotorGroup::Set(0);
				DriveAuto::actionQueues.pop();
			}

		}
		if(action.second[0] > 0)
		{
			DriveAuto::leftMotors->TwoMotorGroup::Set(1);
			DriveAuto::rightMotors->TwoMotorGroup::Set(-1);
			if(action.second[0] == gyro->GetAngle())
			{
				DriveAuto::leftMotors->TwoMotorGroup::Set(0);
				DriveAuto::rightMotors->TwoMotorGroup::Set(0);
				DriveAuto::actionQueues.pop();
			}
		}
	}
}

