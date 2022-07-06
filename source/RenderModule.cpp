#include "RenderModule.h"

RenderModule::RenderModule()
{
	
}

RenderModule::~RenderModule()
{

}

void RenderModule::render()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}