#include "Win32Window.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

namespace Impara
{
	void Win32Window::Initialize(int width, int height, const std::string& name)
	{
		ASSERT(glfwInit(), "There was an error initializing the win32window! Reason: glfw failed to initialize!");
		
		m_WindowHandle = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		
		// Will change this later, since there will be more than opengl for apis
		glfwMakeContextCurrent(m_WindowHandle);

		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(m_WindowHandle, true);
	}
	void Win32Window::Update()
	{
		glfwSwapBuffers(m_WindowHandle);
		glfwPollEvents();
	}
}