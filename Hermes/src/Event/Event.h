#pragma once

#include "Core.h"
#include "types.h"

namespace Hermes {
	class HERMES_API Event
	{
	public:
		Event(STRING name);
		virtual ~Event() = default;

		virtual void OnEvent() = 0;
	};

	class HERMES_API OnWindowResize : public Event
	{
	public:
		OnWindowResize();
		virtual ~OnWindowResize();

		virtual void OnEvent() override;
	};
}