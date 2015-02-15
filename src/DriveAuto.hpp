#ifndef DRIVE_AUTO_HPP
#define DRIVE_AUTO_HPP

#include <iostream>
#include <WPILib.h>
#include <queue>
#include "TwoMotorGroup.hpp"
#include "RobotLocation.hpp"

class DriveAuto
{
public:
	void move(float feet, float motorVelocity);
	void axisTurn(float degrees);
	void wait(float seconds);
	enum DriveActions
	{
		Move,
		Turn,
		Wait
	};
	void update();
	static DriveAuto* get();
	const std::shared_ptr<TwoMotorGroup> getLeftMotors();
	const std::shared_ptr<TwoMotorGroup> getRightMotors();

private:
	DriveAuto();
	std::queue<std::pair <DriveActions, std::vector<float>>> actionQueue;
	const std::shared_ptr<TwoMotorGroup> leftMotors;
	const std::shared_ptr<TwoMotorGroup> rightMotors;
	static DriveAuto* instance;
	float initialAngle;
	bool whatToName;
};

#endif
