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

		inline RendererApi GetAPI() { return m_Api; }
		
		void Initialize(const RendererApi& api);

		void BeginRender() const;
		
		void RenderVertexArray(const Ref<VertexArray>& array);
	private:
		RendererApi m_Api;
	};
}