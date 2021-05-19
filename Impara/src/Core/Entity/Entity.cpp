#include "Entity.h"

#include <glm/gtx/projection.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>

namespace Impara
{
	Ref<Entity> Entity::CreateEntity2DDefault(const SPRITE2D& spriteType, Ref<Texture> tex)
	{
		Ref<Entity> entity = CreateRef<Entity>();

		switch (spriteType)
		{
		case SPRITE2D::QUAD: {
			std::vector<float> vertices = {
0.5f,  0.5f, 0.0f,  // top right
0.5f, -0.5f, 0.0f,  // bottom right
-0.5f, -0.5f, 0.0f,  // bottom left
-0.5f,  0.5f, 0.0f   // top left 
			};
			std::vector<uint32_t> indices = {  // note that we start from 0!
				0, 1, 3,   // first triangle
				1, 2, 3    // second triangle
			};
			float uv[] = {
				1.0f, 1.0f, //0
				1.0f, -1.0f, //1
				-1.0f, -1.0f, //2
				-1.0f, 1.0f, //3
			};

			entity->mesh = Mesh::CreateMesh(vertices, indices, "main_shader_2d_textured.shader");
			entity->pos = glm::mat4(1.0f);

			entity->texture = tex;

			Ref<VertexBuffer> uvBuf = VertexBuffer::CreateVertexBuffer(uv, sizeof(uv));
			BufferLayout layout;
			layout.index = 1;
			layout.size = 2;
			uvBuf->SetLayout(layout);
			entity->mesh->vao->AddVertexBuffer(uvBuf);

			return entity;
		}break;
		default: {
			exit(-1);
		}
		}
	}
	void Entity::Render()
	{
		if (texture)
		{
			(*texture)->Bind();
		}
		mesh->shader->SetMat4("u_Proj", Camera::Get().proj);
		mesh->shader->SetMat4("u_View", Camera::Get().view);
		mesh->shader->SetMat4("u_Model", pos);

		mesh->Render();

		if (texture)
		{
			(*texture)->Unbind();
		}
	}
	Camera& Camera::Get()
	{
		static Camera instance;

		return instance;
	}
	void IMPARA_API CreateOrthographicSceneCamera(float left, float right, float bottom, float top)
	{
		Camera::Get().proj = glm::ortho(left, right, bottom, top);
		Camera::Get().view = glm::mat4(1.0f);
	}
	void IMPARA_API CreateOrthographicSceneCamera(float left, float right, float bottom, float top, const glm::mat4& view)
	{
		Camera::Get().proj = glm::ortho(left, right, bottom, top);
		Camera::Get().view = view;
	}
}