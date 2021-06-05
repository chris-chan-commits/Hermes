#include "VertexArray.h"

#include "Platform/RenderPlatform/OpenGL/OGLVertexArray.h"

#include "Renderer/Renderer.h"

namespace Hermes
{
	Ref<VertexArray> VertexArray::CreateVertexArray()
	{
		switch (LowLevelRenderer::Get().GetAPI())
		{
			case RendererApi::OpenGL:
				{
					return CreateRef<OGLVertexArray>();
				}break;
			default:
				{

				}break;
		}
	}
}