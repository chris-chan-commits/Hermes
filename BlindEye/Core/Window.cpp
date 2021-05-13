#include "Window.h"


namespace beye
{
	#ifdef BE_PLATFORM_WINDOWS
	bool Win32Window::Closing()
	{
		return glfwWindowShouldClose(m_WindowHandle);
	}
	void Win32Window::Initialize(int width, int height, const std::string& title, bool vsync)
	{
		if (!glfwInit())
		{
			BE_CORE_ERROR("There was an error initializing glfw!");
			throw std::runtime_error("");
			return;
		}

		m_WindowHandle = glfwCreateWindow
		(
			width, height,
			title.c_str(),
			nullptr, nullptr
		);

		if (!m_WindowHandle)
		{
			BE_CORE_ERROR("Failed to create window!");
			throw std::runtime_error("");
			return;
		}

		glfwMakeContextCurrent(m_WindowHandle);

		glfwShowWindow(m_WindowHandle);

		if (vsync)
		{
			glfwSwapInterval(0);
		}
		else
		{
			glfwSwapInterval(1);
		}
	}

	void Win32Window::Poll()
	{
		glfwSwapBuffers(m_WindowHandle);
		glfwPollEvents();
	}
	#endif
}
