#ifndef CONTAINER_LIFTER_HPP
#define CONTAINER_LIFTER_HPP

#include <iostream>
#include <WPILib.h>

class ContainerLifter
{
public:
	ContainerLifter();
	ContainerLifter(int leftPortA, int leftPortB, int rightPortA, int rightPortB);
	void extendPiston();
	void retractPiston();
	const std::unique_ptr<DoubleSolenoid> cRight;
	const std::unique_ptr<DoubleSolenoid> cLeft;
};

#endif
