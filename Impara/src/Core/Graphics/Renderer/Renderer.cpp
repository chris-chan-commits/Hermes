#include "Renderer.h"

namespace Impara
{
	API Renderer::s_Api;
	void Renderer::Initialize(const API& api)
	{
		s_Api = api;
		
		switch (s_Api)
		{
		case API::OPENGL: 
		{
			ASSERT(glewInit() == GLEW_OK, "glew failed to init");
		}break;
		default: ASSERT(5 == 2, "Only opengl supported!"); break;
		}
	}
	void Renderer::DrawVertexArray(Ref<VertexArray> vao)
	{
		vao->Bind();
		glDrawArrays(GL_TRIANGLES, 0, vao->GetVertexBuffers()[0]->GetCount());
		vao->Unbind();
	}
	void Renderer::DrawVertexArrayElements(Ref<VertexArray> vao)
	{
		vao->Bind();
		vao->GetIndexBuffer()->Bind();

		for (auto vb : vao->GetVertexBuffers())
		{
			glEnableVertexAttribArray(vb->GetLayout().index);
		}

		glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, NULL);
		
		for (auto vb : vao->GetVertexBuffers())
		{
			glDisableVertexAttribArray(vb->GetLayout().index);
		}
		
		vao->GetIndexBuffer()->Unbind();
		vao->Unbind(); 
	}
}