#pragma once

#include "Core.h"
#include "types.h"
#include <map>

namespace Hermes{
	INTERFACE IWindow
	{
	public:
		IWindow() = default;
		virtual ~IWindow() = default;

		virtual VOID Initialize(INT width, INT height, STRING title) = 0;
		virtual VOID Update() = 0;
		virtual B00L ShouldClose() = 0;
	};
}