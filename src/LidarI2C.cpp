#include "LidarI2C.hpp"

void LidarI2C::readyUp()
{
	const int tries = 50;
	int ret = 1;
	for (int i = 0; ret != 0 && i < tries; i++)
	{
		ret = lidar->Write(0x00, 0x04);
		::Wait(0.04);
	}
}


LidarI2C::LidarI2C(I2C::Port port, char address)
	: lidar(new I2C(port, address))
{
	::Wait(0.5);
	readyUp();
}

double LidarI2C::getDistance() //returns distance in centimeters
{

	const int tries = 50;
	int ret = 1;

	readyUp();
	unsigned char *distArray = new unsigned char[2];
	for (int i = 0; ret != 0 && i < tries; i++)
	{
		::Wait(0.04);
		ret = lidar->Read(0x8f, 2, distArray);
		std::cout << "ret: " << ret << "\t" << i << std::endl;

	}

	int centimeters = (distArray[0] << 8) + distArray[1];

	delete[] distArray;
	return centimeters;
}

double LidarI2C::PIDGet()
{
	return getDistance();
}

LidarI2C::~LidarI2C()
{
	delete lidar;
}
