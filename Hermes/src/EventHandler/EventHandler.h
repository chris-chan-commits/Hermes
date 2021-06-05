#pragma once

#include "Core.h"
#include "Event/Event.h"
#include <vector>

namespace Hermes {
	class HERMES_API EventHandler
	{
	public:
		EventHandler()=default;
		~EventHandler();
	
		void PushEvent(Event* event);
		void PopEvent(Event* event);

	private:
		std::vector<Event*> m_Events;
	};
}