#include "OpenGLTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#define GLEW_STATIC
#include <GL/glew.h>

namespace beye
{
	OGLTexture::OGLTexture(const std::string& filename)
	{
		stbi_set_flip_vertically_on_load(1);
		int nrChannels;
		int width, height;
		m_Data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 4);

		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	OGLTexture::~OGLTexture()
	{
		glDeleteTextures(1, &m_ID);
	}
	void OGLTexture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}
	void OGLTexture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}