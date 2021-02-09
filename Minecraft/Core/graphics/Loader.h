#pragma once
#include <graphics/models/RawModel.h>
class Loader
{
public:
	static RawModel* LoadToVao(float positions[], int indices[]);
};

