#pragma once

#include "Core.h"
#include "Window.h"

namespace beye
{
	class BLIND_EYE_API Event
	{
	public:
		Event(const std::string& eventName);
		virtual ~Event() = default;

		virtual void OnAttach() = 0 {}
		virtual void OnDetach() = 0 {}
		virtual void OnUpdate() = 0 {}
	private:
		std::string m_EventName;
	};

	#ifdef BE_PLATFORM_WINDOWS
	class BLIND_EYE_API Win32WindowResizeEvent : public Event
	{
	public:
		Win32WindowResizeEvent(Ref<Window> window);
		virtual ~Win32WindowResizeEvent();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
	private:
		Ref<Win32Window> m_Window;
	};
	#endif

	class BLIND_EYE_API TimeUpdateEvent : public Event
	{
	public:
		TimeUpdateEvent();
		virtual ~TimeUpdateEvent();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;

	};
}

