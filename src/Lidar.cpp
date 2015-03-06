#include "Lidar.hpp"

Lidar::Lidar(I2C::Port port, uint8_t address) : comm(port, address)
{
	if (port == I2C::Port::kMXP) std::cout << "mxp" << std::endl; else std::cout << "onboard" << std::endl;

	int val = 100;
	while (val > 0)
	{
		val = comm.Write(0x00, 0x04);
		std::cout << "i2cval: " << val << std::endl;

		::Wait(0.5);
	}
	if (port == I2C::Port::kMXP) std::cout << "mxpend" << std::endl; else std::cout << "onboardend" << std::endl;
}

double Lidar::getDistance()
{
	unsigned char buffer[2];

	std::cout << "Reading: " << comm.Read(0x8f, 2, buffer) << std::endl;
	int dist = (buffer[0] << 8) + buffer[1];
	std::cout << dist << std::endl;

	::Wait(0.02);
	int val = 100;
	while (val > 0)
	{
		val = comm.Write(0x00, 0x04);
		std::cout << "i2cval: " << val << std::endl;
		::Wait(1.0);
		//::Wait(0.02);
	}
	return dist;
}

double Lidar::PIDGet()
{
	return getDistance();
}

Lidar::~Lidar()
{

}
