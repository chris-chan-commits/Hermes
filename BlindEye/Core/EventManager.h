#pragma once

#include "Core.h"
#include "Event.h"
#include <vector>

namespace beye
{
	class BLIND_EYE_API EventManager
	{
	public:
		EventManager() = default;
		~EventManager();

		std::vector<Event*> GetEvents() { return m_Events; }

		void PushEvent(Event* event);
		void PopEvent(Event* event);
	private:
		std::vector<Event*> m_Events;
	};
}