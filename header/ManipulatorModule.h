#pragma once

#include <GLFW/glfw3.h>

class ManipulatorModule
{
public:
	ManipulatorModule();
	void processInput(GLFWwindow*);
	static void setWindowSizeCallback(GLFWwindow* window, int width, int height);
	static void setFramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
