#include <iostream>

#include "function/render/RenderModule.h"

namespace LearnOpenGL
{
	RenderModule::RenderModule()
	{
		int vertexSize = 4;
		vertices = new Vertex[vertexSize] {
			{ {0.5f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {2.0f, 2.0f} },
			{ {0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {2.0f, 0.0f} },
			{ {-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f} },
			{ {-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 0.0f}, {0.0f, 2.0f} },
		};
		int indexSize = 6;
		indices = new unsigned int[indexSize] {
			0, 1, 2,	// 第一个三角形
			2, 3, 0,	// 第二个三角形
		};

		// 0. 初始化VAO/VBO/EBO
		glGenBuffers(1, &VBO);
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &EBO);
		// 1. 绑定VAO
		glBindVertexArray(VAO);
		// 2. 把顶点数组复制到缓冲中，供OpenGL使用
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(Vertex), vertices, GL_STATIC_DRAW);
		// 3. 复制索引数组到一个索引缓冲中，供OpenGL使用
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
		// 4. 设置顶点属性指针
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(Vector3)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	// 如果要unbind EBO，需要先unbind VAO

		mShader = new Shader("shader/VertexShader.glsl", "shader/FragmentShader.glsl");
		mTexture1 = new Texture("asset/container.jpg", GL_RGB);
		mTexture2 = new Texture("asset/awesomeface.png", GL_RGBA);
	}

	RenderModule::~RenderModule()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		delete mShader;
		delete mTexture1, mTexture2;
		delete vertices;
	}

	void RenderModule::render()
	{
		mShader->use();
		mShader->setInt("mTexture1", 0);
		mShader->setInt("mTexture2", 1);
		float timeValue = glfwGetTime();
		float delta = sin(timeValue) / 2 + 0.5f;
		mShader->setFloat("delta", delta);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mTexture1->textureID);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, mTexture2->textureID);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}
