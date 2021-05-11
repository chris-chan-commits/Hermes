#include "OpenGLVertexArray.h"

#define GLEW_STATIC
#include <GL\glew.h>

namespace beye
{
	OGLVertexArray::OGLVertexArray()
	{
		// We only want 1 vertex array
		glGenVertexArrays(1, &m_ID);
	}
	OGLVertexArray::~OGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);
	}
	void OGLVertexArray::Bind()
	{
		glBindVertexArray(m_ID);
	}
	void OGLVertexArray::Unbind()
	{
		// When 0 is passed, it binds a non existant vertex array, thus being unbound
		glBindVertexArray(0);
	}
	void OGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		Bind();
		vertexBuffer->Bind();
		glEnableVertexAttribArray(vertexBuffer->GetLayout().index);
		glVertexAttribPointer(vertexBuffer->GetLayout().index, vertexBuffer->GetLayout().size, GL_FLOAT, GL_FALSE, sizeof(float) * vertexBuffer->GetLayout().size, (const void*)0);
		glDisableVertexAttribArray(vertexBuffer->GetLayout().index);
		vertexBuffer->Unbind();
		Unbind();


		m_VertexBuffers.push_back(vertexBuffer);
	}
	void OGLVertexArray::BindIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		m_IndexBuffer = indexBuffer;
		m_UsesIndexBuffers = true;
	}
	Ref<IndexBuffer> OGLVertexArray::GetIndexBuffer()
	{
		return m_IndexBuffer;
	}
}