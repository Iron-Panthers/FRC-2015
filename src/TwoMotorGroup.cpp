#include <WPILib.h>
#include "TwoMotorGroup.hpp"
#include <iostream>

TwoMotorGroup::TwoMotorGroup(int portOne, int portTwo, bool isInverted)
	: one(new Talon(portOne))
	, two(new Talon(portTwo))
	, controller(nullptr)
	, isInverted(isInverted)
{
	std::cout << portOne << portTwo << "twomotorgroup constructor" << std::endl;
}

void TwoMotorGroup::Set(float speed, uint8_t syncGroup)
{
	if(isInverted)
	{
		one->Set(-speed);
		two->Set(-speed);
	}
	else if(isInverted == false)
	{
		one->Set(speed);
		two->Set(speed);
	}
}

float TwoMotorGroup::Get()
{
	float B;
	float speedOne = one->Get();
	float speedTwo = two->Get();
	B = (speedOne + speedTwo) /2; //average speed from both robots
	return B;
}

void TwoMotorGroup::Disable()
{
	one->Disable();
	two->Disable();
}

TwoMotorGroup::~TwoMotorGroup()
{
	delete controller;
}

std::shared_ptr<Talon> TwoMotorGroup::getTalonOne()
{
	return one;
}

std::shared_ptr<Talon> TwoMotorGroup::getTalonTwo()
{
	return two;
}

void TwoMotorGroup::syncWith(const std::shared_ptr<Encoder> encoderSync, const std::shared_ptr<Encoder> thisEncoder)
{
	syncedEncoder = encoderSync;
	controller = new PIDController(1.f, 1.f, 1.f, thisEncoder.get(), this);
	controller->SetInputRange(-1.0f, 1.0f);
	controller->SetOutputRange(-1.0f, 1.0f);
	controller->SetTolerance(0.01f);
}

void TwoMotorGroup::updateSync()
{
	if (controller)
		controller->SetSetpoint(syncedEncoder->GetRate() / 209.131f);
}

void TwoMotorGroup::moveStraight(bool straight)
{
	straight ? controller->Enable() : controller->Disable();
}

void TwoMotorGroup::PIDWrite(float output)
{
	Set(output);
}
