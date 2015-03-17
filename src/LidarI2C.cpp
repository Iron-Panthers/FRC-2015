#include "LidarI2C.hpp"

void LidarI2C::readyUp()
{
	const int tries = 50;
	int ret = 1;
	for (int i = 0; ret != 0 && i < tries; i++)
	{
		ret = lidar.Write(0x00, 0x04);
		::Wait(0.002);
	}
}


LidarI2C::LidarI2C(I2C::Port port, char address)
	: lidar(port, address)
{
	readyUp();
}

double LidarI2C::getDistance() //returns distance in centimeters
{
	readyUp();

	const int tries = 50;
	int ret = 1;

	unsigned char distArray[2];
	for (int i = 0; ret != 0 && i < tries; i++)
	{
		ret = lidar.Read(0x8f, 2, distArray);
		::Wait(0.002);
	}

	int centimeters = (distArray[0] << 8) + distArray[1];
	return centimeters;
}

double LidarI2C::PIDGet()
{
	return getDistance();
}

LidarI2C::~LidarI2C()
{

}
