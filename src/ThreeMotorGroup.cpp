#include <ThreeMotorGroup.hpp>
#include <WPIlib.h>

ThreeMotorGroup::ThreeMotorGroup(int portOne, int portTwo, int portThree)
{
	std::cout << "threemotorgroup constructor" << std::endl;
}

ThreeMotorGroup::~ThreeMotorGroup()
{
	std::cout << "threemotorgroup destructor" << std::endl;
}

void ThreeMotorGroup::Set(float speed, uint8_t syncGroup = 0)
{
	std::cout << "threemotorgroup set" << std::endl;
}

float ThreeMotorGroup::Get()
{
	std::cout << "threemotorgroup get" << std::endl;
}

void ThreeMotorGroup::Disable()
{
	std::cout << "threemotorgroup disable" << std::endl;
}

void ThreeMotorGroup::PIDWrite(float output)
{
	std::cout << "threemotorgroup pidwrite" << std::endl;
}
