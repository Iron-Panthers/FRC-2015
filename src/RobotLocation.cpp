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
	: gyro(new Gyro(1))
	, left(new Encoder(0,1))
	, right(new Encoder(2, 3))
{
	std::cout << "Hello World" << std::endl;
	left->SetDistancePerPulse(163);
	//right->SetDistancePerPulse(163);
}

void RobotLocation::update()
{

}

const std::shared_ptr<Gyro> RobotLocation::getGyro() const
{
	return gyro;
}

std::shared_ptr<Encoder> RobotLocation::getLeftEncoder()
{
	return left;
}

const std::shared_ptr<Encoder> RobotLocation::getRightEncoder() const
{
	return right;
}
