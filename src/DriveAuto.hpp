#ifndef DRIVE_AUTO_HPP
#define DRIVE_AUTO_HPP

#include <iostream>
#include <WPILib.h>
#include <queue>
#include "TwoMotorGroup.hpp"
#include "RobotLocation.hpp"

class DriveAuto {
public:
	void move(float feet, float motorVelocity);
	void axisTurn(float degrees);
	enum DriveActions
	{
		Move,
		Turn
	};
private:
	std::queue<std::pair <DriveActions, std::vector<float>>> actionQueues;
	const std::unique_ptr<TwoMotorGroup> leftMotors;
	const std::unique_ptr<TwoMotorGroup> rightMotors;
};

#endif
