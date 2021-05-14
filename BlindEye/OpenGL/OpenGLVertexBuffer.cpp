#include "OpenGLVertexBuffer.h"
namespace beye
{
	OGLVertexBuffer::OGLVertexBuffer(float* vertices, GLsizeiptr size)
	{
		m_Count = (size / sizeof(GLsizeiptr)) / 3;
		glGenBuffers(1, &m_ID);
		
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		Unbind();
	}

	OGLVertexBuffer::~OGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}
	void OGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}
	void OGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	int OGLVertexBuffer::GetCount()
	{
		return m_Count;
	}
}