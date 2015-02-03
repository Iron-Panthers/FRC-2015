/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#pragma once

#include "PWM.h"


/**
 * A safe version of the PWM class.
 * It is safe because it implements the MotorSafety interface that provides timeouts
 * in the event that the motor value is not updated before the expiration time.
 * This delegates the actual work to a MotorSafetyHelper object that is used for all
 * objects that implement MotorSafety.
 */
class SafePWM : public PWM
{
public:
	explicit SafePWM(uint32_t channel);
	~SafePWM();

	void SetExpiration(float timeout);
	float GetExpiration();
	bool IsAlive();
	void StopMotor();
	bool IsSafetyEnabled();
	void SetSafetyEnabled(bool enabled);
	void GetDescription(char *desc);

	virtual void SetSpeed(float speed);
private:
	void InitSafePWM();
};
