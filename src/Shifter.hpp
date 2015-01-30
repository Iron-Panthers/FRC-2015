#ifndef GEAR_SHIFTER_HPP
#define GEAR_SHIFTER_HPP

#include <WPILib.h>

class Shifter
{
	const std::unique_ptr<DoubleSolenoid> shift;
	Shifter(int solenoidPortA, int solenoidPortB);
	void shiftHigh();
	void shiftLow();
};

#endif
