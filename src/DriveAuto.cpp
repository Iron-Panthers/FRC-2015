#include <iostream>
#include <WPILib.h>
#include "DriveAuto.hpp"
#include "RobotLocation.hpp"

void DriveAuto::move(float feet, float motorVelocity)
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::Move;
	std::vector<float> params;
	params.push_back(feet);
	params.push_back(motorVelocity);
	moveAction.second = params;
	actionQueue.push (moveAction);
}

void DriveAuto::axisTurn(float degrees)
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::Turn;
	std::vector<float> params;
	params.push_back(degrees);
	moveAction.second = params;
	actionQueue.push (moveAction);
}

void DriveAuto::update()
{
	std::pair<DriveAuto::DriveActions, std::vector<float>> action = actionQueue.front();
	if(action.first == DriveAuto::DriveActions::Move)
	{
		leftMotors->Set(action.second[1]);
		rightMotors->Set(action.second[1]);
		float distanceTraveled = RobotLocation::get()->getLeftEncoder()->GetDistance();
		action.second[0] -= distanceTraveled;
		if(action.second[0] == 0)
		{
			actionQueue.pop();
		}
	}
	if(action.first == DriveAuto::DriveActions::Turn)
	{
		if(action.second[0] < 0)
		{
			leftMotors->Set(-1);
			rightMotors->Set(1);
			if(action.second[0] == RobotLocation::get()->getGyro()->GetAngle())
			{
				leftMotors->Set(0);
				rightMotors->Set(0);
				actionQueue.pop();
			}

		}
		if(action.second[0] > 0)
		{
			leftMotors->Set(1);
			rightMotors->Set(-1);
			if(action.second[0] == RobotLocation::get()->getGyro()->GetAngle())
			{
				leftMotors->Set(0);
				rightMotors->Set(0);
				actionQueue.pop();
			}
		}
	}
}
