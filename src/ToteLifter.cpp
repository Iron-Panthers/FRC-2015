#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	//: toteEncoder(new Encoder(5, 6)), //Encoder ports
	: toteMotor(new Talon(4)),
	  toteMotorSpeed(1.0),
	 encoderValueFileName("lastEncoderValue.txt")
{
	//std::ifstream lastEncoderValue(encoderValueFileName);
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
	/*double currentDistance = toteEncoder->GetDistance();
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
	lastEncoderValue.close();*/

}
