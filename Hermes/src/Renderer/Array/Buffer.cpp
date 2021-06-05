#include "Buffer.h"

#include "Renderer/Renderer.h"

#include "Platform/RenderPlatform/OpenGL/OGLBuffer.h"

namespace Hermes
{
	Ref<VertexBuffer> VertexBuffer::CreateVertexBuffer()
	{
		switch(LowLevelRenderer::Get().GetAPI())
		{
			case RendererApi::OpenGL:
				{
					return CreateRef<OGLVertexBuffer>();
				}break;
			default:
				{

				}break;
		}
	}

	Ref<IndexBuffer> IndexBuffer::CreateIndexBuffer()
	{
		switch(LowLevelRenderer::Get().GetAPI())
		{
			case RendererApi::OpenGL:
				{
					return CreateRef<OGLIndexBuffer>();
				}break;
			default:
				{

				}break;
		}
	}
}
