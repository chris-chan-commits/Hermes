#pragma once

#include "Core/Core.h"
#include "Buffer.h"
#include <vector>

namespace beye
{
	class BLIND_EYE_API VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		static Ref<VertexArray> CreateVertexArray();

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		// ALWAYS MAKE THE FIRST VERTEX BUFFER THE VERTICES!!!!!
		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
		// ALWAYS MAKE THE FIRST VERTEX BUFFER THE VERTICES!!!!!
		virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() = 0;

		virtual void BindIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;
		virtual Ref<IndexBuffer> GetIndexBuffer() = 0;
		virtual bool UsesIndexBuffers() = 0;
	};
}