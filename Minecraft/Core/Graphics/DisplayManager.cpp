#include "DisplayManager.h"
#include <glad/glad.h>

void DisplayManager::DisplayCreate()
{
	glfwInit();

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	m_Window = glfwCreateWindow(1280, 720, "Hello World!", NULL, NULL);

	glfwMakeContextCurrent(m_Window);

	glfwSwapInterval(1);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glfwShowWindow(m_Window);
}

void DisplayManager::DisplayUpdate()
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void DisplayManager::DisplayDestroy()
{
	glfwTerminate();
}

bool DisplayManager::DisplayRunning()
{
	return !glfwWindowShouldClose(m_Window);
}
