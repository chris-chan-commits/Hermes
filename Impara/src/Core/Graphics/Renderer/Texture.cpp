#include "Texture.h"

#include "Renderer.h"
#include "RenderPlatform\OpenGL\OpenGLTexture.h"

namespace Impara
{
	Ref<Texture> Texture::CreateTexture(const std::string& filename)
	{
		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				Ref<OGLTexture> tex = CreateRef<OGLTexture, const std::string&>(filename);
				
				return tex;
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to create texture! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}break;
		}
	}
}
