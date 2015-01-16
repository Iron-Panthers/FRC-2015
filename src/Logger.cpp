#include "Logger.hpp"
#include <iostream>
#include <WPILib.h>
#include <string>
#include <fstream>

Logger::Logger()
{
	std::cout<< "constructor" << std::endl;
}

Logger::~Logger()
{
	std::cout<< "destructor" << std::endl;
}

void Logger::logToFile(Log log)
{
	std::cout<< log.action + log.position + log.time << std::endl;
}


