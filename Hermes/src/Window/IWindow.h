#pragma once

#include "Core.h"
#include "types.h"
#include <map>
#include "renderer/Renderer.h"

namespace Hermes{
	class HERMES_API IWindow
	{
	public:
		IWindow() = default;
		virtual ~IWindow() = default;

		virtual VOID Initialize(INT width, INT height, STRING title, const RendererApi& api) = 0;
		virtual VOID Update() = 0;
		virtual B00L ShouldClose() = 0;
	};
}