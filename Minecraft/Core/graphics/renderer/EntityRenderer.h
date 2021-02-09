#pragma once

#include "shaders/entities/EntityShader.h"
class EntityRenderer
{
public:
	EntityRenderer(EntityShader* shader)
		: m_Shader(shader) {}
private:
	EntityShader* m_Shader;
};

