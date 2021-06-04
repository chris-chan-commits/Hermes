#include "Windows32Window.h"
#include <glfw\glfw3.h>

#include "Logger/Logger.h"

namespace Hermes
{
	void Windows32Window::Initialize(INT width, INT height, STRING title, const RendererApi& api)
	{
		HERMES_TRACE("Initializing Windows32Window!");
		
		m_Width = width;
		m_Height = height;
		m_Title = title;
		switch(api)
		{
		case RendererApi::OpenGL:
			{
				_InitForOpenGL();
			}break;
		}
	}

	bool Windows32Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Handle);
	}

	void Windows32Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Handle);
	}



	void Windows32Window::_InitForOpenGL()
	{
		if (!glfwInit())
		{
			HERMES_FATAL("Failed to create Windows32Window because glfwInit() returned false!");
		}
		else
		{
			HERMES_INFO("GLFW initialization succeeded!");
		}

		m_Handle = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

		glfwMakeContextCurrent(m_Handle);
	}
}
