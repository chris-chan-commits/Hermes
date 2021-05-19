#pragma once

#include "Core/Core.h"
#include "Core/DLL.h"
#include "Core/Graphics/Renderer/Buffer.h"

namespace Impara
{
	class IMPARA_API OGLIndexBuffer : public IndexBuffer
	{
	public:
		OGLIndexBuffer(uint32_t* indices, GLsizeiptr size);
		virtual ~OGLIndexBuffer();

		virtual uint32_t GetCount() override;
		
		virtual void Bind() override;
		virtual void Unbind() override;
	private:
		uint32_t m_Count = 0;
		uint32_t m_ID = 0;
	};
}