#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ResourceModule
{
	public:
		ResourceModule();

		~ResourceModule();

	private:
		float *vertices;

		unsigned int VBO;
};