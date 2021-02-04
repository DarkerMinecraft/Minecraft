#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() 
{

	glfwInit();

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); 
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(300, 300, "Hello World!", NULL, NULL);

	glfwMakeContextCurrent(window);
	
	glfwSwapInterval(1);

	glfwShowWindow(window);

	while (!glfwWindowShouldClose(window)) 
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}