#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: toteEncoder(new Encoder(5, 6)), //Encoder ports
	  leftMotor(new Talon(7)),
	  rightMotor(new Talon(8)),
	  toteMotorSpeed(1.0),
	  encoderValueFileName("lastEncoderValue.txt")
{
	std::ifstream lastEncoderValue(encoderValueFileName);
	distanceOffset = std::stof(encoderValueFileName);
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
	double currentDistance = toteEncoder->GetDistance() + distanceOffset;
	if(!tolerance(currentDistance, targetDistance, 2))
	{
		if(targetDistance > currentDistance)
		{
			leftMotor->Set(toteMotorSpeed);
			rightMotor->Set(toteMotorSpeed);
		}
		else if(targetDistance < currentDistance)
		{
			leftMotor->Set(-toteMotorSpeed);
			rightMotor->Set(toteMotorSpeed);
		}
	}
	else
	{
		leftMotor->Set(0);
		rightMotor->Set(0);
	}
	std::ofstream lastEncoderValue(encoderValueFileName, std::ios::trunc);
	lastEncoderValue << toteEncoder->GetDistance() + distanceOffset;

	lastEncoderValue.close();
}
