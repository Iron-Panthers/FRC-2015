#include <WPILib.h>
#include "TwoMotorGroup.hpp"
#include <iostream>

TwoMotorGroup::TwoMotorGroup(int portOne, int portTwo)
	: one(new Talon(portOne))
	, two(new Talon(portTwo))
{
	std::cout << portOne << portTwo << "twomotorgroup constructor" << std::endl;
}

void TwoMotorGroup::Set(float speed)
{
	one->Set(speed);
	two->Set(speed);
}

float TwoMotorGroup::Get()
{
	float B;
	float speedOne = one->Get();
	float speedTwo = two->Get();
	B = (speedOne + speedTwo) /2; //average speed from both robots
	return B;
}

TwoMotorGroup::~TwoMotorGroup()
{

}
