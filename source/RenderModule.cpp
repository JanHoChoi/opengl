#include "RenderModule.h"
#include <iostream>

RenderModule::RenderModule()
{
	int vertexSize = 18;
	vertices = new float[vertexSize]{
		// λ��				// ��ɫ
		0.0f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	// �Ͻ�
		-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,	// ���½�
		0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	// ���½�
	};
	int indexSize = 3;
	indices = new unsigned int[indexSize]{
		0, 1, 2, // ��һ��������
	};

	// 0. ��ʼ��VAO/VBO/EBO
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	// 1. ��VAO
	glBindVertexArray(VAO);
	// 2. �Ѷ������鸴�Ƶ������У���OpenGLʹ��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);
	// 3. �����������鵽һ�����������У���OpenGLʹ��
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	// 4. ���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	// ���Ҫunbind EBO����Ҫ��unbind VAO

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
