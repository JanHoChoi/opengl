#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ResourceModule
{
	public:
		ResourceModule();
		~ResourceModule();
		unsigned int shaderProgram;
		float* vertices;
		unsigned int VBO;
		unsigned int VAO;

	private:
		char* vertexShaderSource;
		char* fragmentShaderSource;

		unsigned int vertexShader;
		unsigned int fragmentShader;

		bool checkShaderCompileSuccess(unsigned int);
		bool checkShaderLinkSuccess(unsigned int);
};