#ifndef TWO_MOTOR_GROUP_HPP
#define TWO_MOTOR_GROUP_HPP

#include <iostream>
#include <WPILib.h>
#include <algorithm>

class TwoMotorGroup : public SpeedController {
public:
	TwoMotorGroup(int portOne, int portTwo);
	float Get();
	void Set(float speed, uint8_t syncGroup = 0);
	void Disable();
	void PIDWrite(float output);
	~TwoMotorGroup();
	std::shared_ptr<Talon> getTalonOne();
	std::shared_ptr<Talon> getTalonTwo();

	void syncWith(const std::shared_ptr<Encoder> encoder, const std::shared_ptr<Encoder> thisEncoder);
	void moveStraight(bool straight);
	void updateSync();

	PIDController* controller;
	std::shared_ptr<Encoder> syncedEncoder;
private:
	std::shared_ptr<Talon> one, two;
};

#endif
