#ifndef TOTE_LIFTER_HPP
#define TOTE_LIFTER_HPP
#include <WPILib.h>
#include <iostream>

class ToteLifter
{
public:
	ToteLifter();
	void setToteLevel(int level);
	float toteLevel;
	std::shared_ptr<Encoder> getToteEncoder();
	void update();

private:
	std::shared_ptr<Encoder> toteEncoder;
	Talon *ToteMotor;
	bool tolerance(double bulkUp, getToteEncoder(),  double epsilon);

};

#endif
