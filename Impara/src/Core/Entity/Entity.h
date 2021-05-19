#pragma once

#include "Core/DLL.h"
#include "Core/Graphics/Renderer/Mesh.h"
#include "Core/Graphics/Renderer/Texture.h"
#include <optional>

namespace Impara
{
	enum class SPRITE2D
	{
		QUAD
	};

	struct IMPARA_API Camera
	{
		glm::mat4 proj;
		glm::mat4 view;

		static Camera& Get();
	};

	void IMPARA_API CreateOrthographicSceneCamera(float left, float right, float bottom, float top);
	void IMPARA_API CreateOrthographicSceneCamera(float left, float right, float bottom, float top, const glm::mat4& view);

	struct IMPARA_API Entity
	{
		Ref<Mesh> mesh;
		glm::mat4 pos = {};
		std::optional<Ref<Texture>> texture;

		static Ref<Entity> CreateEntity2DDefault(const SPRITE2D& spriteType, Ref<Texture> tex);

		void Render();
	};
}