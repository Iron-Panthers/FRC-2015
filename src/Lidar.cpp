#include "Lidar.hpp"

Lidar::Lidar(I2C::Port port, uint8_t address) : comm(port, address)
{

}

double Lidar::getDistance()
{
	uint8_t buffer[255];
	comm.Read(0xf, 8, buffer);
	uint8_t greg = buffer[0];
	comm.Read(0x10, 8, buffer);
	greg = greg << 8;
	greg += buffer[0];

	return greg;
}
double Lidar::PIDGet()
{

}
Lidar::~Lidar()
{

}
