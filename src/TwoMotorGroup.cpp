#include <WPILib.h>
#include "TwoMotorGroup.hpp"
#include <iostream>

TwoMotorGroup::TwoMotorGroup(int portOne, int portTwo)
	: one(new Talon(1))
	, two(new Talon(2))
{

}

void TwoMotorGroup::Set(float speed)
{
	one->Set(speed);
	two->Set(speed);

}

float TwoMotorGroup::Get()
{
	int B;
	float speedOne = one->Get();
	float speedTwo = two->Get();
	B = (speedOne + speedTwo) /2;
	std::cout << B;
};
