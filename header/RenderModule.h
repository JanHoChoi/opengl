#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderModule
{
	public:
		RenderModule();
		~RenderModule();
		void render();

	private:
		float* vertices;
		unsigned int* indices;
		char* vertexShaderSource;
		char* fragmentShaderSource;
		unsigned int vertexShader;
		unsigned int fragmentShader;
		unsigned int shaderProgram;
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
		bool checkShaderCompileSuccess(unsigned int);
		bool checkShaderLinkSuccess(unsigned int);
};