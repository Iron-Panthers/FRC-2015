#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
<<<<<<< HEAD
	//: toteEncoder(new Encoder(5, 6)), //Encoder ports
	: toteMotor(new Talon(4)),
=======
	: toteEncoder(new Encoder(5, 6)), //Encoder ports
	  leftMotor(new Talon(7)),
	  rightMotor(new Talon(8)),
>>>>>>> origin/master
	  toteMotorSpeed(1.0),
	 encoderValueFileName("lastEncoderValue.txt")
{
<<<<<<< HEAD
	//std::ifstream lastEncoderValue(encoderValueFileName);
=======
	std::ifstream lastEncoderValue(encoderValueFileName);
	distanceOffset = std::stof(encoderValueFileName);
>>>>>>> origin/master
}

ToteLifter::~ToteLifter()
{
	delete toteMotor;
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
	toteMotor->Set(1.0);
}
void ToteLifter::setToteLevel2()
{
	setToteLevel(2);
	toteMotor->Set(-1.0);
}
void ToteLifter::setToteLevel3()
{
	setToteLevel(3);
	toteMotor->Set(0.0);
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
	//return toteEncoder;
}

void ToteLifter::update()
{
<<<<<<< HEAD
	/*double currentDistance = toteEncoder->GetDistance();
=======
	double currentDistance = toteEncoder->GetDistance() + distanceOffset;
>>>>>>> origin/master
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
<<<<<<< HEAD
	std::fstream lastEncoderValue;
	lastEncoderValue.open (encoderValueFileName);
	lastEncoderValue << toteEncoder->GetDistance();
	std::ios::trunc << 	"lastEncoderValue.txt" << std::ofstream;
	lastEncoderValue.close();*/

=======
	std::ofstream lastEncoderValue(encoderValueFileName, std::ios::trunc);
	lastEncoderValue << toteEncoder->GetDistance() + distanceOffset;

	lastEncoderValue.close();
>>>>>>> origin/master
}
