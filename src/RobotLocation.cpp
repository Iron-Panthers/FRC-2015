#include <WPILib.h>
#include "RobotLocation.hpp"
#include <iostream>
#include <cmath>

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
	  : gyro(new Gyro(0))
	  , left(new Encoder(0,1))
	  , right(new Encoder(2, 3))
	  , north(new LidarPWM(4, 5, 6))
	  , east(new LidarI2C(I2C::Port::kMXP, 0x62))

{
	left->SetDistancePerPulse(0.01031292364);
	right->SetDistancePerPulse(0.01031292364);
}

Lidar* RobotLocation::getNorth()
{
	return north;
}

Lidar* RobotLocation::getEast()
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

