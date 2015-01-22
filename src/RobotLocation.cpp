#include <WPILib.h>
#include "RobotLocation.hpp"
#include <iostream>
#include <cmath>

bool tolerance(float val1, float val2, float tolVal)
{
	if(fabs(val1 - val2) < tolVal)
	{
		return true;
	}
}

RobotLocation::RobotLocation()
	: gyro(1)
	, left(0,1)
	, right(0, 1)
{
	std::cout << "Hello World" << std::endl;
}

void RobotLocation::update()
{
	direction == gyro.GetAngle()*180/M_PI;
	if(tolerance(left.GetDistance(), right.GetDistance(), 5e-5) == true)
	{
		float x = left.GetDistance()/cos(direction);
		float y = right.GetDistance()/sin(direction);
		pos.first += x;
		pos.second += y;

	}

}

