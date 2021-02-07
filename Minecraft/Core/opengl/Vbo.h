#pragma once

class Vbo
{
public:
	Vbo(unsigned int);
	~Vbo();

	void BindVbo();
	void StoreDataInVbo(float[]);
	void StoreDataInVbo(int[]);
	void UnBindVbo();
private:
	unsigned int m_ID;
	unsigned int m_Target;
};

