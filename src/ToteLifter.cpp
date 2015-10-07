#include "ToteLifter.hpp"

ToteLifter::ToteLifter()
	: leftMotor(new Talon(0)),
	  rightMotor(new Talon(1)),
	  limitSwitch(new DigitalInput(9)),
	  isManualUp(false),
	  isManualDown(false),
	  override(false)
{
}

ToteLifter::~ToteLifter()
{
}

void ToteLifter::manualUp()
{
	isManualUp = true;
	isManualDown = false;
}

void ToteLifter::manualDown()
{
	isManualUp = false;
	isManualDown = true;
}


void ToteLifter::update()
{
	std::cout << "Limit Switch: " << limitSwitch->Get() << std::endl;
	if(isManualUp)
	{
		moveDown();
	}
	else if((isManualDown && limitSwitch->Get()) || (override && isManualDown))
	{
		moveUp();
	}
	else if(limitSwitch->Get() == false)
	{
		stop();
	}
	else
	{
		stop();
	}
	isManualUp = false;
	isManualDown = false;
	override = false;
}

void ToteLifter::moveUp()
{
	leftMotor->Set(1);
	rightMotor->Set(-1);
}
void ToteLifter::moveDown()
{
	leftMotor->Set(-1);
	rightMotor->Set(1);
}
void ToteLifter::stop()
{
	leftMotor->Set(0);
	rightMotor->Set(0);
}

void ToteLifter::limitOverride()
{
	override = true;
}

