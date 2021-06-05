#include "OGLBuffer.h"

#include <glad/glad.h>

namespace Hermes
{
	void OGLVertexBuffer::Initialize(const BufferLayout& layout, float* data, size_t size)
	{
		m_Layout = layout;

		m_Length = (size / sizeof(float)) / layout.size;

		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	BufferLayout OGLVertexBuffer::GetLayout()
	{
		return m_Layout;
	}
	void OGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void OGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	uint32_t OGLVertexBuffer::GetLength()
	{
		return m_Length;
	}

}