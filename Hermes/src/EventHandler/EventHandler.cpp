#include "EventHandler.h"

namespace Hermes {
	EventHandler::~EventHandler()
	{
		for (Event* event : m_Events)
		{
			delete event;
		}
	}

	VOID EventHandler::PushEvent(Event* event)
	{
		m_Events.push_back(event);
	}

	VOID EventHandler::PopEvent(Event* event)
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