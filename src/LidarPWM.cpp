#include "LidarPWM.hpp"

LidarPWM::LidarPWM(uint32_t channelPulseLength, uint32_t channelSensorManagement, uint32_t channelResistorLine)
	: pulseLength(channelPulseLength)
	, sensorManagement(channelSensorManagement)
	, resistorLine(channelResistorLine)

{
	sensorManagement.Set(1);
	resistorLine.Set(0);
}

double LidarPWM::getDistance() //returns distance in centimeters
{
	for (int i = 0; !pulseLength.Get(); i++) { if (i > 500) break; else continue; }
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; pulseLength.Get(); i++) { if (i > 500) break; else continue; }
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	auto microseconds = std::chrono::duration_cast<std::chrono::duration<int, std::micro>>(duration);
	double dist = microseconds.count() / 10;


	if (dist != 0)
		return dist;

	sensorManagement.Set(0);
	::Wait(0.001);
	sensorManagement.Set(1);
	::Wait(0.001);
	return 0;
}

double LidarPWM::PIDGet()
{
	return getDistance();
}

LidarPWM::~LidarPWM()
{

}
