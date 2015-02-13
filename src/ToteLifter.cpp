#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: toteEncoder(new Encoder(5, 6)), //Encoder ports
	  toteMotor(new Talon(7)),
	  toteMotorSpeed(1.0),
	  encoderValueFilename("lastEncoderValue.txt")
{
	std::ifstream lastEncoderValue("lastEncoderValue.txt")


}

ToteLifter::~ToteLifter()
{
	lastEncoderValue.close();
}

bool ToteLifter::tolerance(double left, double right, double epsilon)
{
	return (std::abs(std::abs(left) - std::abs(right)) < epsilon);
}

void ToteLifter::setToteLevel(int level)
{
	targetDistance = 12 * level + 3;
}

std::shared_ptr<Encoder> ToteLifter::getToteEncoder()
{
	return toteEncoder;
}

void ToteLifter::update()
{
	double currentDistance = toteEncoder->GetDistance();
	if(!tolerance(currentDistance, targetDistance, 2))
	{
		if(targetDistance > currentDistance)
		{
			toteMotor->Set(toteMotorSpeed);
		}
		else if(targetDistance < currentDistance)
		{
			toteMotor->Set(-toteMotorSpeed);
		}
	}
	else
	{
		toteMotor->Set(0);
	}
}
