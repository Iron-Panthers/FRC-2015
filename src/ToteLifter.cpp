#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: toteEncoder(new Encoder(5, 6)), //Encoder ports
	  ToteMotor(new Talon(7))
{

}

bool tolerance(double bulkUp, double epsilon)
{
	return (std::abs(std::abs(bulkUp) - std::abs(right)) < epsilon);
}

void ToteLifter::setToteLevel(int level)
{
	float toteLevel = 12 * level + 3;
	if(tolerance(toteLevel, getToteEncoder(), 2))
	{

	}
}

std::shared_ptr<Encoder> ToteLifter::getToteEncoder()
{
	return toteEncoder;
}
