#ifndef LIDAR_I2C
#define LIDAR_I2C

#include <iostream>
#include <wpilib.h>
#include "Lidar.hpp"

class LidarI2C : public Lidar
{
public:
	LidarI2C(I2C::Port port, char address);
	virtual double getDistance();
	virtual double PIDGet();
	virtual ~LidarI2C();
private:
	I2C *lidar;
	void readyUp();
	/**
	 * Pin 1 - 5v
	 * Pin 2 - Power en - Digital output - turn off sensor (low) turn on sensor (high)
	 * Pin 3 - Modeline - Digital input - finding how long pulsed high
	 * Pin 3 - Resistor line - trigger - Digital output - set low for continuous read
	 * Pin 6 - GND
	 */
};

#endif
