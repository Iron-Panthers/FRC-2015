#include "LidarPWM.hpp"

LidarPWM::LidarPWM(uint32_t channelPulseLength, uint32_t channelSensorManagement, uint32_t channelResistorLine)
	: pulseLength(channelPulseLength)
	, sensorManagement(channelSensorManagement)
	, resistorLine(channelResistorLine)
	, movingAverage(12)
{
	sensorManagement.Set(1);
	resistorLine.Set(0);
}

double LidarPWM::getDistance() //returns distance in centimeters
{
	Timer timer;
	timer.Start();
	while (!pulseLength.Get()) {
		if (timer.Get() > 0.01) return computedMA;
	}
	timer.Stop();
	timer.Reset();

	auto start = std::chrono::high_resolution_clock::now();

	timer.Start();
	while (pulseLength.Get()) {
		if (timer.Get() > 0.01) return computedMA;
	}
	timer.Stop();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	auto microseconds = std::chrono::duration_cast<std::chrono::duration<int, std::micro>>(duration);

	double dist = microseconds.count() / 10;

	if (dist == 0) return restart();

	movingAverage.giveRawValue(dist);
	return movingAverage.computeAverage();
}

double LidarPWM::restart()
{
	sensorManagement.Set(0);
	//::Wait(0.004);
	sensorManagement.Set(1);
	return computedMA;
}

double LidarPWM::PIDGet()
{
	return getDistance();
}

LidarPWM::~LidarPWM()
{

}
