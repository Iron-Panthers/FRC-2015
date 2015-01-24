#ifndef DRIVE_AUTO_HPP
#define DRIVE_AUTO_HPP

#include <ostream>
#include <WPILib.h>
class DriveAuto {
public:
	void move(float feet, float velocity);
	void axisTurn(float degrees);

private:
	const std::shared_ptr<Encoder> leftEncoder;
	const std::shared_ptr<Encoder> rightEncoder;
	const std::shared_ptr<Gyro> gyro;
	//const std::unique_ptr<TwoMotorGroup> leftMotors;
	//const std::unique_ptr<TwoMotorGroup> rightMotors;
};







#endif
