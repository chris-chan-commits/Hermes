#pragma once

#include "Core.h"
#include "Buffer.h"
#include <vector>

namespace Hermes
{
	class HERMES_API VertexArray
	{
	public:
		virtual ~VertexArray()=default;

		virtual void Initialize() = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void AddVertexBuffer(Ref<VertexBuffer>& buffer) = 0;
		virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() = 0;
	};
}