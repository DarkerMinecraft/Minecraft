#include "Vbo.h"
#include <glad/glad.h>

Vbo::Vbo(unsigned int target)
	: m_Target(target)
{
	glGenBuffers(1, &m_ID);
}

Vbo::~Vbo()
{
	glDeleteBuffers(1, &m_ID);
}

void Vbo::BindVbo()
{
	glBindBuffer(m_Target, m_ID);
}

void Vbo::StoreDataInVbo(float data[])
{
	int size = sizeof(data);
	glBufferData(m_Target, size * sizeof(float), data, GL_STATIC_DRAW);
}

void Vbo::StoreDataInVbo(int data[])
{
	int size = sizeof(data);
	glBufferData(m_Target, size * sizeof(int), data, GL_STATIC_DRAW);
}

void Vbo::UnBindVbo()
{
	glBindBuffer(m_Target, 0);
}
