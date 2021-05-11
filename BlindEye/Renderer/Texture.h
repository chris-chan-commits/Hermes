#pragma once

#include "Core/Core.h"
#include <string>

namespace beye
{
	class BLIND_EYE_API Texture
	{
	public:
		virtual ~Texture() = default;

		static Ref<Texture> CreateTexture(const std::string& filename);

		virtual void Bind() = 0 {}
		virtual void Unbind() = 0 {}
	};
}