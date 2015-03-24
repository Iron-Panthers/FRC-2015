#include "ToteLifter.hpp"

const double MIN_POT = 112.0;
const double MAX_POT = 0.0;

const double LEVELS[5] = { 112.22, 78.183, 70.183, 39.344, 31.264 };


ToteLifter::ToteLifter()
	: leftMotor(new Talon(0)),
	  rightMotor(new Talon(1)),
	  toteMotorSpeed(1.0),
	  encoderValueFileName("lastEncoderValue.txt"),
	  isManualUp(false),
	  isManualDown(false),
	  isManualStop(true),
	  pot(new AnalogPotentiometer(1, 112))
{
	//std::ifstream lastEncoderValue(encoderValueFileName);
	//distanceOffset = std::stof(encoderValueFileName);
	distanceOffset = 0;
	targetDistance = distanceOffset;
	//toteEncoder->SetDistancePerPulse(1/43.375);
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
	targetDistance = LEVELS[level];
}


/*std::shared_ptr<Encoder> ToteLifter::getToteEncoder()
{
	return toteEncoder;
}*/

void ToteLifter::manualUp()
{
	isManualUp = true;
	isManualDown = false;
	autoLevelMode = false;
}

void ToteLifter::manualDown()
{
	isManualUp = false;
	isManualDown = true;
	autoLevelMode = false;
}


void ToteLifter::update()
{
	if ((!isManualUp && !isManualDown) && autoLevelMode)
	{
		double pos = pot->Get();
		if (!tolerance(pos, targetDistance, 1.5))
		{
			if (targetDistance > pos)
			{
				moveDown();
			}
			else if (targetDistance < pos)
			{
				moveUp();
			}
		}
		else
		{
			stop();
		}
	}
	else
	{
		if(isManualUp)
		{
			moveUp();
		}
		else if(isManualDown)
		{
			moveDown();
		}
		else
		{
			stop();
		}
	}

	isManualUp = false;
	isManualDown = false;
}

void ToteLifter::moveUp()
{
	if (pot->Get() > (MAX_POT + 1.5))
	{
		leftMotor->Set(-1);
		rightMotor->Set(1);
	}
}
void ToteLifter::moveDown()
{
	if (pot->Get() < MIN_POT - 1.5)
	{
		leftMotor->Set(1);
		rightMotor->Set(-1);
	}
}
void ToteLifter::stop()
{
	leftMotor->Set(0);
	rightMotor->Set(0);

}

void ToteLifter::levelUp()
{
	double pos = pot->Get();

	double minGreater = 0.0;
	int minGreaterIndex = 0;
	for (int i = 0; i < 5; i++)
	{
		if (pos > LEVELS[i] && LEVELS[i] > minGreater)
		{
			minGreater = LEVELS[i];
			minGreaterIndex = i;
		}
	}
	setToteLevel(minGreaterIndex);
	autoLevelMode = true;
}

void ToteLifter::levelDown()
{
	double pos = pot->Get();

	double maxGreater = 99999.0;
	int maxGreaterIndex = 0;
	for (int i = 0; i < 5; i++)
	{
		if (pos < LEVELS[i] && LEVELS[i] < maxGreater)
		{
			maxGreater = LEVELS[i];
			maxGreaterIndex = i;
		}
	}
	setToteLevel(maxGreaterIndex);
	autoLevelMode = true;
}

