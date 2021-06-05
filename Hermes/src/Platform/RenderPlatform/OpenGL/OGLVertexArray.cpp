#include "OGLVertexArray.h"

#include <glad/glad.h>

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
		buffer->Bind();
		const BufferLayout layout = buffer->GetLayout();
		glEnableVertexAttribArray(layout.index);

		glVertexAttribPointer(layout.index, layout.size, GL_FLOAT, GL_FALSE, NULL, nullptr);

		//glDrawArrays(GL_TRIANGLES, 0, buffer->GetLength());
		
		glDisableVertexAttribArray(layout.index);
		buffer->Unbind();


		m_VertexBuffers.push_back(buffer);
	}
	
	std::vector<Ref<VertexBuffer>> OGLVertexArray::GetVertexBuffers()
	{
		return m_VertexBuffers;
	}

	void OGLVertexArray::Render()
	{
		for(auto bufs : m_VertexBuffers)
		{
			glEnableVertexAttribArray(bufs->GetLayout().index);
		}

		glDrawArrays(GL_TRIANGLES, 0, m_VertexBuffers[0]->GetLength());
		
		for (auto bufs : m_VertexBuffers)
		{
			glDisableVertexAttribArray(bufs->GetLayout().index);
		}
	}

}
