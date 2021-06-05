#pragma once

#include "Core.h"
#include "Array/VertexArray.h"

namespace Hermes {
	enum class RendererApi
	{
		OpenGL
	};

	class HERMES_API LowLevelRenderer // Singleton
	{
	public:
		static LowLevelRenderer& Get() { static LowLevelRenderer instance; return instance; }

		void Initialize(const RendererApi& api);
		
		//void RenderVertexArray(VertexArray& array);
	private:
		RendererApi m_Api;
	};
}