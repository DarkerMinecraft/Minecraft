#include <glad/glad.h>
#include "Graphics/DisplayManager.h"
#include "opengl/Vao.h"
#include "shaders/ShaderProgram.h"
#include "glad/glad.h"

int main() {
	DisplayManager* display = new DisplayManager();

	display->DisplayCreate();

	float positions[] = 
	{
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	Vao* vao = new Vao();
	vao->BindVao(-1);
	vao->StoreDataInAttributeList(positions, 0, 3);
	vao->UnBindVao(-1);

	ShaderProgram* shader = new ShaderProgram("Core/shaders/vertexShader.glsl", "Core/shaders/fragmentShader.glsl");

	while (display->DisplayRunning())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 0.3f, 0.3f, 0.3f);
		
		display->DisplayUpdate();
	}
	display->DisplayDestroy();
}