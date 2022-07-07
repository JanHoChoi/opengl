#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "consts.h"
#include "utils.h"
#include "ManipulatorModule.h"
#include "ResourceModule.h"
#include "RenderModule.h"

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	ManipulatorModule mManipulatorModule;
	glfwSetWindowSizeCallback(window, mManipulatorModule.setWindowSizeCallback);
	glfwSetFramebufferSizeCallback(window, mManipulatorModule.setFramebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	ResourceModule mResourceModule;
	RenderModule mRenderModule;

	while (!glfwWindowShouldClose(window))
	{
		mManipulatorModule.processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		mRenderModule.render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

