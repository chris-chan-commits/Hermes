#include "Event.h"

#include "Logger/Logger.h"

namespace Hermes {
	/*- Event Interface -*/
	Event::Event(STRING name)
	{
		HERMES_TRACE("Initializing event %s...", name);
	}

	/*- Resize Event -*/
	OnWindowResize::OnWindowResize() :
		Event("OnWindowResize")
	{

	}

	OnWindowResize::~OnWindowResize()
	{
	}

	void OnWindowResize::OnEvent()
	{

	}
}