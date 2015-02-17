#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: toteEncoder(new Encoder(4, 5)), //Encoder ports
	  leftMotor(new Talon(5)),
	  rightMotor(new Talon(4)),
	  toteMotorSpeed(1.0),
	  encoderValueFileName("lastEncoderValue.txt")
{
	//std::ifstream lastEncoderValue(encoderValueFileName);
	//distanceOffset = std::stof(encoderValueFileName);
	distanceOffset = 0;
	targetDistance = distanceOffset;
	toteEncoder->SetDistancePerPulse(1/43.375);
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
	if(level > 0)
	{
		targetDistance = 16.5 * level + 5;
	}
	else
	{
		targetDistance = 16.5 * level;
	}
}
void ToteLifter::setToteLevel1()
{
	setToteLevel(0);
}
void ToteLifter::setToteLevel2()
{
	setToteLevel(1);
}
void ToteLifter::setToteLevel3()
{
	setToteLevel(2);
}
void ToteLifter::setToteLevel4()
{
	setToteLevel(3);
}

std::shared_ptr<Encoder> ToteLifter::getToteEncoder()
{
	return toteEncoder;
}

void ToteLifter::manualUp()
{
	isManualUp = true;
	isManualDown = false;
	isManualStop = false;
}

void ToteLifter::manualDown()
{
	isManualUp = false;
	isManualDown = true;
	isManualStop = false;
}

void ToteLifter::manualStop()
{
	isManualUp = false;
	isManualDown = false;
	isManualStop = true;
}

void ToteLifter::resumeAuto()
{
	isManualUp = false;
	isManualDown = false;
	isManualStop = false;
}

void ToteLifter::update()
{
	double currentDistance = toteEncoder->GetDistance() + distanceOffset;
	if(!tolerance(currentDistance, targetDistance, 2))
	{
		if(targetDistance > currentDistance)
		{
			leftMotor->Set(-toteMotorSpeed);
			rightMotor->Set(toteMotorSpeed);
		}
		else if(targetDistance < currentDistance)
		{
			leftMotor->Set(toteMotorSpeed);
			rightMotor->Set(-toteMotorSpeed);
		}
	}
	else
	{
		leftMotor->Set(0);
		rightMotor->Set(0);
	}

	std::cout << "toteEncoder: " << toteEncoder->GetDistance() << std::endl;

	std::ofstream lastEncoderValue(encoderValueFileName, std::ios::trunc);
	lastEncoderValue << toteEncoder->GetDistance() + distanceOffset;

	lastEncoderValue.close();

	if(isManualUp)
	{
		leftMotor->Set(-1);
		rightMotor->Set(1);
	}
	else if(isManualDown)
	{
		leftMotor->Set(1);
		rightMotor->Set(-1);
	}
	else if(isManualStop)
	{
		leftMotor->Set(0.0);
		rightMotor->Set(0.0);
	}
}
