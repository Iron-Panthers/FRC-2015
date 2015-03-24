#include "LidarI2C.hpp"

void LidarI2C::readyUp()
{
	const int tries = 5;
	int ret = 1;
	for (int i = 0; ret != 0 && i < tries; i++)
	{
		ret = lidar->Write(0x00, 0x04);
		std::cout << ret << '\t' << i << std::endl;
		::Wait(0.004);
	}
}


LidarI2C::LidarI2C(I2C::Port port, char address)
	: lidar(new I2C(port, address))
{
	::Wait(0.02);
	readyUp();
}

double LidarI2C::getDistance() //returns distance in centimeters
{
	const int tries = 10;
	int ret = 1;

	readyUp();
	unsigned char *distArray = new unsigned char[8];
	for (int i = 0; ret != 0 && i < tries; i++)
	{
		::Wait(0.003);
		ret = lidar->Read(0x8f, 2, distArray);

	}

	int centimeters = (distArray[0] << 8) + distArray[1];

	delete[] distArray;

	return centimeters;
	return 0;
}

double LidarI2C::PIDGet()
{
	return getDistance();
}

LidarI2C::~LidarI2C()
{
	delete lidar;
}
