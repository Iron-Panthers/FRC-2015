/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#pragma once

#include "HAL/HAL.hpp"
#include "SensorBase.h"
#include "PIDSource.h"

/**
 * Analog input class.
 *
 * Connected to each analog channel is an averaging and oversampling engine.  This engine accumulates
 * the specified ( by SetAverageBits() and SetOversampleBits() ) number of samples before returning a new
 * value.  This is not a sliding window average.  The only difference between the oversampled samples and
 * the averaged samples is that the oversampled samples are simply accumulated effectively increasing the
 * resolution, while the averaged samples are divided by the number of samples to retain the resolution,
 * but get more stable values.
 */
class AnalogInput : public SensorBase, public PIDSource
{
public:
	static const uint8_t kAccumulatorModuleNumber = 1;
	static const uint32_t kAccumulatorNumChannels = 2;
	static const uint32_t kAccumulatorChannels[kAccumulatorNumChannels];

	explicit AnalogInput(uint32_t channel);
	virtual ~AnalogInput();

	int16_t GetValue();
	int32_t GetAverageValue();

	float GetVoltage();
	float GetAverageVoltage();

	uint32_t GetChannel();

	void SetAverageBits(uint32_t bits);
	uint32_t GetAverageBits();
	void SetOversampleBits(uint32_t bits);
	uint32_t GetOversampleBits();

	uint32_t GetLSBWeight();
	int32_t GetOffset();

	bool IsAccumulatorChannel();
	void InitAccumulator();
	void SetAccumulatorInitialValue(int64_t value);
	void ResetAccumulator();
	void SetAccumulatorCenter(int32_t center);
	void SetAccumulatorDeadband(int32_t deadband);
	int64_t GetAccumulatorValue();
	uint32_t GetAccumulatorCount();
	void GetAccumulatorOutput(int64_t *value, uint32_t *count);

	static void SetSampleRate(float samplesPerSecond);
	static float GetSampleRate();

	double PIDGet();

private:
	void InitAnalogInput(uint32_t channel);
	uint32_t m_channel;
	void* m_port;
	int64_t m_accumulatorOffset;
};
