#include "Loader.h"

RawModel* Loader::LoadToVao(float positions[], int indices[])
{
	Vao* vao = new Vao();
	vao->BindVao(-1);
	vao->BindIndicesBuffer(indices);
	vao->StoreDataInAttributeList(positions, 0, 2);
	vao->UnBindVao(-1);

	return new RawModel(vao, sizeof(indices));
}
