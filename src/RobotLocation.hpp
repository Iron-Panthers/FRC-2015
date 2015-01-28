#ifndef ROBOT_LOCATION_HPP
#define ROBOT_LOCATION_HPP

#include <WPILib.h>
#include <utility>

class RobotLocation
{
public:
	const std::pair<float, float> getPosition()
	const RobotLocation& get()
	void update();

private:
	RobotLocation();
	const std::unique_ptr <Gyro> gyro;
	const std::unique_ptr<Encoder> left, right;
	std::pair<float, float> pos;
	float direction;
	static RobotLocation instance;
};


#endif
