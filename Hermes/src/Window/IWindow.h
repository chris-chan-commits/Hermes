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

		virtual void Initialize(INT width, INT height, STRING title, const RendererApi& api) = 0;
		virtual void Update() = 0;
		virtual bool ShouldClose() = 0;
	};
}