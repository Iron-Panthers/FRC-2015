#include "Logger.hpp"

static Logger Logger::*get()
{
	std::cout << "*get" << std::endl;
}

void Logger::log(std::string message)
{
	std::cout << "log" << std::endl;
}
