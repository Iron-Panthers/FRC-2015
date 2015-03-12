#include "Lidar.hpp"

/*Lidar::Lidar(I2C::Port port, uint8_t address) : comm(port, address)
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
}*/

Lidar::Lidar(uint32_t channel)  : comm(channel)
{

}

double Lidar::getDistance()
{
	while (!comm.Get()) {}
	auto start = std::chrono::high_resolution_clock::now();
	while (comm.Get()) {}
	auto stop = std::chrono::high_resolution_clock::now();

	return std::chrono::duration<std::chrono::microseconds>(start - stop).count() / 10;
}

double Lidar::PIDGet()
{
	return getDistance();
}
Lidar::~Lidar()
{

}
