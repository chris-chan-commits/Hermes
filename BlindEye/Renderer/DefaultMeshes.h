#pragma once

#include "Core/Core.h"
#include "Renderer/Mesh.h"

namespace beye
{
	Ref<Mesh> BLIND_EYE_API DefaultQuad();
	Ref<Mesh> BLIND_EYE_API Default3DObject(const std::string& objFilename, const std::string& textureFileName);
}