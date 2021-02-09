#include <glad/glad.h>
#include "graphics/DisplayManager.h"
#include "opengl/Vao.h"
#include "shaders/entities/EntityShader.h"
#include "graphics/Loader.h"

int main() {
	DisplayManager* display = new DisplayManager();

	display->DisplayCreate();

	float positions[] = 
	{
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f, 
		-0.5f, 0.5f
	};

	int indices[] = 
	{
		0, 1, 2, 
		2, 3, 0
	};

	RawModel* model = Loader::LoadToVao(positions, indices);

	EntityShader* shader = new EntityShader();

	while (display->DisplayRunning())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 0.3f, 0.3f, 0.3f);
		
		Vao* vao = model->GetVao();

		vao->BindVao(0);
		shader->Start();
		glDrawArrays(GL_TRIANGLES, 0, model->GetModelCount());
		shader->Stop();
		vao->UnBindVao(0);

		display->DisplayUpdate();
	}
	display->DisplayDestroy();
}