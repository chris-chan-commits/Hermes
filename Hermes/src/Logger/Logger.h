#pragma once

#include "Core.h"
#include "types.h"

namespace Hermes {
	class HERMES_API Logger
	{
	public:
		static void Trace(STRING message, ...);
		static void Info(STRING message, ...);
		static void Error(STRING message, ...);
		static void Fatal(STRING message, ...);
	};

	/*- Defines -*/
	#define HERMES_TRACE(X, ...) Logger::Trace(X, __VA_ARGS__)
	#define HERMES_INFO(X, ...) Logger::Info(X, __VA_ARGS__)
	#define HERMES_ERROR(X, ...) Logger::Error(X, __VA_ARGS__)
	#define HERMES_FATAL(X, ...) Logger::Fatal(X, __VA_ARGS__)
}