#pragma once

#include "Core\Core.h"
#include "Renderer/Texture.h"

namespace beye
{
	class OGLTexture : public Texture
	{
	public:
		OGLTexture(const std::string& filename);
		virtual ~OGLTexture();

		virtual void Bind() override;
		virtual void Unbind() override;
	private:
		uint32_t m_ID;
		unsigned char* m_Data;
	};
}