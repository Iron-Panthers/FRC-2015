/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2014. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#pragma once

#include "interfaces/Accelerometer.h"
#include "SensorBase.h"
#include <string>

/**
 * Built-in accelerometer.
 *
 * This class allows access to the RoboRIO's internal accelerometer.
 */
class BuiltInAccelerometer : public Accelerometer, public SensorBase
{
public:
	BuiltInAccelerometer(Range range = kRange_8G);
        virtual ~BuiltInAccelerometer();

	// Accelerometer interface
	virtual void SetRange(Range range);
	virtual double GetX();
	virtual double GetY();
	virtual double GetZ();
};
