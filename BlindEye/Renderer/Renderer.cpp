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
				glEnable(GL_MULTISAMPLE);
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
		glm::mat4 mvp = s_Camera->projection;
		mvp *= s_Camera->view;
		mvp *= mesh->model;
		mesh->shader->SetMat4("u_MVP", mvp);
		mesh->shader->Bind();
		switch (s_API)
		{
		case API::OPENGL:
			{
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_BLEND);
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
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_BLEND);
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
				glEnable(GL_CULL_FACE);
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
				glDisable(GL_CULL_FACE);
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