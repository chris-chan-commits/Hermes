#pragma once

#include "Core/Core.h"
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <string>

namespace beye
{
	class BLIND_EYE_API Shader
	{
	public:
		static Ref<Shader> CreateShader(const std::string& filename);

		virtual ~Shader()																	{}

		virtual void Bind()																= 0 {}
		virtual void Unbind()															= 0 {}

		virtual void SetInt(const std::string& name, int value)							= 0 {}
		virtual void SetIntArray(const std::string& name, int* value, uint32_t count)	= 0 {}
		virtual void SetFloat(const std::string& name, float value)						= 0 {}
		virtual void SetFloat2(const std::string& name, const glm::vec2& value)			= 0 {}
		virtual void SetFloat3(const std::string& name, const glm::vec3& value)			= 0 {}
		virtual void SetFloat4(const std::string& name, const glm::vec4& value)			= 0 {}
		virtual void SetMat4(const std::string& name, const glm::mat4& value)			= 0 {}
	};
}