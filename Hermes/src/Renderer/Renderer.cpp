#include "Renderer.h"

#define GLEW_STATIC
#include <gl\glew.h>

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
					if (GLEW_OK != glewInit())
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
}