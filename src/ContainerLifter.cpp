#include "ContainerLifter.hpp"

ContainerLifter::ContainerLifter(int portA, int portB)
	: containerS(new DoubleSolenoid(portA, portB))
{

}

void ContainerLifter::extendPiston()
{
	containerS->Set(DoubleSolenoid::kForward);
	std::cout << "Extended Piston" << std::endl;
}

void ContainerLifter::retractPiston()
{
	containerS->Set(DoubleSolenoid::kReverse);
	std::cout << "Retract Piston" << std::endl;
}

