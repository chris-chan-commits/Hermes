#pragma once

#include <iostream>
#include "Core/Core.h"
#define GLEW_STATIC
#include <gl\glew.h>

#include "Core/Graphics/Renderer/Buffer.h"

namespace Impara
{
	class IMPARA_API OGLVertexBuffer : public VertexBuffer
	{
	public:
		OGLVertexBuffer(float* vertices, GLsizeiptr size);
		virtual ~OGLVertexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;
		virtual int GetCount() override;
	private:
		int m_Count = 0;
		uint32_t m_ID;
	};
}
