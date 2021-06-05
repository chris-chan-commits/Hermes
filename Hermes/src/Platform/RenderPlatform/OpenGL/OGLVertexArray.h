#pragma once

#include "Renderer/Array/VertexArray.h"

#include "Platform/RenderPlatform/OpenGL/OGLBuffer.h"

namespace Hermes
{
	class HERMES_API OGLVertexArray : public VertexArray
	{
	public:
		virtual ~OGLVertexArray();

		virtual void Initialize() override;
		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void AddVertexBuffer(Ref<VertexBuffer>& buffer) override;
		virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() override;
	private:
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		uint32_t m_ID;
	};
}