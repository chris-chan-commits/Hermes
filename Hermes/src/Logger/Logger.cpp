#include "Logger.h"

#include <cstdarg>
#include <conio.h>

#ifdef HERMES_PLATFORM_WINDOWS
#include <Windows.h>
#endif

static void _CoreLog(STRING prepend, STRING message, va_list args)
{
	vprintf(((std::string(prepend) +message) + "\n").c_str(), args);
}

namespace Hermes {
	void Logger::Trace(STRING message, ...)
	{
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		#endif
		va_list args;
		va_start(args, message);
		_CoreLog("[Trace]: ", message, args);
		va_end(args);
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		#endif
	}

	void Logger::Info(STRING message, ...)
	{
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		#endif
		va_list args;
		va_start(args, message);
		_CoreLog("[Info]: ", message, args);
		va_end(args);
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		#endif
	}

	void Logger::Error(STRING message, ...)
	{
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		#endif
		va_list args;
		va_start(args, message);
		_CoreLog("[Error]: ", message, args);
		va_end(args);
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		#endif
	}

	void Logger::Fatal(STRING message, ...)
	{
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		#endif
		va_list args;
		va_start(args, message);
		_CoreLog("[Fatal]: ", message, args);
		va_end(args);

		// Wait for user input
		printf("Press any key to continue...\n");
		_getch();

		// Then close
		std::exit(-1);
		#ifdef HERMES_PLATFORM_WINDOWS
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		#endif
	}
}