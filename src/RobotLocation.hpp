#ifdef ROBOT_LOCATION_HPP
#define ROBOT_LOCATION_HPP

#include <WPILib.h>

class RobotLocation{
private:
	Gyro gyro;
	Encoder left, right;
	std::pair<float, float> pos;
	float direction;

public:
	RobotLocation();
	void update();
};


#endif
