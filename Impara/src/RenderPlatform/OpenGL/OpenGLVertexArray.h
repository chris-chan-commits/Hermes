#pragma once

#include "Core/Core.h"
#include "Core/Graphics/Renderer/VertexArray.h"
#include <vector>

namespace Impara
{
	class IMPARA_API OGLVertexArray : public VertexArray
	{
	public:
		OGLVertexArray();
		virtual ~OGLVertexArray();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
		virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() { return m_VertexBuffers; }

		virtual void BindIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;
		virtual Ref<IndexBuffer> GetIndexBuffer() override;
		bool UsesIndexBuffers() override { return m_UsesIndexBuffers; }
	private:
		bool m_UsesIndexBuffers = false;
		Ref<IndexBuffer> m_IndexBuffer;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		uint32_t m_ID;
	};

}