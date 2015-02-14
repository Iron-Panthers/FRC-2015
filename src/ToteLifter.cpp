#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: toteEncoder(new Encoder(5, 6)), //Encoder ports
	  toteMotor(new Talon(7)),
	  toteMotorSpeed(1.0),
	  encoderValueFileName("lastEncoderValue.txt")
{
	std::ifstream lastEncoderValue(encoderValueFileName);
}

ToteLifter::~ToteLifter()
{

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
	std::fstream lastEncoderValue;
	lastEncoderValue.open (encoderValueFileName);
	lastEncoderValue << toteEncoder->GetDistance();
	std::ios::trunc << 	"lastEncoderValue.txt" << std::ofstream;
	lastEncoderValue.close();
}
