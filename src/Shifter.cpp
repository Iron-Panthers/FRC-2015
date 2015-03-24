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
	shift->Set(DoubleSolenoid::kReverse);
	DriveAuto::get()->getLeftMotors()->Set(pSpeedOne);
	DriveAuto::get()->getRightMotors()->Set(pSpeedTwo);
}

void Shifter::shiftLow()
{
	int pSpeedOne = DriveAuto::get()->getLeftMotors()->Get();
	int pSpeedTwo = DriveAuto::get()->getRightMotors()->Get();
	shift->Set(DoubleSolenoid::kForward);
	DriveAuto::get()->getLeftMotors()->Set(pSpeedOne);
	DriveAuto::get()->getRightMotors()->Set(pSpeedTwo);
}

void Shifter::shiftUpdate()
{
	auto leftSpeed = RobotLocation::get()->getLeftEncoder()->GetRate();
	auto rightSpeed = RobotLocation::get()->getRightEncoder()->GetRate();

	float averageSpeed = (leftSpeed + rightSpeed)/2;
	if(averageSpeed >= 100 && RobotLocation::get()->getLeftEncoder()->Get() != DoubleSolenoid::kForward && RobotLocation::get()->getRightEncoder()->Get() != DoubleSolenoid::kForward)
	{
		//shiftHigh(); //if it's going faster than 100 and isn't already shifted high then shiftHigh
	}
	else if(averageSpeed < 100 && RobotLocation::get()->getLeftEncoder()->Get() != DoubleSolenoid::kReverse && RobotLocation::get()->getRightEncoder()->Get() != DoubleSolenoid::kReverse)
	{
		//shiftLow(); //if it's going slower than 100 and isn't already shifted low then shiftLow
	}
}

