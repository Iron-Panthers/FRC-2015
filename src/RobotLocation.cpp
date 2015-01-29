#include <WPILib.h>
#include "RobotLocation.hpp"
#include <iostream>
#include <cmath>

const std::pair<float, float> RobotLocation::getPosition()
{
	return pos;
}

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
	, right(new Encoder(0, 1))
{
	std::cout << "Hello World" << std::endl;
}

void RobotLocation::update()
{

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
