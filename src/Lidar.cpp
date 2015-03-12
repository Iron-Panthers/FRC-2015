#include "Lidar.hpp"

Lidar::Lidar(uint32_t channelPulseLength, uint32_t channelSensorManagement, uint32_t channelResistorLine)
	: pulseLength(channelPulseLength)
	, sensorManagement(channelSensorManagement)
	, resistorLine(channelResistorLine)

{
	sensorManagement.Set(1);
	resistorLine.Set(0);
}

double Lidar::getDistance() //returns distance in centimeters
{
	if(pulseLength.Get())
	{
		while (!pulseLength.Get()) {}
		auto start = std::chrono::high_resolution_clock::now();
		while (pulseLength.Get()) {}
		auto stop = std::chrono::high_resolution_clock::now();
		return std::chrono::duration<std::chrono::microseconds>(start - stop).count() / 10;
	}

	sensorManagement.Set(0);
	::Wait(.001);
	sensorManagement.Set(1);
	return 0;
}

double Lidar::PIDGet()
{
	return getDistance();
}
Lidar::~Lidar()
{

}
