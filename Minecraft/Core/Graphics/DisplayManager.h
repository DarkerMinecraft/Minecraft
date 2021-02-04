#pragma once

#include <GLFW/glfw3.h>

class DisplayManager
{
public:
	void DisplayCreate();
	void DisplayUpdate();
	void DisplayDestroy();

	bool DisplayRunning();
private:
	GLFWwindow* m_Window;

};

