#include "../src/RobotLocation.hpp"

#include <WPILib.h>
#include <iostream>

RobotLocation::RobotLocation() : gyro(2, 3)
{
	std::cout << "Hello World" << std::endl;
}

void RobotLocation::update()
{
	std::cout << "Hello World" << std::endl;
}
