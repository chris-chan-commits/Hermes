#pragma once

#include "types.h"

#ifdef _WIN32
#define HERMES_PLATFORM_WINDOWS

	#ifdef HERMES_BUILD_DLL
	#define HERMES_API __declspec(dllexport)
	#else
	#define HERMES_API __declspec(dllimport)
	#endif

#elif __linux__
#define HERMES_API
#define HERMES_PLATFORM_LINUX

#elif APPLE
#define HERMES_API
#define HERMES_PLATFORM_MAC
#endif

#include <intrin.h>

#define debugbreak() __debugbreak()

#define ASSERTIONS_ENABLED

#include <iostream>
#ifdef ASSERTIONS_ENABLED
#define ASSERT(X) if(X){}else\
{\
std::cerr << "Assertion error! Expression: " << #X << ", " << "on line " __LINE__ << " in file " << __FILE__ << std::endl;\
debugbreak();\
}
#endif

namespace Hermes
{
	template <typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}