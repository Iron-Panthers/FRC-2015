#include<WPILib.h>
#include <iostream>
#include "Shifter.hpp"
#include "TwoMotorGroup.hpp"
#include "DriveAuto.hpp"


Shifter::Shifter(int solenoidPortA, int solenoidPortB)
	: shift(new DoubleSolenoid(solenoidPortA, solenoidPortB))
{

}

void Shifter::shiftHigh()
{
	int pSpeedOne = DriveAuto::get()->getLeftMotors()->Get();
	int pSpeedTwo = DriveAuto::get()->getRightMotors()->Get();
	Wait(1);
	shift->Set(DoubleSolenoid::kForward);
	Wait(1);
	DriveAuto::get()->getLeftMotors()->Set(pSpeedOne);
	DriveAuto::get()->getRightMotors()->Set(pSpeedTwo);
	std::cout << "ShiftHigh online" << std::endl;
}

void Shifter::shiftLow()
{
	int pSpeedOne = DriveAuto::get()->getLeftMotors()->Get();
	int pSpeedTwo = DriveAuto::get()->getRightMotors()->Get();
	Wait(1);
	shift->Set(DoubleSolenoid::kReverse);
	Wait(1);
	DriveAuto::get()->getLeftMotors()->Set(pSpeedOne);
	DriveAuto::get()->getRightMotors()->Set(pSpeedTwo);
	std::cout << "ShiftLow online" << std::endl;
}
