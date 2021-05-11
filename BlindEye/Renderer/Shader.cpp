#include "Shader.h"

#include "Renderer.h"

#include "OpenGL\OpenGLShader.h"

namespace beye
{
	Ref<Shader> Shader::CreateShader(const std::string& filename)
	{
		Ref<Shader> shader;

		switch (Renderer::GetAPI())
		{
		case API::OPENGL:
			{
				shader = CreateRef<OGLShader, const std::string&>(filename);
				return shader;
			}break;
		default:
			{
				BE_CORE_ERROR("Failed to create shader! Reason: Only OpenGL is supported!");
				BE_CORE_PAUSE();
				std::exit(-1);
			}
		}
	}
}