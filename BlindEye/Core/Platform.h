#pragma once

#ifdef _WIN32
	#ifdef _WIN64
		#define BE_PLATFORM_WINDOWS
	#else
		#error ONLY SUPPORTS x64
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
#error APPLE IS NOT SUPPORTED
#elif defined(__linux__)
#error LINUX NOT SUPPORTED
#endif