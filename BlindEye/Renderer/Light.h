#pragma once

#include "Core/Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Mesh.h"

namespace beye
{
	struct BLIND_EYE_API Mesh;
	struct BLIND_EYE_API Light
	{
		Ref<Mesh> lightMesh;
		glm::vec3 lightColor;
	};
}