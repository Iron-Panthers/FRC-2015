#ifndef CONTAINER_LIFTER_HPP
#define CONTAINER_LIFTER_HPP

#include <iostream>
#include <WPILib.h>

class ContainerLifter
{
public:
	ContainerLifter();
	ContainerLifter(int portA, int portB);
	void extendPiston();
	void retractPiston();
	const std::unique_ptr<DoubleSolenoid> containerS;
};

#endif
