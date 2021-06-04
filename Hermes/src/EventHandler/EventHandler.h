#pragma once

#include "Core.h"
#include "Event/Event.h"
#include <vector>

namespace Hermes {
	CLASS EventHandler
	{
	public:
		EventHandler()=default;
		~EventHandler();
	
		VOID PushEvent(Event* event);
		VOID PopEvent(Event* event);

	private:
		std::vector<Event*> m_Events;
	};
}