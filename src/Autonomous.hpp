#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP
#include <WPILib.h>

class Autonomous {
public:
	void run();
private:
	DriveAuto drive;
	Vision vision;
	SendableChooser autoChoice;
};
#endif
