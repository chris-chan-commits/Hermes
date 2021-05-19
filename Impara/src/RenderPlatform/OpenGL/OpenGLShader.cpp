#include "OpenGLShader.h"
#include <fstream>
#include <sstream>

#define GLEW_STATIC
#include <GL\glew.h>

#include <glm/gtc/type_ptr.hpp>

namespace Impara
{
	OGLShader::OGLShader(const std::string& filename)
	{
		std::string filecontents = _ReadFile(filename);
		std::vector<std::string> shadersSource = _SplitFile(filecontents, ".SplitShader");

		// Compile both of the shaders into an ID
		uint32_t vertexShader = _CompileShader(shadersSource[0], GL_VERTEX_SHADER);
		uint32_t fragmentShader = _CompileShader(shadersSource[1], GL_FRAGMENT_SHADER);

		// Link the program
		m_ID = _LinkIntoProgram(vertexShader, fragmentShader);
	}

	OGLShader::~OGLShader()
	{
		glDeleteProgram(m_ID);
	}


	void OGLShader::Bind()
	{
		glUseProgram(m_ID);
	}

	void OGLShader::Unbind()
	{
		glUseProgram(0);
	}

	void OGLShader::SetInt(const std::string& name, int value)
	{
		Bind();
		glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
		Unbind();
	}

	void OGLShader::SetIntArray(const std::string& name, int* value, uint32_t count)
	{
		Bind();
		glUniform1iv(glGetUniformLocation(m_ID, name.c_str()), count, value);
		Unbind();
	}

	void OGLShader::SetFloat(const std::string& name, float value)
	{
		Bind();
		glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
		Unbind();
	}

	void OGLShader::SetFloat2(const std::string& name, const glm::vec2& value)
	{
		Bind();
		glUniform2fv(glGetUniformLocation(m_ID, name.c_str()), 1, glm::value_ptr(value));
		Unbind();
	}

	void OGLShader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		Bind();
		glUniform3fv(glGetUniformLocation(m_ID, name.c_str()), 1, glm::value_ptr(value));
		Unbind();
	}

	void OGLShader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		Bind();
		glUniform4fv(glGetUniformLocation(m_ID, name.c_str()), 1, glm::value_ptr(value));
		Unbind();
	}

	void OGLShader::SetMat4(const std::string& name, const glm::mat4& value)
	{
		Bind();
		glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		Unbind();
	}


	std::string OGLShader::_ReadFile(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			BE_CORE_ERROR("Failed to create shader! Reason: Cannot open shader filepath!");
			BE_CORE_PAUSE();
			return NULL;
		}
	
		std::string buffer = "";

		std::string line;
		while (std::getline(file, line))
		{
			buffer += line += '\n';
		}


		file.close();

		return buffer;
	}
	std::vector<std::string> OGLShader::_SplitFile(const std::string& filecontents, const std::string& delim)
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
	uint32_t OGLShader::_CompileShader(const std::string& source, uint32_t type)
	{
		uint32_t id = glCreateShader(type);
		const char* src = source.c_str();
		
		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		int shaderCompiled;
		glGetShaderiv(id, GL_COMPILE_STATUS, &shaderCompiled);
		if (shaderCompiled != GL_TRUE)
		{
			int logLength = 0;
			char message[1024];
			glGetShaderInfoLog(id, 1024, &logLength, message);
			BE_CORE_ERROR("There was an error compiling shaders:");
			BE_CORE_ERROR(message);
			BE_CORE_PAUSE();
			
			
			std::exit(-1);
		}

		return id;
	}
	uint32_t OGLShader::_LinkIntoProgram(uint32_t vertexShader, uint32_t fragmentShader)
	{
		uint32_t program = glCreateProgram();

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		int programLinked;
		glGetProgramiv(program, GL_LINK_STATUS, &programLinked);
		if (programLinked != GL_TRUE)
		{
			int logLength = 0;
			char message[1024];
			glGetProgramInfoLog(program, 1024, &logLength, message);
			BE_CORE_ERROR("There was an error linking shader program:");
			BE_CORE_ERROR(message);
			BE_CORE_PAUSE();
			
			
			std::exit(-1);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return program;
	}
}