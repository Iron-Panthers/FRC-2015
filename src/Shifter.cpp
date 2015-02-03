#include<WPILib.h>
#include <iostream>
#include "Shifter.hpp"
<<<<<<< HEAD
=======

Shifter::Shifter()
	: shift(new DoubleSolenoid(0, 1)) {}
>>>>>>> origin/master

Shifter::Shifter(int solenoidPortA, int solenoidPortB)
	: shift(new DoubleSolenoid(solenoidPortA, solenoidPortB))
{

}

void Shifter::shiftHigh()
{
	/*int pSpeedOne = get->getLeftEncoder();
	int pSpeedTwo = get()-> ;*/
	TwoMotorGroup::one->Set(0);
	TwoMotorGroup::two->Set(0);
	Wait(1);
	shift->Set(DoubleSolenoid::kForward);
	Wait(1);

	std::cout << "ShiftHigh online" << std::endl;
}

void Shifter::shiftLow()
{
	TwoMotorGroup::one->Set(0);
	TwoMotorGroup::two->Set(0);
	Wait(1);
	shift->Set(DoubleSolenoid::kReverse);
	Wait(1);
	std::cout << "ShiftLow online" << std::endl;
}
