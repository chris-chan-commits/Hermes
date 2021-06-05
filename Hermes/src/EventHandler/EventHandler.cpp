#include "EventHandler.h"

namespace Hermes {
	EventHandler::~EventHandler()
	{
		for (Event* event : m_Events)
		{
			delete event;
		}
	}

	void EventHandler::PushEvent(Event* event)
	{
		m_Events.push_back(event);
	}

	void EventHandler::PopEvent(Event* event)
	{
		m_Events.erase
		(
			std::remove(
				m_Events.begin(),
				m_Events.end(),
				event),
			m_Events.end()
		);
	}
}