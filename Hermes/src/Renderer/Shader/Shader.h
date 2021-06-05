#pragma once

#include "Core.h"

namespace Hermes
{
	class HERMES_API Shader
	{
	public:
		virtual ~Shader()=0;

		virtual void Initialize(STRING shaderFilename) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}