#ifndef TOTE_LIFTER_HPP
#define TOTE_LIFTER_HPP
#include <WPILib.h>
#include <iostream>
#include <queue>
#include <fstream>
#include <ostream>
#include <string>

class ToteLifter
{
public:
	ToteLifter();
	~ToteLifter();

	bool isManualUp;
	bool isManualDown;
	bool override;

	void manualUp();
	void manualDown();
	void moveUp();
	void moveDown();
	void stop();
	void update();
	void limitOverride();

private:
	std::shared_ptr<Talon> leftMotor;
	std::shared_ptr<Talon> rightMotor;

	DigitalInput *limitSwitch;
};

#endif
