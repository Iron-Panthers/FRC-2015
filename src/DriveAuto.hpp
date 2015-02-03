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
	void update();
	const static DriveAuto* get();

private:
	DriveAuto();
	std::queue<std::pair <DriveActions, std::vector<float>>> actionQueue;
	const std::unique_ptr<TwoMotorGroup> leftMotors;
	const std::unique_ptr<TwoMotorGroup> rightMotors;
	static DriveAuto* instance;
};

#endif
