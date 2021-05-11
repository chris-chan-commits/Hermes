#include "Texture.h"

#include "Renderer.h"
#include "OpenGL/OpenGLTexture.h"

namespace beye
{
	Ref<Texture> Texture::CreateTexture(const std::string& filename)
	{
		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
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
