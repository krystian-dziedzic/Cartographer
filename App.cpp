#include "App.h"

App::App()
{
	Init();
}

App::~App()
{
	glfwTerminate();
}

void App::Init()
{
	glfwInit();
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE, NULL, NULL);
	glfwSetFramebufferSizeCallback(window, window_size_callback);
}

void App::Run()
{
	while (window && !glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
}
