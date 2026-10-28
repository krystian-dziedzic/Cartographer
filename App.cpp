#include "App.h"
#include <math.h>
App::App()
{
	Init();
}

App::~App()
{
	glfwTerminate();
}

int App::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE, NULL, NULL);
	if (!window)
	{
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(window);
		window = nullptr;
		return -1;
	}

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
		glClearColor(sin(glfwGetTime()) * 0.5f + 0.5f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
