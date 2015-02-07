#include <WPILib.h>
#include <iostream>
#include "Shifter.hpp"
#include "TwoMotorGroup.hpp"
#include "DriveAuto.hpp"
#include "RobotLocation.hpp"


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

void Shifter::shiftUpdate()
{
	float leftSpeed = RobotLocation::get()->getLeftEncoder()->GetRate();
	float rightSpeed = RobotLocation::get()->getRightEncoder()->GetRate();
	if(rightSpeed >= 100 && leftSpeed >= 100 && RobotLocation::get()->getLeftEncoder()->Get() != DoubleSolenoid::kForward && RobotLocation::get()->getRightEncoder()->Get() != DoubleSolenoid::kForward)
	{
		shiftHigh();
	}
	else if(rightSpeed < 100 && leftSpeed < 100 && RobotLocation::get()->getLeftEncoder()->Get() != DoubleSolenoid::kReverse && RobotLocation::get()->getRightEncoder()->Get() != DoubleSolenoid::kReverse)
	{
		shiftLow();
	}
}

