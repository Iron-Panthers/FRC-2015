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

	const int MA_LENGTH = 12;

	movingAverage.push_front(dist);
	if (movingAverage.size() > MA_LENGTH) movingAverage.pop_back();
	else if (movingAverage.size() < MA_LENGTH) return dist;

	int max = 0, min = 999999;
	std::for_each (movingAverage.begin(), movingAverage.end(),	//identify outliers
		[&] (auto e) {
			if (e > max) max = e; else if (e < min) min = e;
		}
	);

	auto copy = movingAverage;
	copy.remove_if([&] (auto e) { return e <= min || e >= max; });

	computedMA = 0;
	for (auto e : copy) { computedMA += e; }
	computedMA /= copy.size();

	return computedMA;
}

double LidarPWM::restart()
{
	sensorManagement.Set(0);
	::Wait(0.004);
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
