#include "OpenGLIndexBuffer.h"

#define GLEW_STATIC
#include <GL\glew.h>

namespace beye
{
	OGLIndexBuffer::OGLIndexBuffer(uint32_t* indices, uint32_t size)
	{
		glGenBuffers(1, &m_ID);

		m_Count = size / sizeof(size_t);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	OGLIndexBuffer::~OGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}
	uint32_t OGLIndexBuffer::GetCount()
	{
		return m_Count;
	}
	void OGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}
	void OGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}