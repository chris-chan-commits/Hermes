#pragma once

#include <iostream>
#include <stdio.h>
#include <conio.h>

#define PAUSE() std::cout << "Press any key to continue..." << std::endl; _getch()
#define ASSERT(expr, msg) if(!expr){std::cout << msg << std::endl; PAUSE(); exit(-1); } 

#ifdef _DEBUG

#define BE_CORE_LOG(X) std::cout << X << std::endl;
#define BE_CORE_INFO(X) std::cout << "INFO: " << X << std::endl;
#define BE_CORE_WARN(X) std::cout << "WARNING: " << X << std::endl;
#define BE_CORE_ERROR(X) std::cout << "FATAL: " << X << std::endl;
#define BE_CORE_PAUSE() std::cout << "Press enter to continue..." << std::endl; std::cin.get();

#define BE_LOG(X) std::cout << "Application: " << X << std::endl;
#define BE_INFO(X) std::cout << "Application: " << "INFO: " << X << std::endl;
#define BE_WARN(X) std::cout << "Application: " << "WARNING: " << X << std::endl;
#define BE_ERROR(X) std::cout << "Application: " << "FATAL: " << X << std::endl;
#define BE_PAUSE() std::cout << "Application: " << "Press enter to continue..." << std::endl; std::cin.get();
#else
#define BE_CORE_LOG(X)
#define BE_CORE_INFO(X)
#define BE_CORE_WARN(X)
#define BE_CORE_ERROR(X)
#define BE_CORE_PAUSE() std::cout << "Press enter to continue..." << std::endl; std::cin.get();

#define BE_LOG(X)
#define BE_INFO(X)
#define BE_WARN(X)
#define BE_ERROR(X)
#define BE_PAUSE() std::cout << "Application: " << "Press enter to continue..." << std::endl; std::cin.get();
#endif

namespace Impara
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