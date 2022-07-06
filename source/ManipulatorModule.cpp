#include <algorithm>
#include "consts.h"
#include "ManipulatorModule.h"

ManipulatorModule::ManipulatorModule()
{
}

void ManipulatorModule::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void ManipulatorModule::setWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	glfwSetWindowSize(window, std::min(WINDOW_MAX_WIDTH, width), std::min(WINDOW_MAX_HEIGHT, height));
}

void ManipulatorModule::setFramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
