#pragma once

#include "Core/Core.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "Renderer.h"

namespace Impara
{

	struct IMPARA_API Mesh
	{
		Ref<Shader> shader;
		Ref<VertexArray> vao;
	
		static Ref<Mesh> CreateMesh(std::vector<float> vertices, std::vector<uint32_t> indices, const std::string& shaderFilename);

		void Render();
	};
}