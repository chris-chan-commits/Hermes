#include "OGLShader.h"
#include <vector>

#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#include "Logger/Logger.h"

#include <glad\glad.h>

static std::string _ReadFile(STRING filename)
{

	std::ifstream file(filename);

	if(!file.is_open())
	{
		Hermes::HERMES_ERROR("Error opening file %s for shader creation! ", filename);
	}

	std::string buffer;

	std::string line;
	while(std::getline(file, line))
	{
		buffer += line + "\n";
	}
	
	file.close();
	return buffer;
}

static std::vector<std::string> _SplitFile(std::string filecontents, std::string delim)
{
	
	std::vector<std::string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = filecontents.find(delim, prev);
		if (pos == std::string::npos) pos = filecontents.length();
		std::string token = filecontents.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < filecontents.length() && prev < filecontents.length());
	return tokens;
}

uint32_t _CompileShader(uint32_t type, STRING shaderCode)
{
	uint32_t shader = glCreateShader(type);

	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);

	INT compiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if(compiled != GL_TRUE)
	{
		int log_length = 0;
		char message[1024];
		glGetShaderInfoLog(shader, 1024, &log_length, message);

		Hermes::HERMES_ERROR("Failed to compile shaders! OpenGL error: %s", message);
	}

	return shader;
}

namespace Hermes
{
	// Public
	OGLShader::~OGLShader()
	{
		glDeleteShader(m_pID);
	}

	
	void OGLShader::Initialize(STRING shaderFilename)
	{
		std::string filecontents = _ReadFile(shaderFilename);

		std::vector<std::string> code = _SplitFile(filecontents, "#Shader_SPLIT");

		_CompileAndLinkShaders(code[0].c_str(), code[1].c_str());
	}

	void OGLShader::Bind()
	{
		glUseProgram(m_pID);
	}

	void OGLShader::Unbind()
	{
		glUseProgram(0);
	}

	void OGLShader::SetFloat(STRING name, const float& value)
	{
		int location = glGetUniformLocation(m_pID, name);
		if(location == -1)
		{
			HERMES_ERROR("Uniform %s does not exist.", name);
		}
		glUniform1f(location, value);
	}

	void OGLShader::SetVec2(STRING name, const vec2& vector)
	{
		int location = glGetUniformLocation(m_pID, name);
		if (location == -1)
		{
			HERMES_ERROR("Uniform %s does not exist.", name);
		}
		glUniform2f(location, vector.x, vector.y);
	}

	void OGLShader::SetVec3(STRING name, const vec3& vector)
	{
		int location = glGetUniformLocation(m_pID, name);
		if (location == -1)
		{
			HERMES_ERROR("Uniform %s does not exist.", name);
		}
		glUniform3f(location, vector.x, vector.y, vector.z);
	}

	void OGLShader::SetVec4(STRING name, const vec4& vector)
	{
		int location = glGetUniformLocation(m_pID, name);
		if (location == -1)
		{
			HERMES_ERROR("Uniform %s does not exist.", name);
		}
		glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
	}

	void OGLShader::SetMat4(STRING name, const mat4& matrix)
	{
		int location = glGetUniformLocation(m_pID, name);
		if (location == -1)
		{
			HERMES_ERROR("Uniform %s does not exist.", name);
		}
		glUniformMatrix4fv(location, 1, GL_FALSE, matrix.GetMatrix());
	}

	
	// Private
	void OGLShader::_CompileAndLinkShaders(STRING vShaderCode, STRING fShaderCode)
	{
		// Compile vertex and fragment shaders
		uint32_t vShader = _CompileShader(GL_VERTEX_SHADER, vShaderCode);
		uint32_t fShader = _CompileShader(GL_FRAGMENT_SHADER, fShaderCode);

		// Create program and link
		m_pID = glCreateProgram();

		glAttachShader(m_pID, vShader);
		glAttachShader(m_pID, fShader);

		glUseProgram(m_pID);
		glLinkProgram(m_pID);
		// Validate
		glValidateProgram(m_pID);

		// Check link
		INT linked = 0;
		glGetProgramiv(m_pID, GL_LINK_STATUS, &linked);
		if (linked != GL_TRUE)
		{
			int log_length = 0;
			char message[1024];
			glGetProgramInfoLog(m_pID, 1024, &log_length, message);

			Hermes::HERMES_ERROR("Failed to link shaders! OpenGL error: %s", message);
		}

		glUseProgram(0);
	}

}
