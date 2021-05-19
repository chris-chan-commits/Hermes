#include "VertexArray.h"

#include "Renderer.h"
#include "RenderPlatform\OpenGL\OpenGLVertexArray.h"

namespace Impara
{
	Ref<VertexArray> VertexArray::CreateVertexArray()
	{
		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				return CreateRef<OGLVertexArray>();
			}break;
		default:
			{
				BE_CORE_ERROR("Unable to create veretx array! Reason: Only supports OpenGL!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
}