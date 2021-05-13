#include "Buffer.h"

#include "Renderer.h"

#include "OpenGL\OpenGLVertexBuffer.h"
#include "OpenGL/OpenGLIndexBuffer.h"

namespace beye
{
	Ref<VertexBuffer> VertexBuffer::CreateVertexBuffer(float* vertices, GLsizeiptr size)
	{
		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				return CreateRef<OGLVertexBuffer, float*, GLsizeiptr>((float*)vertices, (GLsizeiptr)size);
			}break;
		default:
			{
				BE_CORE_ERROR("Unable to create vertex buffer! Reason: Only supports OpenGL!");
				BE_CORE_PAUSE();

				std::exit(-1);
			}break;
		}
	}
	Ref<IndexBuffer> IndexBuffer::CreateIndexBuffer(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				return CreateRef<OGLIndexBuffer, uint32_t*, uint32_t>((uint32_t*)indices, (uint32_t)size);
			}break;
		default:
			{
				BE_CORE_ERROR("Unable to create index buffer! Reason: Only supports OpenGL!");
				BE_CORE_PAUSE();

				std::exit(-1);
			}break;
		}
	}
}