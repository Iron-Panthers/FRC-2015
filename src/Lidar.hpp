#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <wpilib.h>
#include <iostream>

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
