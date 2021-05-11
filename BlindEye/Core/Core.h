#pragma once

#include <memory>
#include <iostream>
#include "Platform.h"
#define GLEW_STATIC
#include "GL\glew.h"

#ifdef BLIND_EYE_BUILD_DLL
#define BLIND_EYE_API __declspec(dllexport)
#else
#define BLIND_EYE_API __declspec(dllimport)
#endif

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

namespace beye
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