#pragma once

#include "Core\Core.h"

namespace beye
{
	struct BufferLayout
	{
		uint32_t size;
		int index;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		static Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetLayout(const BufferLayout& layout) { m_Layout = layout; }
		virtual const BufferLayout& GetLayout() { return m_Layout; }
	private:
		BufferLayout m_Layout;
	};

	class BLIND_EYE_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		static Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t size);

		virtual uint32_t GetCount() = 0;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}