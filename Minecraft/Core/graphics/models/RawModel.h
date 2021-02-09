#pragma once

#include "opengl/Vao.h"
class RawModel
{
public:
	RawModel(Vao* vao, int modelCount)
		: m_Vao(vao), m_ModelCount(modelCount) {}

	inline int GetModelCount() { return m_ModelCount; }
	inline Vao* GetVao() { return m_Vao; }
private:
	Vao* m_Vao;
	int m_ModelCount;
};

