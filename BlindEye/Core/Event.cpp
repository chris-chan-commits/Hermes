#include "Event.h"

#include "Renderer/Renderer.h"

#include <chrono>
#include "Time/Time.h"
namespace chrono = std::chrono;

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
	TimeUpdateEvent::TimeUpdateEvent():
		Event("Time Update Event")
	{
	}
	TimeUpdateEvent::~TimeUpdateEvent()
	{
	}

	static chrono::system_clock::time_point tp1;
	static chrono::system_clock::time_point tp2;

	void TimeUpdateEvent::OnAttach()
	{
		tp1 = chrono::system_clock::now();
		tp2 = chrono::system_clock::now();
	}
	void TimeUpdateEvent::OnDetach()
	{
	}
	void TimeUpdateEvent::OnUpdate()
	{
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedT = tp2 - tp1;
		tp1 = tp2;
		Time::deltaTime = elapsedT.count();
	}
}