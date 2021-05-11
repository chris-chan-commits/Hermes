#include "EventManager.h"

namespace beye
{
	EventManager::~EventManager()
	{
		for (Event* event : m_Events)
		{
			event->OnDetach();

			delete event;
		}
	}
	void EventManager::PushEvent(Event* event)
	{
		event->OnAttach();

		m_Events.push_back(event);
	}

	void EventManager::PopEvent(Event* event)
	{
		event->OnDetach();

		m_Events.erase(std::remove
		(
			m_Events.begin(),
			m_Events.end(),
			event
		),
			m_Events.end()
		);
	}
}
