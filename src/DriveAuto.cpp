#include <iostream>
#include <WPILib.h>
#include "DriveAuto.hpp"
#include "RobotLocation.hpp"
#include <cmath>

bool tolerance(double left, double right, double epsilon)
{
	return (std::abs(std::abs(left) - std::abs(right)) < epsilon);
}

float modification(float offset)
{
	float mod = 0;
	if(offset <= 45 && offset >= 30)
	{
		float m = (0.3 - 0.2) / (45 - 30);
		float b = -(m * 30) / 0.2;
		mod = m * offset + b;
	}
	else if(offset <= 30 && offset >= 15)
	{
		float m = (0.2 - 0.1) / (30 - 15);
		float b = -(m * 15) / 0.1;
		mod = m * offset + b;
	}
	else if(offset <= 15 && offset >= 7.5)
	{
		float m = (0.1 - 0.05) / (15 - 7.5);
		float b = -(m * 7.5) / 0.05;
		mod = m * offset + b;
	}
	else if(offset <= 7.5 && offset >= 3.75)
	{
		float m = (0.05 - 0.03) / (7.5 - 3.75);
		float b = -(m * 3.75) / 0.03;
		mod = m * offset + b;
	}
	else if(offset <= 3.75 && offset >= 2)
	{
		float m = ( 0.03 - 0.015) / (3.75 - 2);
		float b = -(m * 2) / 0.015;
		mod = m * offset + b;
	}

	return mod;
}

DriveAuto::DriveAuto()
	: leftMotors(new TwoMotorGroup(0, 1, true))
	, rightMotors(new TwoMotorGroup(2, 3, false))
{
	auto rl = RobotLocation::get();
	rl->getLeftEncoder()->SetPIDSourceParameter(Encoder::kRate);
	//rl->getRightEncoder()->SetPIDSourceParameter(Encoder::kRate);
	whatToName = true;
	initialAngle = true;
	initialTurn = true;
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
	std::vector<float> params;  //stores inches and motorVelocity
	params.push_back(inches);
	params.push_back(motorVelocity);
	float currentDistance = RobotLocation::get()->getLeftEncoder()->GetDistance();
	params.push_back(currentDistance);
	moveAction.second = params; //Puts inches & motorVelocity in moveAction
	actionQueue.push (moveAction); //Stores the params pair and the DriveAction in actionQueue

	//rightMotors->syncWith(RobotLocation::get()->getLeftEncoder(), RobotLocation::get()->getRightEncoder());
}

void DriveAuto::axisTurn(float degrees)
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::Turn;
	std::vector<float> params;
	params.push_back(degrees);
	moveAction.second = params;
	actionQueue.push (moveAction); //Puts degrees and Turn into actionQueue
}

void DriveAuto::wait(float seconds)
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::Wait;
	std::vector<float> params;
	params.push_back(seconds);
	moveAction.second = params;
	actionQueue.push (moveAction); //Stores seconds and Wait in actionQueue
}

void DriveAuto::update()
{
	if (actionQueue.size() == 0)
	{
		return; //If there's nothing in the queue to do then return
	}

	std::pair<DriveAuto::DriveActions, std::vector<float> > action = actionQueue.front();
	auto robotLocation = RobotLocation::get();

	if(action.first == DriveAuto::DriveActions::Move)
	{
		std::cout << "dog" << std::endl;
		if(whatToName == true)
		{
			std::cout << "bird" << std::endl;
			initialAngle = RobotLocation::get()->getGyro()->GetAngle();
			whatToName = false;
			std::cout << "cat" << std::endl;
		}
		else
		{
			std::cout << "cow" << std::endl;
			leftMotors->Set(action.second[1]);
			rightMotors->Set(action.second[1]); //Sets the left & right motors to the motorVelocity that was pushed in the queue in Move()
			float currentAngle = RobotLocation::get()->getGyro()->GetAngle();
			if(!tolerance(currentAngle, initialAngle - RobotLocation::get()->getGyro()->GetAngle(), 2))
			{
				float offset = currentAngle - initialAngle;
				if (currentAngle > initialAngle)
				{
					leftMotors->Set(action.second[1] - modification(offset));
					rightMotors->Set(action.second[1] + modification(offset));
				}
				else if(currentAngle < initialAngle)
				{
					leftMotors->Set(action.second[1] + modification(offset));
					rightMotors->Set(action.second[1] - modification(offset));
				}
			}
			float totalDistance = robotLocation->getLeftEncoder()->GetDistance();
			std::cout << actionQueue.size() << "\t" << totalDistance - action.second[2] <<  std::endl;
			if(tolerance(action.second[0], totalDistance - action.second[2], 0.5 * action.second[1] * 10)) //if totalDistance is more or less 0
			{
				leftMotors->Set(0);
				rightMotors->Set(0);
				actionQueue.pop();
				whatToName = true;
				if (actionQueue.size() > 0 && actionQueue.front().first == DriveAuto::DriveActions::Move) //If there's stuff in actionQueues
				{
					float leftDistance = robotLocation->getLeftEncoder()->GetDistance();
					actionQueue.front().second[2] = leftDistance;
				}
			}
		}
	}
	else if(action.first == DriveAuto::DriveActions::Turn)
	{
		if(initialTurn == true)
		{
			initialAngle = RobotLocation::get()->getGyro()->GetAngle();
			initialTurn = false;
		}
		else
		{
			float wantedAngle = RobotLocation::get()->getGyro()->GetAngle() - initialAngle;
			if(action.second[0] < 0) //want to turn right
			{
				leftMotors->Set(-1);
				rightMotors->Set(1);
				if(tolerance(action.second[0], wantedAngle, 2)) //need to use tolerance here
				{
					leftMotors->Set(0);
					rightMotors->Set(0);
					actionQueue.pop();
					initialTurn = true;
					if (actionQueue.size() > 0 && actionQueue.front().first == DriveAuto::DriveActions::Move) //If there's stuff in actionQueues
					{
						float leftDistance = robotLocation->getLeftEncoder()->GetDistance();
						actionQueue.front().second[2] = leftDistance;
					}
				}
			}
			if(action.second[0] > 0) //want to turn left
			{
				leftMotors->Set(1);
				rightMotors->Set(-1);
				if(tolerance(action.second[0], wantedAngle, 2)) //need to use tolerance here
				{
					leftMotors->Set(0);
					rightMotors->Set(0);
					actionQueue.pop();
					initialTurn = true;
					if (actionQueue.size() > 0 && actionQueue.front().first == DriveAuto::DriveActions::Move) //If there's stuff in actionQueues
					{
						float leftDistance = robotLocation->getLeftEncoder()->GetDistance();
						actionQueue.front().second[2] = leftDistance;
					}
				}
			}
		}
	}
	else if(action.first == DriveAuto::DriveActions::Wait)
	{
		leftMotors->Set(0);
		rightMotors->Set(0);
		::Wait(static_cast<double>(action.second[0]));
		actionQueue.pop();
	}
}
