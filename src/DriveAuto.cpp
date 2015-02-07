#include <iostream>
#include <WPILib.h>
#include "DriveAuto.hpp"
#include "RobotLocation.hpp"
#include <cmath>

bool tolerance(double left, double right, double epsilon)
{
	return (std::abs(std::abs(left) - std::abs(right)) < epsilon);
}

DriveAuto::DriveAuto()
	: leftMotors(new TwoMotorGroup(0, 1))
	, rightMotors(new TwoMotorGroup(2, 3))
{

}

DriveAuto* DriveAuto::instance = nullptr;
DriveAuto* DriveAuto::get()
{
	if(instance == nullptr)
	{
		instance = new DriveAuto();
	}
	return instance;
}

const std::shared_ptr<TwoMotorGroup> DriveAuto::getLeftMotors()
{
	return leftMotors;
}

const std::shared_ptr<TwoMotorGroup> DriveAuto::getRightMotors()
{
	return rightMotors;
}

void DriveAuto::move(float inches, float motorVelocity)
{
	std::cout << "move" << std::endl;
	std::pair<DriveActions, std::vector<float> > moveAction;
	moveAction.first = DriveActions::Move;
	std::vector<float> params;
	params.push_back(inches);
	params.push_back(motorVelocity);
	float leftDistance = RobotLocation::get()->getLeftEncoder()->GetDistance();
	float rightDistance = RobotLocation::get()->getRightEncoder()->GetDistance();
	float currentDistance = (leftDistance + rightDistance) / 2.0f;
	params.push_back(currentDistance);
	moveAction.second = params;
	actionQueue.push (moveAction);
}

void DriveAuto::axisTurn(float degrees)
{
	std::pair<DriveActions, std::vector<float> > moveAction;
	moveAction.first = DriveActions::Turn;
	std::vector<float> params;
	params.push_back(degrees);
	moveAction.second = params;
	actionQueue.push (moveAction);
}

void DriveAuto::update()
{
	if (actionQueue.size() == 0)
	{
		return;
	}

	std::pair<DriveAuto::DriveActions, std::vector<float> > action = actionQueue.front();
	auto robotLocation = RobotLocation::get();

	if(action.first == DriveAuto::DriveActions::Move)
	{
		leftMotors->Set(-action.second[1]);
		rightMotors->Set(action.second[1]);

		float leftDistance = robotLocation->getLeftEncoder()->GetDistance();
		float rightDistance = robotLocation->getRightEncoder()->GetDistance();
		float totalDistance = (leftDistance + rightDistance) / 2.0f;
		std::cout << actionQueue.size() << "\t" << totalDistance - action.second[2] <<  std::endl;
		if(tolerance(action.second[0], totalDistance - action.second[2], 0.5 * action.second[1] * 10))
		{
			leftMotors->Set(0);
			rightMotors->Set(0);
			actionQueue.pop();
			if (actionQueue.size() > 0)
			{
				float leftDistance = robotLocation->getLeftEncoder()->GetDistance();
				float rightDistance = robotLocation->getRightEncoder()->GetDistance();
				float totalDistance = (leftDistance + rightDistance) / 2.0f;
				actionQueue.front().second[2] = totalDistance;
			}

		}
	}
	else if(action.first == DriveAuto::DriveActions::Turn)
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
	else if(action.first )
	{

	}
}
