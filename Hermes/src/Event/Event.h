#pragma once

#include "Core.h"
#include "types.h"

namespace Hermes {
	INTERFACE Event
	{
	public:
		Event(STRING name);
		virtual ~Event() = default;

		virtual VOID OnEvent() = 0;
	};

	CLASS OnWindowResize : public Event
	{
	public:
		OnWindowResize();
		virtual ~OnWindowResize();

		virtual VOID OnEvent() override;
	};
}