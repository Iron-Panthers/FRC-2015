#include "ContainerLifter.hpp"

ContainerLifter::ContainerLifter()
{

}

ContainerLifter::ContainerLifter(int leftPortA, int leftPortB, int rightPortA, int rightPortB)
	: cRight(new DoubleSolenoid(rightPortA, rightPortB))
	, cLeft(new DoubleSolenoid(leftPortA, leftPortB))
{

}

void ContainerLifter::extendPiston()
{
	cRight->Set(DoubleSolenoid::kForward);
	cLeft->Set(DoubleSolenoid::kForward);
}

void ContainerLifter::retractPiston()
{
	cRight->Set(DoubleSolenoid::kReverse);
	cLeft->Set(DoubleSolenoid::kReverse);
}
