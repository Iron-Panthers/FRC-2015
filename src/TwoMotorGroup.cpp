#include <WPILib.h>
#include "TwoMotorGroup.hpp"

TwoMotorGroup::TwoMotorGroup(int portOne, int portTwo)
	: one(new Talon(1))
	, two(new Talon(2))
{

}

float TwoMotorGroup::Set(float Speed)
{
	return 0.0f;
}

void TwoMotorGroup::Get()
{

}
