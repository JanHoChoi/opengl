#include "RenderModule.h"
#include <iostream>

RenderModule::RenderModule()
{
	int vertexSize = 18;
	vertices = new float[vertexSize]{
		// 位置				// 颜色
		0.0f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	// 上角
		-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,	// 左下角
		0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	// 右下角
	};
	int indexSize = 3;
	indices = new unsigned int[indexSize]{
		0, 1, 2, // 第一个三角形
	};

	// 0. 初始化VAO/VBO/EBO
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	// 1. 绑定VAO
	glBindVertexArray(VAO);
	// 2. 把顶点数组复制到缓冲中，供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);
	// 3. 复制索引数组到一个索引缓冲中，供OpenGL使用
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	// 4. 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	// 如果要unbind EBO，需要先unbind VAO

	mShader = new Shader("shader/VertexShader.glsl", "shader/FragmentShader.glsl");
}

RenderModule::~RenderModule()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	delete mShader;
}

void RenderModule::render()
{
	float timeValue = glfwGetTime();
	float horiOffset = sin(timeValue);	// [-1, 1]
	
	mShader->setFloat("horiOffset", horiOffset);
	mShader->use();

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}
