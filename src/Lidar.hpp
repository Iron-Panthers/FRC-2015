#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <wpilib.h>
#include <iostream>
#include <chrono>

class Lidar
{
public:
	virtual double getDistance() = 0;
	virtual double PIDGet();
	virtual ~Lidar();
};

#endif
