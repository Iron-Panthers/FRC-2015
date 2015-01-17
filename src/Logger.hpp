#ifndef JOYSTICKWRAPPER_HPP
#define JOYSTICKWRAPPER_HPP

#include <WPILib.h>
#include <string>
#include <iostream>
#include "RobotLocation.hpp"

class Logger
{
public:
	static Logger *get();
	void log(std::string message);
	RobotLocation loc;

private:
	static Logger instance;
	Timer timer;
	std::string fileName;
};

#endif
