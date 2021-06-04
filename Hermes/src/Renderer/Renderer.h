#pragma once

#include "Core.h"

namespace Hermes {
	enum CLASS RendererApi
	{
		OpenGL=0x000a,
		Direct3D=0x000b, // Note: DirectX not supported
		Vulkan=0x000c, // Note: Vulkan not supported
	};

	CLASS Renderer
	{
	public:
		static VOID Initialize(const RendererApi& api);
	private:
		static RendererApi s_Api;
	};
}