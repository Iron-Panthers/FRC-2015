#ifndef ROBOT_LOCATION_HPP
#define ROBOT_LOCATION_HPP

#include <WPILib.h>
#include <utility>

class RobotLocation
{
public:
	RobotLocation();
	void update();

private:
	Gyro gyro;
	Encoder left, right;
	std::pair<float, float> pos;
	float direction;
};


#endif
