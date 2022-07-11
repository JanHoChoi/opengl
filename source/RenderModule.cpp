#include "RenderModule.h"
#include <iostream>

RenderModule::RenderModule()
{
	int vertexSize = 32;
	vertices = new float[vertexSize]{
	//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
		0.5f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	2.0f, 2.0f,   // ����
		0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	2.0f, 0.0f,   // ����
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,   // ����
		-0.5f, 0.5f, 0.0f,		1.0f, 1.0f, 0.0f,	0.0f, 2.0f    // ����
	};
	int indexSize = 6;
	indices = new unsigned int[indexSize]{
		0, 1, 2,	// ��һ��������
		2, 3, 0,	// �ڶ���������
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	// ���Ҫunbind EBO����Ҫ��unbind VAO

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
