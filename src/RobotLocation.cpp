#include <WPILib.h>
#include "RobotLocation.hpp"
#include <iostream>
#include <cmath>

const std::pair<float, float> RobotLocation::getPosition()
{
	return pos;
}

RobotLocation* RobotLocation::instance = nullptr;
const RobotLocation* RobotLocation::get()
{
	if(instance == nullptr)
	{
		instance = new RobotLocation();
	}
	return instance;
}

RobotLocation::RobotLocation()
	: gyro(new Gyro(1))
	, left(new Encoder(0,1))
	, builtinaccelerometer()
//	, right(new Encoder(2, 3))
{
	std::cout << "Hello World" << std::endl;
}

void RobotLocation::update()
{
	double x = builtinaccelerometer.GetX()
	double y = builtinaccelerometer.GetY()

	float x * (1/3600);
	float  * distX;
	float y * (1/3600);
	float  * distY;

	double distX
	double distY
	builtinaccelerometer ** (1/3600)

	float radius = 3.0;
	float circumference = radius * 2 * 3.14;
}

const std::shared_ptr<Gyro> RobotLocation::getGyro() const
{
	return gyro;
}

const std::shared_ptr<Encoder> RobotLocation::getLeftEncoder() const
{
	return left;
}

const std::shared_ptr<Encoder> RobotLocation::getRightEncoder() const
{
	return right;
}
