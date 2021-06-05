#pragma once

#include "Core.h"

namespace Hermes
{
	struct HERMES_API BufferLayout
	{
		uint32_t index, size;
	};
	
	class HERMES_API VertexBuffer
	{
	public:
		VertexBuffer() = default;
		virtual ~VertexBuffer() = default;

		virtual void Initialize(const BufferLayout& layout, float* data, size_t size) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual BufferLayout GetLayout() = 0;
	};
}