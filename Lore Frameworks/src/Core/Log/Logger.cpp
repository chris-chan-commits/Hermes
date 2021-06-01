#include "Logger.h"

#include <stdarg.h>

static void _log(STRING prepend, STRING msg, va_list list)
{
	vprintf((std::string(prepend) + msg).c_str(), list);
}

namespace LoreFrameworks {
	void Logger::Info(STRING msg, ...)
	{
		va_list list;
		va_start(list, msg);
		_log("[INFO]: ", msg, list);
		va_end(list);
	}
	void Logger::Warn(STRING msg, ...)
	{
		va_list list;
		va_start(list, msg);
		_log("[WARN]: ", msg, list);
		va_end(list);
	}
	void Logger::Error(STRING msg, ...)
	{
		va_list list;
		va_start(list, msg);
		_log("[ERROR]: ", msg, list);
		va_end(list);
	}
	void Logger::Fatal(STRING msg, ...)
	{
		va_list list;
		va_start(list, msg);
		_log("[FATAL]: ", msg, list);
		va_end(list);

		getchar();
		exit(-1);
	}
}