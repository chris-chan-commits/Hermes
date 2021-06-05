#pragma once

#include "Core.h"
#include "Vector/mat.h"

namespace Hermes
{
	class HERMES_API Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Initialize(STRING shaderFilename) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static Ref<Shader> CreateShader();

		virtual void SetFloat(STRING name, const float& value) = 0;
		virtual void SetVec2(STRING name, const vec2& vector) = 0;
		virtual void SetVec3(STRING name, const vec3& vector) = 0;
		virtual void SetVec4(STRING name, const vec4& vector) = 0;
		virtual void SetMat4(STRING name, const mat4& matrix) = 0;
	};
}
