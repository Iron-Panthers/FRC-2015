#ifndef VISION_HPP
#define VISION_HPP
#include <iostream>
#include <WPILib.h>
#include <string>
#include <fstream>

class Vision
{
private:
	const std::string cameraIP;
	const AxisCamera camera;

public:
	Vision();
	float distanceToBox();
	float angleToBox();
};

#endif
