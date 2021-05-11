#pragma once

#include <iostream>
#include "Core/Core.h"
#define GLEW_STATIC
#include <gl\glew.h>

#include "Renderer/Buffer.h"

namespace beye
{
	class BLIND_EYE_API OGLVertexBuffer : public VertexBuffer
	{
	public:
		OGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OGLVertexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;
	private:
		uint32_t m_ID;
	};
}
