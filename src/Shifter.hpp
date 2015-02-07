#ifndef SHIFTER_HPP
#define SHIFTER_HPP

#include <WPILib.h>

class Shifter
{
public:
	Shifter();
	const std::unique_ptr<DoubleSolenoid> shift;
	Shifter(int solenoidPortA, int solenoidPortB);
	void shiftHigh();
	void shiftLow();
	void shiftUpdate();
};

#endif
