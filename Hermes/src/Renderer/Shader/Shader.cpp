#include "Shader.h"

#include "Platform/RenderPlatform/OpenGL/OGLShader.h"
#include "renderer/Renderer.h"

namespace Hermes
{
	Ref<Shader> Shader::CreateShader()
	{
		switch(LowLevelRenderer::Get().GetAPI())
		{
			case RendererApi::OpenGL:
				{
					return CreateRef<OGLShader>();
				}break;
			default:
				{

				}break;
		}
	}
}
