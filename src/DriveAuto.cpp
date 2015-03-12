#include <iostream>
#include <WPILib.h>
#include "DriveAuto.hpp"
#include "RobotLocation.hpp"
#include <cmath>

const float DISTANCE_DS = 36;
const float DISTANCE_TS = 93825;

bool tolerance(double left, double right, double epsilon)
{
	return (std::abs(std::abs(left) - std::abs(right)) < epsilon);
}

float modification(float offset)
{
	float a = 0.000135f;
	float b = 0.008636f;
	float c = 0.015f;
	return a * offset * offset
	     + b * offset
	     + c;
}

DriveAuto::DriveAuto()
	: leftMotors(new TwoMotorGroup(4, 5, true))
	, rightMotors(new TwoMotorGroup(2, 3, false))
	, TURN_SPEED(0.15f)
{
	auto rl = RobotLocation::get();
	//rl->getLeftEncoder()->SetPIDSourceParameter(Encoder::kRate);
	//rl->getRightEncoder()->SetPIDSourceParameter(Encoder::kRate);
	initiallyStraight = true;
	initialAngle = true;
	initialTurn = true;
	initialAlign = true;

	distanceController = new PIDController(
				0.5f,
				0.f,
				0.f,
				RobotLocation::get()->getLeftEncoder(),
				DriveAuto::getLeftMotors());

	syncController = new PIDController(
					0.5f,
					0.f,
					0.f,
					RobotLocation::get()->getRightEncoder(),
					DriveAuto::getRightMotors());

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
	params.push_back(degrees - TURN_SPEED * 100 * (degrees / 180));
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

void DriveAuto::toteAlign()
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::ToteAlign;
	std::vector<float> params;
	moveAction.second = params;
	actionQueue.push (moveAction);
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
		if(initiallyStraight == true)
		{
			initialAngle = RobotLocation::get()->getGyro()->GetAngle();
			initiallyStraight = false;
		}
		else
		{
			leftMotors->Set(action.second[1]);
			rightMotors->Set(action.second[1]); //Sets the left & right motors to the motorVelocity that was pushed in the queue in Move()
			float currentAngle = RobotLocation::get()->getGyro()->GetAngle();
			std::cout << "InitialAngle: " << initialAngle << std::endl << "Current Angle: " << currentAngle << std::endl;
			if(!tolerance(currentAngle, initialAngle, 0.03))
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
			else
			{
				if(tolerance(leftMotors->Get(), 0, 0.01))
				{
					leftMotors->Set(action.second[1]);
					rightMotors->Set(action.second[1]);
				}
			}
			float totalDistance = robotLocation->getLeftEncoder()->GetDistance();
			if(tolerance(action.second[0], totalDistance - action.second[2], 0.5 * action.second[1] * 10)) //if totalDistance is more or less 0
			{
				leftMotors->Set(0);
				rightMotors->Set(0);
				actionQueue.pop();
				initiallyStraight = true;
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
			std::cout << "gyro" << RobotLocation::get()->getGyro()->GetAngle() << std::endl;
			float wantedAngle = RobotLocation::get()->getGyro()->GetAngle() - initialAngle;
			if(action.second[0] < 0) //want to turn right
			{
				leftMotors->Set(-TURN_SPEED);
				rightMotors->Set(TURN_SPEED);
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
				leftMotors->Set(TURN_SPEED);
				rightMotors->Set(-TURN_SPEED);
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
	/*else if(action.first == DriveAuto::DriveActions::ToteAlign)
	{
		float distanceEast = RobotLocation::get()->getEast()->getDistance();
		float distanceNorth = RobotLocation::get()->getNorth()->getDistance();
		if(tolerance(distanceEast, DISTANCE_DS, 1))
		{
			if(initialAlign == true)
			{
				leftMotors->Set(1);
				rightMotors->Set(1);
				initialAlign = false;
			}
			else
			{
				if(tolerance(distanceNorth, DISTANCE_TS, 1))
				{
					leftMotors->Set(0);
					rightMotors->Set(0);
				}
			}
		}
		else
		{
			if(distanceEast > DISTANCE_TS)
			{

			}
			else if(distanceEast < DISTANCE_TS)
			{

			}
		}
	}*/
}
