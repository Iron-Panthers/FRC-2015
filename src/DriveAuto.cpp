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
	//, rightMotors(new TwoMotorGroup(0, 1))
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
	params.push_back(RobotLocation::get()->getLeftEncoder()->GetDistance());
	//params.push_back(RobotLocatoin::get()->getRightEncoder()->GetDistance());
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

	if(action.first == DriveAuto::DriveActions::Move)
	{
		leftMotors->Set(action.second[1]);
		//rightMotors->Set(action.second[1]);
		float totalDistance = RobotLocation::get()->getLeftEncoder()->GetDistance();
		std::cout << actionQueue.size() << "\t" << std::abs(action.second[0]) - std::abs(totalDistance - action.second[2]) <<  std::endl;
		if(tolerance(action.second[0], totalDistance - action.second[2], 0.5 * action.second[1] * 10))
		{
			leftMotors->Set(0);
			//rightMotors->Set(0);
			actionQueue.pop();
			if (actionQueue.size() > 0)
				actionQueue.front().second[2] = RobotLocation::get()->getLeftEncoder()->GetDistance();
		}
	}
	else if(action.first == DriveAuto::DriveActions::Turn)
	{
		if(action.second[0] < 0)
		{
			leftMotors->Set(-1);
			//rightMotors->Set(1);
			if(action.second[0] == RobotLocation::get()->getGyro()->GetAngle())
			{
				leftMotors->Set(0);
				//rightMotors->Set(0);
				actionQueue.pop();
			}

		}
		if(action.second[0] > 0)
		{
			leftMotors->Set(1);
			//rightMotors->Set(-1);
			if(action.second[0] == RobotLocation::get()->getGyro()->GetAngle())
			{
				leftMotors->Set(0);
				//rightMotors->Set(0);
				actionQueue.pop();
			}
		}
	}
	else if(action.first )
}
