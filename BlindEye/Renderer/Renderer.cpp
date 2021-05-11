#include "Renderer.h"

#define GLEW_STATIC
#include <GL\glew.h>

namespace beye
{
	/*-------DEBUGGING-*/
	/*-------OGL-*/
	void GLAPIENTRY
		MessageCallback(GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
	{
		fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
	}
	/*-OGL----*/
	/*-DEBUGGING-------*/

	API Renderer::s_API;
	Ref<Camera> Renderer::s_Camera;
	void Renderer::Initialize(const API& api)
	{
		s_API = api;

		switch (s_API)
		{
		case API::OPENGL:
			{
				if (glewInit() != GLEW_OK)
				{
					BE_CORE_ERROR("Failed to initialize renderer! Reason: GLEW failed to initialize!");
					BE_CORE_PAUSE();
					std::exit(-1);
				}
				// During init, enable debug output
				glEnable(GL_DEBUG_OUTPUT);
				glDebugMessageCallback(MessageCallback, 0);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to initialize renderer! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
	void Renderer::BeginRender(Ref<Camera> camera)
	{
		s_Camera = camera;
		switch (s_API)
		{
		case API::OPENGL:
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glClearColor(0, 1, 0.5, 1.0);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to begin render! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
	void Renderer::Render(const Ref<Mesh>& mesh)
	{
		mesh->shader->SetMat4("u_MVP", s_Camera->projection * s_Camera->view * mesh->model);
		mesh->shader->Bind();
		switch (s_API)
		{
		case API::OPENGL:
			{
				glEnable(GL_DEPTH_TEST);
				mesh->vao->Bind();
				if (mesh->usesTexture)
				{
					mesh->texture->Bind();
				}

				for (auto buf : mesh->vao->GetVertexBuffers())
				{
					glEnableVertexAttribArray(buf->GetLayout().index);
				}
				if (mesh->vao->UsesIndexBuffers())
				{
					mesh->vao->GetIndexBuffer()->Bind();
					glDrawElements(GL_TRIANGLES, mesh->vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, NULL);
					mesh->vao->GetIndexBuffer()->Unbind();
				}
				else
					glDrawArrays(GL_TRIANGLES, 0, mesh->points);
				for (auto buf : mesh->vao->GetVertexBuffers())
				{
					glDisableVertexAttribArray(buf->GetLayout().index);
				}
				if (mesh->usesTexture)
				{
					mesh->texture->Unbind();
				}
				mesh->vao->Unbind();
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to render! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
		mesh->shader->Unbind();
	}
	void Renderer::Resize(int width, int height)
	{
		switch (s_API)
		{
		case API::OPENGL:
			{
				glViewport(0, 0, width, height);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to resize renderer! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
	void Renderer::CullFace()
	{
		switch (s_API)
		{
		case API::OPENGL:
			{
				glCullFace(GL_FRONT_AND_BACK);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to cull faces! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
	void Renderer::NotCullFace()
	{
		switch (s_API)
		{
		case API::OPENGL:
			{
				glCullFace(GL_BACK);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to not cull faces! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
}