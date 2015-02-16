#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: toteEncoder(new Encoder(5, 6)), //Encoder ports
	  leftMotor(new Talon(6)),
	  rightMotor(new Talon(7)),
	  toteMotorSpeed(1.0),
	  encoderValueFileName("lastEncoderValue.txt")
{
	std::ifstream lastEncoderValue(encoderValueFileName);
	distanceOffset = std::stof(encoderValueFileName);
	targetDistance = distanceOffset;
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
void ToteLifter::setToteLevel1()
{
	setToteLevel(1);
}
void ToteLifter::setToteLevel2()
{
	setToteLevel(2);
}
void ToteLifter::setToteLevel3()
{
	setToteLevel(3);
}
void ToteLifter::setToteLevel4()
{
	setToteLevel(4);
}
void ToteLifter::setToteLevel5()
{
	setToteLevel(5);
}
void ToteLifter::setToteLevel6()
{
	setToteLevel(6);
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
			rightMotor->Set(-toteMotorSpeed);
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
