#pragma once

#include "Core\Core.h"
#include "Core/DLL.h"
#include "Core/Graphics/Renderer/Texture.h"

namespace Impara
{
	class IMPARA_API OGLTexture : public Texture
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