#include <glad/glad.h>
#include "Graphics/DisplayManager.h"

int main() {
	DisplayManager* display = new DisplayManager();

	display->DisplayCreate();

	while (display->DisplayRunning())
	{
		display->DisplayUpdate();
	}
	display->DisplayDestroy();
}