#pragma once

#include "Core/Graphics/Window.h"

#include <GLFW/glfw3.h>
#include "Core/Core.h"

namespace Impara
{
	class IMPARA_API Win32Window : public Window
	{
	public:
		virtual void Initialize(int width, int height, const std::string& name) override;
		virtual void Update() override;
		virtual bool Closing() override { return glfwWindowShouldClose(m_WindowHandle); }
	private:
		GLFWwindow* m_WindowHandle = nullptr;
	};
}