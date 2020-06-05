#include "TestLogger.h"

//
TestLogger::TestLogger()
{
	
	tstring s_fileName = ;
	/*1. Instantiate an appender object*/
	SharedObjectPtr<Appender> _append(new FileAppender(s_fileName));
	_append->setName(_T("fileAppender"));


	/*2. Instantiate a layout object*/ 　
	tstring pattern = _T("%d{%m/%d/%y %H:%M:%S} - %m[%l]%n");
	std::auto_ptr<Layout> _layout(new PatternLayout(pattern));

	
	
	
}

/******************************************************
TestLogger::TestLogger(const TestLogger &other)
{	
	this->m_appender = other.m_appender;
	this->m_layout = other.m_layout;
	this->m_logger = other.m_logger;
}

TestLogger& TestLogger::operator=(const TestLogger &other)
{
	this->m_appender = other.m_appender;
	this->m_layout = other.m_layout;
	this->m_logger = other.m_logger;
	return *this;
}
*******************************************************/
TestLogger::~TestLogger()
{
	m_logger.shutdown();
}

void TestLogger::Debug(std::string message)
{
	if(m_logger.getName().empty())
	{
		return;
	}
	
	LOG4CPLUS_DEBUG(m_logger, message);
}

void TestLogger::Debug(const TCHAR* format, ...)
{
	va_list list;
	va_start(list, format);
	int size = _vscprintf(format, list);
	std::string result(++size, 0);
	vsnprintf_s( (char *) result.data(), size, _TRUNCATE, format, list );
	va_end(list);
	result.erase(size);

	Debug(result);
}

void TestLogger::Info(std::string message)
{
	if(m_logger.getName().empty())
		return;

	LOG4CPLUS_INFO(m_logger, message);	
}

void TestLogger::Info(const TCHAR* format, ...)
{
	va_list list;
	va_start(list, format);
	int size = _vscprintf(format, list);
	std::string result(++size, 0);
	vsnprintf_s( (char *) result.data(), size, _TRUNCATE, format, list );
	va_end(list);
	result.erase(size);

	Info(result);	
}

void TestLogger::Warn(std::string message)
{
	if(m_logger.getName().empty())
		return;

	LOG4CPLUS_WARN(m_logger, message);	
}

void TestLogger::Warn(const TCHAR* format, ...)
{
	va_list list;
	va_start(list, format);
	int size = _vscprintf(format, list);
	std::string result(++size, 0);
	vsnprintf_s( (char *) result.data(), size, _TRUNCATE, format, list );
	va_end(list);
	result.erase(size);

	Warn(result);	
}

void TestLogger::Error(std::string message)
{
	if(m_logger.getName().empty())
		return;

	LOG4CPLUS_ERROR(m_logger, message);	
}

void TestLogger::Error(const TCHAR* format, ...)
{
	va_list list;
	va_start(list, format);
	int size = _vscprintf(format, list);
	std::string result(++size, 0);
	vsnprintf_s( (char *) result.data(), size, _TRUNCATE, format, list );
	va_end(list);
	result.erase(size);

	Error(result);		
}

void TestLogger::Fatal(std::string message)
{
	if(m_logger.getName().empty())
		return;

	LOG4CPLUS_FATAL(m_logger, message);
}

void TestLogger::Fatal(const TCHAR* format, ...)
{
	va_list list;
	va_start(list, format);
	int size = _vscprintf(format, list);
	std::string result(++size, 0);
	vsnprintf_s( (char *) result.data(), size, _TRUNCATE, format, list );
	va_end(list);
	result.erase(size);

	Fatal(result);		
}