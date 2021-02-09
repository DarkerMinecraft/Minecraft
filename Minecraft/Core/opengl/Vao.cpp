#include "Vao.h"
#include <glad/glad.h>
#include <opengl/Vbo.h>

Vao::Vao()
{
	glGenVertexArrays(1, &m_ID);
}

Vao::~Vao()
{
	glDeleteVertexArrays(1, &m_ID);
}

void Vao::BindVao(int attrib)
{
	glBindVertexArray(m_ID);
	if (attrib != -1) 
	{
		for (int i = 0; i <= attrib; i++) 
			glEnableVertexArrayAttrib(m_ID, i);
	}
}

void Vao::StoreDataInAttributeList(float data[], int index, int size)
{
	Vbo* vbo = new Vbo (GL_ARRAY_BUFFER);
	vbo->BindVbo();
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(float) * size, 0);
	vbo->StoreDataInVbo(data);
	vbo->UnBindVbo();
}

void Vao::BindIndicesBuffer(int data[])
{
	Vbo* vbo = new Vbo(GL_ELEMENT_ARRAY_BUFFER);
	vbo->BindVbo();
	vbo->StoreDataInVbo(data);
}

void Vao::UnBindVao(int attrib)
{
	if (attrib != -1)
	{
		for (int i = 0; i <= attrib; i++)
			glEnableVertexArrayAttrib(m_ID, i);
	}
	glBindVertexArray(0);
}
