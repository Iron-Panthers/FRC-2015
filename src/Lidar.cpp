#include "Lidar.hpp"

Lidar::Lidar(I2C::Port port, uint8_t address) : comm(port, address)
{

}

double Lidar::getDistance()
{
	i2c.read
}
