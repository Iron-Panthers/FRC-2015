#include <ostream>
#include <WPILib.h>
#include <DriveAuto.hpp>

void DriveAuto::move(float feet, float motorVelocity)
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::Move;
	std::vector<float> params;
	params.push_back(feet);
	params.push_back(motorVelocity);
	moveAction.second = params;
	actionQueues.push (moveAction);
}

void DriveAuto::axisTurn(float degrees)
{
	std::pair<DriveActions, std::vector<float>> moveAction;
	moveAction.first = DriveActions::Turn;
	std::vector<float> params;
	params.push_back(degrees);
	moveAction.second = params;
	actionQueues.push (moveAction);
}

void DriveAuto::updateQueue()
{
	std::pair<DriveActions, std::vector<float>> action = std::queue::front();
	if(action.first == DriveActions::Move)
	{
		leftMotors->TwoMotorGroup::Set(action.second[1]);
		rightMotors->TwoMotorGroup::Set(action.second[1]);
		float distanceTraveled = leftEncoder->GetDistance();
		action.second[0] -= distanceTraveled;
		if(action.second[0] == 0)
		{
			actionQueues.pop();
		}
	}
	if(action.first == DriveActions::Turn)
	{
		if(action.second[0] < 0)
		{
			leftMotors->TwoMotorGroup::Set(-1);
			rightMotors->TwoMotorGroup::Set(1);
			if(action.second[0] == Gyro::GetAngle())
			{
				leftMotors->TwoMotorGroup::Set(0);
				rightMotors->TwoMotorGroup::Set(0);
				actionQueues.pop();
			}

		}
		if(action.second[0] > 0)
		{
			leftMotors->TwoMotorGroup::Set(1);
			rightMotors->TwoMotorGroup::Set(-1);
			if(action.second[0] == Gyro::GetAngle())
			{
				leftMotors->TwoMotorGroup::Set(0);
				rightMotors->TwoMotorGroup::Set(0);
				actionQueues.pop();
			}
		}
	}
}
