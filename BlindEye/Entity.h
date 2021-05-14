#pragma once

#include "Core\Core.h"
#include "Renderer/Mesh.h"

namespace beye
{
	class BLIND_EYE_API Entity
	{
	public:
		Entity(Ref<Mesh> mesh);
		~Entity();

		void Translate(const glm::vec3& translation);
		void Teleport(const glm::vec3& position);
	private:
		Ref<Mesh> m_Mesh;
	};
}