#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_decompose.hpp>
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
	void Renderer::BeginRender()
	{
		switch (s_API)
		{
		case API::OPENGL:
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				//glClearColor(0, 1, 0.5, 1.0);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to begin render! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
	void Renderer::Render(const Ref<VertexArray>& array)
	{
		array->Bind();
		for (auto vb : array->GetVertexBuffers())
		{
			glEnableVertexAttribArray(vb->GetLayout().index);
		}
		array->GetIndexBuffer()->Bind();
		glDrawElements(GL_TRIANGLES, array->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, NULL);
		array->GetIndexBuffer()->Unbind();
		for (auto vb : array->GetVertexBuffers())
		{
			glDisableVertexAttribArray(vb->GetLayout().index);
		}
		array->Unbind();
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
	void Renderer::EnableWireframe()
	{
		switch (s_API)
		{
		case API::OPENGL:
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to enable wireframe! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
	void Renderer::DisableWireframe()
	{
		switch (s_API)
		{
		case API::OPENGL:
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to disable wireframe! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
}