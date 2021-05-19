#pragma once

#include "Core/Core.h"
#include "Core/DLL.h"

#define GLEW_STATIC
#include <GL\glew.h>

#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

namespace Impara
{
	enum class API
	{
		OPENGL
	};

	class IMPARA_API Renderer
	{
	public:
		static void Initialize(const API& api);
		static API GetAPI() { return s_Api; }
		static void DrawVertexArray(Ref<VertexArray> vao);
		static void DrawVertexArrayElements(Ref<VertexArray> vao);
	private:
		static API s_Api;
	};
}