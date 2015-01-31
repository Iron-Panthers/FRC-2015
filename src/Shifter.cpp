#include<WPILib.h>
#include <iostream>
#include "Shifter.hpp"

Shifter::Shifter()
	: shift(new DoubleSolenoid(0, 1)) {}

Shifter::Shifter(int solenoidPortA, int solenoidPortB)
	: shift(new DoubleSolenoid(solenoidPortA, solenoidPortB))
{

}

void Shifter::shiftHigh()
{
	shift->Set(DoubleSolenoid::kForward);
	std::cout << "ShiftHigh online" << std::endl;
}

void Shifter::shiftLow()
{
	shift->Set(DoubleSolenoid::kReverse);
	std::cout << "ShiftLow online" << std::endl;
}
