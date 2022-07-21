#pragma once

#ifndef MANIPULATOR_MODULE_H
#define MANIPULATOR_MODULE_H

#include <GLFW/glfw3.h>

namespace LearnOpenGL
{
	class ManipulatorModule
	{
	public:
		ManipulatorModule();

		void processInput(GLFWwindow*);

		static void setWindowSizeCallback(GLFWwindow* window, int width, int height);
		static void setFramebufferSizeCallback(GLFWwindow* window, int width, int height);
	};
}

#endif
