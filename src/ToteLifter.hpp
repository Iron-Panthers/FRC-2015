#ifndef TOTE_LIFTER_HPP
#define TOTE_LIFTER_HPP
#include <WPILib.h>
#include <iostream>
#include <queue>
#include <fstream>

class ToteLifter
{
public:
	ToteLifter();
	~ToteLifter();
	void setToteLevel(int level);
	float toteLevel;
	std::shared_ptr<Encoder> getToteEncoder();
	void update();

private:
	std::shared_ptr<Encoder> toteEncoder;
	Talon *toteMotor;
	bool tolerance(double left, double right, double epsilon);
	double targetDistance;
	const double toteMotorSpeed;

	const std::string encoderValueFilename;
	double distanceOffset;

};

#endif
