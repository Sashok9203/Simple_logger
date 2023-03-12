#include "Logger.h"

Logger& Logger::getInstance()
{
	 static Logger instance;
	return instance;
}

void Logger::Log(mType Type, const std::string message)
{
	unsigned int id = getId();
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	std::ofstream ofs("MyLog.log", std::ios::app);
	if (!ofs) throw std::exception(" Error open file");
	switch (Type)
	{
	case Info:
		ofs << "INFO:";
		break;
	case Warning:
		ofs << "WARNING:";
		break;
	case Error:
		ofs << "ERROR:";
		break;
	}
	if (id < 10) ofs << "000";
	else if (id >= 10 && id < 100) ofs << "00";
	else if (id >= 100 && id < 1000) ofs << "0";
	ofs << id << " at " << now->tm_year + 1900 << "/" << now->tm_mon + 1 << "/" << now->tm_mday << " "
		<< (now->tm_hour < 10 ? "0" : "") << std::to_string(now->tm_hour) << ":"
		<< (now->tm_min < 10 ? "0" : "") << std::to_string(now->tm_min) << " - " << message << std::endl;
	ofs.close();
}

void Logger::showMessagesByType(mType Type)
{
	std::string tmp;
	std::ifstream ifs("MyLog.log");
	if (!ifs) std::cout << "No log messeges....";
	while (std::getline(ifs, tmp))
	{
		bool print = false;
		switch (Type)
		{
		case Info:
			print = tmp.front() == 'I';
			break;
		case Warning:
			print = tmp.front() == 'W';
			break;
		case Error:
			print = tmp.front() == 'E';
		}
		if (print) std::cout << tmp << std::endl;
	}
	ifs.close();
}

void Logger::showAllMessages()
{
	std::string tmp;
	std::ifstream ifs("MyLog.log");
	if (!ifs) std::cout << "No log messeges....";
	while (ifs)
	{
		std::getline(ifs, tmp);
		std::cout << tmp << std::endl;
	}
	ifs.close();
}






