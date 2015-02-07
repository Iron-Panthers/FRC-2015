#ifndef ROBOT_LOCATION_HPP
#define ROBOT_LOCATION_HPP

#include <WPILib.h>
#include <utility>
#include "DriveAuto.hpp"
#include "TwoMotorGroup.hpp"
#include <queue>


class RobotLocation
{
public:
	const std::pair<float, float> getPosition();
	static RobotLocation* get();
	void update();

	const std::shared_ptr<Gyro> getGyro() const;
	std::shared_ptr<Encoder> getLeftEncoder();
	std::shared_ptr<Encoder> getRightEncoder();
private:
	RobotLocation();
	const std::shared_ptr<Gyro> gyro;
	std::shared_ptr<Encoder> left, right;
	std::pair<float, float> pos;
	float direction;
	static RobotLocation* instance;
};


#endif
