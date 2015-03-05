#include <WPILib.h>
#include "RobotLocation.hpp"
#include <iostream>
#include <cmath>

const std::pair<float, float> RobotLocation::getPosition()
{
	return pos;
}

RobotLocation* RobotLocation::instance = nullptr;
RobotLocation* RobotLocation::get()
{
	if(instance == nullptr)
	{
		instance = new RobotLocation();
	}
	return instance;
}

RobotLocation::RobotLocation()
	//: gyro(new Gyro(0))
	: left(new Encoder(0,1))
	//, b	uiltinaccelerometer()
	//: right(new Encoder(4, 5))

{
	//left->SetDistancePerPulse(0.073631077818);
	left->SetDistancePerPulse(0.073631077818 / 7.139690);
	//left->SetDistancePerPulse(163/12);
	//right->SetDistancePerPulse(0.073631077818 / 7.139690);
}

void RobotLocation::update()
{
	/*double x = builtinaccelerometer.GetX()
	double y = builtinaccelerometer.GetY()

	float distX = x * (1/3600);
	float distY = y * (1/3600);

	pos.first = distX += position.first
	pos.second = distY += position.second*/
}

Lidar RobotLocation::getNorth()
{
	return north;
}

Lidar RobotLocation::getEast()
{
	return east;
}

const std::shared_ptr<Gyro> RobotLocation::getGyro() const
{
	return gyro;
}

std::shared_ptr<Encoder> RobotLocation::getLeftEncoder()
{
	return left;
}

std::shared_ptr<Encoder> RobotLocation::getRightEncoder()
{
	return right;
}
