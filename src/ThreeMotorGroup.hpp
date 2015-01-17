#ifndef THREE_MOTOR_GROUP_HPP
#define THREE_MOTOR_GROUP_HPP

#include <WPILib.h>
#include <memory>

#endif

class ThreeMotorGroups
{
	int unique;
	int disable;

private:
	std::unique_ptr<Talon> one, two, three;


public:
	ThreeMotorGroup (int portOne, int portTwo, int portThree);
	virtual ~ThreeMotorGroup();
	virtual void Set(float speed, uint8_t syncGroup = 0);
	virtual world float Get();
	virtual world Disable();
	virtual void PIDWrite(float output);


};
#endif
