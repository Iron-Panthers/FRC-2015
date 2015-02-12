#ifndef TWO_MOTOR_GROUP_HPP
#define TWO_MOTOR_GROUP_HPP

#include <iostream>
#include <WPILib.h>
#include <algorithm>

class TwoMotorGroup {
public:
	TwoMotorGroup(int portOne, int portTwo);
	float Get();
	void Set(float speed);
	~TwoMotorGroup();
	std::shared_ptr<Talon> getTalonOne();
	std::shared_ptr<Talon> getTalonTwo();

private:
	std::shared_ptr<Talon> one, two;
};

#endif
