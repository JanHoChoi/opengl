#include "Shader.h"

namespace LearnOpenGL
{
	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		std::string vertShaderCode;
		std::string fragShaderCode;

		std::ifstream vertShaderFile;
		std::ifstream fragShaderFile;
		try
		{
			vertShaderFile.open(vertPath, std::ios_base::in);
			fragShaderFile.open(fragPath, std::ios_base::in);
			std::stringstream vertShaderStream, fragShaderStream;
			vertShaderStream << vertShaderFile.rdbuf();
			fragShaderStream << fragShaderFile.rdbuf();
			vertShaderFile.close();
			fragShaderFile.close();
			vertShaderCode = vertShaderStream.str();
			fragShaderCode = fragShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}

		vertShader = glCreateShader(GL_VERTEX_SHADER);
		const char* vShaderCode = vertShaderCode.c_str();
		glShaderSource(vertShader, 1, &vShaderCode, NULL);
		glCompileShader(vertShader);
		checkShaderCompileSuccess(vertShader);

		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fShaderCode = fragShaderCode.c_str();
		glShaderSource(fragShader, 1, &fShaderCode, NULL);
		glCompileShader(fragShader);
		checkShaderCompileSuccess(fragShader);

		programID = glCreateProgram();
		glAttachShader(programID, vertShader);
		glAttachShader(programID, fragShader);
		glLinkProgram(programID);
		checkShaderLinkSuccess(programID);

		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(programID);
	}

	void Shader::use() const
	{
		glUseProgram(programID);
	}

	void Shader::setBool(const std::string& name, bool value) const
	{
		int location = glGetUniformLocation(programID, name.c_str());
		glUniform1i(location, value);
	}

	void Shader::setInt(const std::string& name, int value) const
	{
		int location = glGetUniformLocation(programID, name.c_str());
		glUniform1i(location, value);
	}

	void Shader::setFloat(const std::string& name, float value) const
	{
		int location = glGetUniformLocation(programID, name.c_str());
		glUniform1f(location, value);
	}

	bool Shader::checkShaderCompileSuccess(unsigned int shader)
	{
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			return false;
		}
		return true;
	}

	bool Shader::checkShaderLinkSuccess(unsigned int shaderProgram)
	{
		int success;
		char infoLog[512];

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
			return false;
		}
		return true;
	}
}

