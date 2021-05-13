#pragma once

#include "Core/Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"

#define COLOR_SLOT "u_Color"

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
		// Set albedoColor to empty if you want a texture
		MaterialSlot<glm::vec3> albedoColor;
		// Set textureAlbedo to empty if you want a solid color
		Ref<Texture> textureAlbedo;
	};
	struct BLIND_EYE_API Mat3D
	{

	};
	struct BLIND_EYE_API Mesh
	{
		uint32_t meshID;
		Ref<VertexArray> vao;
		Ref<Shader> shader;
		glm::mat4 transformation;
		Ref<Texture> texture;
		bool usesTextures;

		static Ref<Mesh> Create2DMesh(const SPRITE& sprite, const Mat2D& mat);
		static Ref<Mesh> Create3DMesh();

		void BindMaterial(const Mat2D& mat);
		void Render();
	};
}