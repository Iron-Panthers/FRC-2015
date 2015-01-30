#ifndef VISIONCLASS_HPP
#define VISIONCLASS_HPP
#include <WPILib.h>
#include "VisionClass.cpp"

class Vision {
private:
	const std::string cameraIP;
	const AxisCamera camera;

public:
	Vision();
	float distanceToBox();
	float angleToBox();
};

#endif
