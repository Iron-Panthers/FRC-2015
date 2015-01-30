#include <ThreeMotorGroup.hpp>
#include <WPIlib.h>

ThreeMotorGroup::ThreeMotorGroup(int portOne, int portTwo, int portThree)
{
	std::cout << "threemotorgroup constructor" << std::endl;
}

ThreeMotorGroup::~ThreeMotorGroup()
	portOne (new Talon)
	portTwo (new Talon)
	portThree (new Talon)
{
	std::cout << "threemotorgroup destructor" << std::endl;
}

void ThreeMotorGroup::Set(float speed, uint8_t syncGroup = 0)
	portOne->speed1
	portTwo->speed2
	portThree->speed3
	(speed1 + speed2 + speed3)/3 = averageSpeed
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
