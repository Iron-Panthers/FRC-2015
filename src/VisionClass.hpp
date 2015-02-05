#ifndef VISUALCLASS_HPP
#define VISUALLCLASS_HPP
#include <iostream>
#include <WPILib.h>
#include <string>
#include <fstream>
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
