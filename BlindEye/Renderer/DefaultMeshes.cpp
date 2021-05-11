#include "DefaultMeshes.h"

namespace beye
{
	Ref<Mesh> DefaultQuad()
	{
		std::vector<float> vertices =
		{
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};
		std::vector<uint32_t> indices =
		{
			0, 1, 3,
			1, 2, 3
		};
		std::vector<float> texCoords =
		{
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,
		};

		Ref<Shader> aShader = Shader::CreateShader("main_shader_textured.shader");

		auto mesh = Mesh::CreateMesh(vertices, indices, aShader);
		mesh->BindTextureCoordinates(texCoords);

		return mesh;
	}
}