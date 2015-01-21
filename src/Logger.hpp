#ifndef JOYSTICKWRAPPER_HPP
#define JOYSTICKWRAPPER_HPP

#include <WPILib.h>
#include <string>

#include "../src/RobotLocation.hpp"

struct Log{
	std::string action;
	//use RobotLocation
	std::string position;
	std::string time;
};

class Logger
{
private:
	Timer timer;
	static Log myLog;
	std::string outputFile;
public:
	void logToFile(Log log);
	Logger();
	~Logger();
};

#endif
