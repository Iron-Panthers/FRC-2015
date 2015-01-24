#ifndef DRIVE_AUTO_HPP
#define DRIVE_AUTO_HPP

#include <ostream>
#include <WPILib.h>
#include <queue>

class DriveAuto {
public:
	void move(float feet, float motorVelocity);
	void axisTurn(float degrees);
	void updateQueue();
	enum DriveActions
	{
		Move,
		Turn
	};
private:
	std::queue<std::pair <DriveActions, std::vector<float>>> actionQueues;
	const std::shared_ptr<Encoder> leftEncoder;
	const std::shared_ptr<Encoder> rightEncoder;
	const std::shared_ptr<Gyro> gyro;
	const std::unique_ptr<TwoMotorGroup> leftMotors;
	const std::unique_ptr<TwoMotorGroup> rightMotors;
};

#endif
