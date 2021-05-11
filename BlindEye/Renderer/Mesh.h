#pragma once

#include "Core/Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"

namespace beye
{
	struct BLIND_EYE_API Mesh
	{
	private:
		friend class Renderer;
		bool usesTexture = false;
	public:
		Ref<VertexArray> vao;
		Ref<Shader> shader;
		size_t points;
		glm::mat4 model;
		Ref<Texture> texture;

		static Ref<Mesh> CreateMesh(const std::string& objFilename, Ref<Shader> shader, std::vector<float>& texCoords);
		static Ref<Mesh> CreateMesh(const std::vector<float> vertices, Ref<Shader> shader);
		static Ref<Mesh> CreateMesh(const std::vector<float> vertices, const std::vector<uint32_t> indices, Ref<Shader> shader);

		void BindTextureCoordinates(const std::vector<float> texCoords);

		void BindTexture(Ref<Texture> texture, const std::vector<float> texCoords);
		void BindTexture(Ref<Texture> texture);
	};
}