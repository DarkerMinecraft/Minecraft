#include <glad/glad.h>
#include "Graphics/DisplayManager.h"
#include "opengl/Vao.h"
#include "shaders/entities/EntityShader.h"
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
	vao->StoreDataInAttributeList(positions, 0, 2);
	vao->UnBindVao(-1);

	EntityShader* shader = new EntityShader();

	while (display->DisplayRunning())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 0.3f, 0.3f, 0.3f);
		
		vao->BindVao(0);
		shader->Start();
		glDrawArrays(GL_TRIANGLES, 0, sizeof(positions));
		shader->Stop();
		vao->UnBindVao(0);

		display->DisplayUpdate();
	}
	display->DisplayDestroy();
}