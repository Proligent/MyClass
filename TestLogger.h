#pragma once
#include <log4cplus/logger.h>
#include <log4cplus/layout.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/loggingmacros.h>



class TestLogger
{
public:
	TestLogger(void);
	~TestLogger(void);
	
	void Debug(std::string message);
	void Debug(const TCHAR* format, ...);
	
	void Info(std::string message);
	void Info(const TCHAR* format, ...);
	
	void Warn(std::string message);
	void Warn(const TCHAR* format, ...);
	
	void Error(std::string message);
	void Error(const TCHAR* format, ...);
	
	void Fatal(std::string message);
	void Fatal(const TCHAR* format, ...);
	
private:
	log4cplus::Logger	m_logger;
	
/*****************************************	
private:
	std::string  m_sPrefix;	
*****************************************/
};



