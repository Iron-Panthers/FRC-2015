#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <wpilib.h>
#include <iostream>
#include <chrono>

const float distance = 0xf;
const float distwo = 0x10;

class Lidar
{
public:
	//Lidar(I2C::Port port, uint8_t address);
	Lidar(uint32_t channel);
	double getDistance();
	virtual double PIDGet();
	virtual ~Lidar();
private:
	DigitalInput comm;
	DigitalOutput commOut;

};


#endif
