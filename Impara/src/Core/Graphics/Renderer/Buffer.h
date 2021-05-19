#pragma once

#include "Core/DLL.h"
#include "Core/Core.h"

#define GLEW_STATIC
#include <GL\glew.h>

namespace Impara
{
	struct BufferLayout
	{
		uint32_t size;
		int index;
	};

	class IMPARA_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		static Ref<VertexBuffer> CreateVertexBuffer(float* vertices, GLsizeiptr size);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetLayout(const BufferLayout& layout) { m_Layout = layout; }
		virtual const BufferLayout& GetLayout() { return m_Layout; }
		virtual int GetCount() = 0;
	private:
		BufferLayout m_Layout;
	};

	class IMPARA_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		static Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t size);

		virtual uint32_t GetCount() = 0;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}