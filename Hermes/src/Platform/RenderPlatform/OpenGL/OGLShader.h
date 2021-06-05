#pragma once

#include "Renderer/Shader/Shader.h"

namespace Hermes
{
	class HERMES_API OGLShader : public Shader
	{
	public:
		virtual ~OGLShader();

		virtual void Initialize(STRING shaderFilename) override;

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void SetFloat(STRING name, const float& value) override;
		virtual void SetVec2(STRING name, const vec2& vector) override;
		virtual void SetVec3(STRING name, const vec3& vector) override;
		virtual void SetVec4(STRING name, const vec4& vector) override;
		virtual void SetMat4(STRING name, const mat4& matrix) override;
	private:
		uint32_t m_pID;
	private:
		void _CompileAndLinkShaders(STRING vShaderCode, STRING fShaderCode);
	};
}