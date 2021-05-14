#include "Entity.h"

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_decompose.hpp>

static glm::vec3 ToPosition(const glm::mat4& transformation)
{
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, rotation, translation, skew, perspective);

	return translation;
}

namespace beye
{
	Entity::Entity(Ref<Mesh> mesh):
		m_Mesh(mesh)
	{
	}
	Entity::~Entity()
	{
	}
	void Entity::Translate(const glm::vec3& translation)
	{
		m_Mesh->transformation = glm::translate(m_Mesh->transformation, translation);
	}
	void Entity::Teleport(const glm::vec3& position)
	{

	}
}
