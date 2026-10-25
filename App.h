#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920
#define APP_TITLE "TestTitle"

class App
{
private:
	GLFWwindow* window;
	static void window_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
public:
	App();
	~App();
	void Init();
	void Run();
};

