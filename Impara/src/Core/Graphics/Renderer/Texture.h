#pragma once

#include "Core/DLL.h"
#include "Core/Core.h"
#include <string>

namespace Impara
{
	class IMPARA_API Texture
	{
	public:
		virtual ~Texture() = default;

		static Ref<Texture> CreateTexture(const std::string& filename);

		virtual void Bind() = 0 {}
		virtual void Unbind() = 0 {}
	};
}