#include "spdlog/spdlog.h"
#include "Logger.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "JoyButton.hpp"

Logger::Logger()
{
	std::cout << "constructor" << std::endl;
}

Logger::~Logger()
{
	std::cout<< "destructor" << std::endl;
}

void logToFile()
{
	//auto console = spd::stdout_logger_mt("console");
	console->info(JoyButton(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name));
}


