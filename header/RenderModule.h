#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class RenderModule
{
public:
	RenderModule();
	~RenderModule();
	void render();

private:
	float* vertices;
	unsigned int* indices;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	Shader* mShader;
};