#include "OGLVertexArray.h"

#define GLEW_STATIC
#include <gl\glew.h>



namespace Hermes
{
	OGLVertexArray::~OGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);
	}
	void OGLVertexArray::Initialize()
	{
		glGenVertexArrays(1, &m_ID);
	}

	void OGLVertexArray::Bind()
	{
		glBindVertexArray(m_ID);
	}

	void OGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void OGLVertexArray::AddVertexBuffer(Ref<VertexBuffer>& buffer)
	{
		Ref<OGLVertexBuffer> openglVertexBuffer = std::dynamic_pointer_cast<OGLVertexBuffer>(buffer);
		
		openglVertexBuffer->Bind();
		const BufferLayout layout = openglVertexBuffer->GetLayout();
		glEnableVertexAttribArray(layout.index);
		glVertexAttribPointer(layout.index, layout.size, GL_FLOAT, GL_FALSE, 0, NULL);
		glDisableVertexAttribArray(layout.index);
		openglVertexBuffer->Unbind();


		m_VertexBuffers.push_back(openglVertexBuffer);
	}
	
	std::vector<Ref<VertexBuffer>> OGLVertexArray::GetVertexBuffers()
	{
		return m_VertexBuffers;
	}
}
