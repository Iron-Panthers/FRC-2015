#ifndef THREE_MOTOR_GROUP_HPP
#define THREE_MOTOR_GROUP_HPP

#include <WPILib.h>
#include <memory>

class ThreeMotorGroup : public SpeedController
{
private:
	std::unique_ptr<Talon> one;
	std::unique_ptr<Talon> two;
	std::unique_ptr<Talon> three;
public:
	ThreeMotorGroup(int portOne, int portTwo, int portThree);
	virtual ~ThreeMotorGroup();
	virtual void Set(float speed, uint8_t syncGroup);
	virtual float Get();
	virtual void Disable();
	virtual void PIDWrite(float output);
};

#endif
