#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP
#include <WPILib.h>
#include "Vision.hpp"
#include "DriveAuto.hpp"

class Autonomous
{
public:
	void run();
	Autonomous();
private:
	DriveAuto drive;
	Vision vision;
	SendableChooser autoChoice;
};
#endif
