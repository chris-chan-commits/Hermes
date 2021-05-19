#include "Mesh.h"

namespace Impara
{
	Ref<Mesh> Mesh::CreateMesh(std::vector<float> vertices, std::vector<uint32_t> indices, const std::string& shaderFilename)
	{
		Ref<Mesh> mesh = CreateRef<Mesh>();
		
		/*---Vertices and indices-*/
		float* verticesData = (float*)vertices.data();
		size_t verticesSize = vertices.size() * sizeof(float);

		uint32_t* indicesData = (uint32_t*)indices.data();
		size_t indicesSize = indices.size() * sizeof(uint32_t);

		// The vertex array for the mesh.
		Ref<VertexArray> vao = VertexArray::CreateVertexArray();
		Ref<VertexBuffer> vbo = VertexBuffer::CreateVertexBuffer(verticesData, verticesSize);
		Ref<IndexBuffer> ibo = IndexBuffer::CreateIndexBuffer(indicesData, indicesSize);
		BufferLayout vboLayout = {};
		vboLayout.index = 0;
		vboLayout.size = 3;
		vbo->SetLayout(vboLayout);

		vao->AddVertexBuffer(vbo);
		vao->BindIndexBuffer(ibo);

		mesh->vao = vao;
		/*-Vertices and indices---*/
		/*---Shaders-*/
		mesh->shader = Shader::CreateShader(shaderFilename);
		/*-Shaders---*/

		return mesh;
	}
	void Mesh::Render()
	{
		shader->Bind();
		Renderer::DrawVertexArrayElements(vao);
		shader->Unbind();
	}
}