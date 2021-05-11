#pragma once

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include "Core/Core.h"

namespace beye
{
	struct BLIND_EYE_API Camera
	{
		glm::mat4 projection;
		glm::mat4 view;

		static Ref<Camera> CreateOrthographicCamera(float left, float right, float bottom, float top);
		static Ref<Camera> CreatePerspectiveCamera(float fov, float width, float height, float near, float far);
	};
}