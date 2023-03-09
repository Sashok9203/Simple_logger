#include "Logger.h"

void main()
{
	Logger& loger = Logger::getInstance();
	loger.Log(mType::Error, "Error !!! File not open...");
	loger.Log(mType::Info, "Construction is complete...");
	loger.Log(mType::Warning, "Warning !!! File not found...");
	loger.Log(mType::Error, "Error !!! Devide by zero !!!");
	loger.Log(mType::Info, "Construction is not completed...");
	loger.Log(mType::Warning, "Warning !!! Memory not allocated...");
	std::cout << "  ------ Warning messages ------" << std::endl;
	loger.showMessagesByType(mType::Warning);
	std::cout << "\n  ------ Information messages ------" << std::endl;
	loger.showMessagesByType(mType::Info);
	std::cout << "\n  ------ Error messages ------" << std::endl;
	loger.showMessagesByType(mType::Error);
	std::cout << "\n  ------ All messages ------" << std::endl;
	loger.showAllMessages();
}