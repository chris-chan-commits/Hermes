#pragma once

#include "Core/Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"

namespace beye
{
	enum class SPRITE
	{
		QUAD,
		TRIANGLE,
		CIRCLE
	};
	template <typename T>
	struct BLIND_EYE_API MaterialSlot
	{
		std::string name;
		T value;
	};
	struct BLIND_EYE_API Mat2D
	{
		MaterialSlot<glm::vec3> color;
	};
	struct BLIND_EYE_API Mesh
	{
		uint32_t meshID;
		Ref<VertexArray> vao;
		Ref<Shader> shader;
		glm::mat4 transformation;

		static Ref<Mesh> Create2DMesh(const SPRITE& sprite, const Mat2D& mat);
		static Ref<Mesh> Create3DMesh();

		void BindMaterial(const Mat2D& mat);
		void Render();
	};
	
	struct Material
	{

	};
}