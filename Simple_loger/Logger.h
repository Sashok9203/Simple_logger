#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

enum mType
{
	Info, Warning, Error
};
class Logger
{
private:
	Logger() {}
	Logger(const Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
	unsigned int getId() { static unsigned int ID = 0; return ++ID; }
public:
	static Logger& getInstance();
	void Log(mType Type, const std::string message);
	void showMessagesByType(mType Type);
	void showAllMessages();
};

