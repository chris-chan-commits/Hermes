#pragma once

#include "Layer.h"

namespace Impara
{
	class Layer
	{
	public:
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnTick() = 0;
	};
}