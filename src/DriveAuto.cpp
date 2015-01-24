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
	std::pair<DriveActions, std::vector<float>> = std::queue::front();
}
