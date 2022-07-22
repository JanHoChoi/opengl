#pragma once

#ifndef RENDER_MODULE_H
#define RENDER_MODULE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "function/render/Shader.h"
#include "function/render/Texture.h"

namespace LearnOpenGL
{
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
		Texture* mTexture1;
		Texture* mTexture2;
	};
}

#endif
