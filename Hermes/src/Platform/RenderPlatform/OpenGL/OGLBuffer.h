#pragma once

#include "Renderer/Array/Buffer.h"

namespace Hermes
{
	class HERMES_API OGLVertexBuffer : public VertexBuffer
	{
	public:
		virtual void Initialize(const BufferLayout& layout, float* data, size_t size) override;
		
		virtual void Bind() override;
		virtual void Unbind() override;

		virtual BufferLayout GetLayout() override;

		virtual uint32_t GetLength() override;
	private:
		uint32_t m_Length;
		uint32_t m_ID;
		BufferLayout m_Layout;
	};

	class HERMES_API OGLIndexBuffer : public IndexBuffer
	{
	public:
		virtual ~OGLIndexBuffer();
		
		virtual void Initialize(uint32_t* data, size_t size) override;
		virtual void Bind() override;
		virtual void Unbind() override;

		virtual uint32_t GetLength() override;
	private:
		uint32_t m_ID;
		uint32_t m_Length;
	};
}