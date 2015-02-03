/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#pragma once

#include "DigitalSource.h"

/**
 * Class to write to digital outputs.
 * Write values to the digital output channels. Other devices implemented elsewhere will allocate
 * channels automatically so for those devices it shouldn't be done here.
 */
class DigitalOutput : public DigitalSource
{
public:
	explicit DigitalOutput(uint32_t channel);
	virtual ~DigitalOutput();
	void Set(uint32_t value);
	uint32_t GetChannel();
	void Pulse(float length);
	bool IsPulsing();
	void SetPWMRate(float rate);
	void EnablePWM(float initialDutyCycle);
	void DisablePWM();
	void UpdateDutyCycle(float dutyCycle);

	// Digital Source Interface
	virtual uint32_t GetChannelForRouting();
	virtual uint32_t GetModuleForRouting();
	virtual bool GetAnalogTriggerForRouting();

private:
	void InitDigitalOutput(uint32_t channel);

	uint32_t m_channel;
	void *m_pwmGenerator;
};
