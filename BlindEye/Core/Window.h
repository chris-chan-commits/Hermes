#pragma once

#include <iostream>
#include "Core.h"
#ifdef BE_PLATFORM_WINDOWS
#include <GLFW\glfw3.h>
#endif

namespace beye
{
	class Event;

	class Window
	{
	public:
		Window() = default;
		virtual ~Window() {}

		virtual bool Closing() = 0 { return false; }
		virtual void Initialize(int width, int height, const std::string& title, bool vsync) = 0 {}
		virtual void Poll() = 0 {}
	};

	#ifdef BE_PLATFORM_WINDOWS
	class Win32Window : public Window
	{
	public:
		virtual bool Closing() override;
		virtual void Initialize(int width, int height, const std::string& title, bool vsync) override;
		virtual void Poll() override;

		GLFWwindow* GetWindowHandle() { return m_WindowHandle; }
	private:
		GLFWwindow* m_WindowHandle;
	};
	#else
	
	#endif
}