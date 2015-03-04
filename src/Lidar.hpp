#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <wpilib.h>
#include <iostream>

const float distance = 0xf;
const float distwo = 0x10;

class Lidar
{
public:
	Lidar(I2C::Port port, uint8_t address);
	double getDistance();
	virtual double PIDGet();
	virtual ~Lidar();
private:
	I2C comm;
};


#endif
