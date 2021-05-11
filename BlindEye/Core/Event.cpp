#include "Event.h"

#include "Renderer/Renderer.h"

namespace beye
{
	Event::Event(const std::string& eventName) :
		m_EventName(eventName)
	{
	}
	#ifdef BE_PLATFORM_WINDOWS
	Win32WindowResizeEvent::Win32WindowResizeEvent(Ref<Window> window):
		Event("win32resizeevent")
	{
		m_Window = std::static_pointer_cast<Win32Window>(window);
	}
	Win32WindowResizeEvent::~Win32WindowResizeEvent()
	{
	}
	void Win32WindowResizeEvent::OnAttach()
	{
		GLFWwindow* handle = m_Window->GetWindowHandle();

		auto callback = [](GLFWwindow * window, int width, int height)
		{
			Renderer::Resize(width, height);
		};

		glfwSetWindowSizeCallback(handle, callback);
	}
	void Win32WindowResizeEvent::OnDetach()
	{
	}
	void Win32WindowResizeEvent::OnUpdate()
	{
	}
	#endif
}