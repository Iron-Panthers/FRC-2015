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
	Lidar(uint32_t channelPulseLength, uint32_t channelSensorManagement, uint32_t channelResistorLine);
	double getDistance();
	virtual double PIDGet();
	virtual ~Lidar();
private:
	DigitalInput pulseLength;
	DigitalOutput sensorManagement;
	DigitalOutput resistorLine;
	/**
	 * Pin 1 - 5v
	 * Pin 2 - Power en - Digital output - turn off sensor (low) turn on sensor (high)
	 * Pin 3 - Modeline - Digital input - finding how long pulsed high
	 * Pin 3 - Resistor line - trigger - Digital output - set low for continuous read
	 * Pin 6 - GND
	 */

};


#endif
