#ifndef LIDAR_PWM
#define LIDAR_PWM

#include <wpilib.h>
#include <iostream>
#include <chrono>
#include "Lidar.hpp"

class LidarPWM : public Lidar
{
public:
	LidarPWM(uint32_t channelPulseLength, uint32_t channelSensorManagement, uint32_t channelResistorLine);
	virtual double getDistance();
	virtual double PIDGet();
	virtual ~LidarPWM();
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
