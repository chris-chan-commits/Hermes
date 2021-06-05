#include "OGLBuffer.h"

#define GLEW_STATIC
#include <gl\glew.h>

namespace Hermes
{
	void OGLVertexBuffer::Initialize(const BufferLayout& layout, float* data, size_t size)
	{
		m_Layout = layout;

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
}