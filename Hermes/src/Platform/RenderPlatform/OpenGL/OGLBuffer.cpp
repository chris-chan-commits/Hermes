#include "OGLBuffer.h"

#include <glad/glad.h>

namespace Hermes
{
	/*- Vertex Buffer -*/
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

	/*- Index Buffer -*/

	OGLIndexBuffer::~OGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void OGLIndexBuffer::Initialize(uint32_t* data, size_t size)
	{
		m_Length = size / sizeof(uint32_t);
		
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	void OGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	uint32_t OGLIndexBuffer::GetLength()
	{
		return m_Length;
	}
}
