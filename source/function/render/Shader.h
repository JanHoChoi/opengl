#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

namespace LearnOpenGL
{
	class Shader
	{
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void use() const;
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;

		unsigned int programID;
		unsigned int vertShader;
		unsigned int fragShader;

	private:
		bool checkShaderCompileSuccess(unsigned int);
		bool checkShaderLinkSuccess(unsigned int);
	};
}

#endif
