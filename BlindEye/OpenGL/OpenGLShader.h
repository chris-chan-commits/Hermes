#pragma once

#include "Renderer/Shader.h"
#include <vector>

namespace beye
{
	class BLIND_EYE_API OGLShader : public Shader
	{
	public:
		OGLShader(const std::string& filename);
		virtual ~OGLShader();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void SetInt(const std::string& name, int value) override;
		virtual void SetIntArray(const std::string& name, int* value, uint32_t count) override;
		virtual void SetFloat(const std::string& name, float value) override;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) override;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) override;
	private:
		std::string _ReadFile(const std::string& filename);
		std::vector<std::string> _SplitFile(const std::string& filecontents, const std::string& delim);
		uint32_t _CompileShader(const std::string& source, uint32_t type);
		uint32_t _LinkIntoProgram(uint32_t vertexShader, uint32_t fragmentShader);
	private:
		uint32_t m_ID;
	};
}