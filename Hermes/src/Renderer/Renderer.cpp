#include "Renderer.h"

#include <glad/glad.h>

#include "Logger/Logger.h"

namespace Hermes
{
	void LowLevelRenderer::Initialize(const RendererApi& api)
	{
		m_Api = api;

		switch (m_Api)
		{
			case RendererApi::OpenGL:
				{
					if (!gladLoadGL())
					{
						HERMES_FATAL("GLEW failed to initialize!");
					}
					else
					{
						HERMES_INFO("GLEW initialized successfully!");
					}
				}break;
			default:
				{

				}break;
		}
	}

	void LowLevelRenderer::BeginRender() const
	{
		switch (m_Api)
		{
			case RendererApi::OpenGL:
				{
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				}break;
			default:
				{

				}break;
		}
	}

	void LowLevelRenderer::RenderVertexArray(const Ref<VertexArray>& array)
	{
		array->Render();
	}

}