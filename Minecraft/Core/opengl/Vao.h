#pragma once
class Vao
{
public:
	Vao();
	~Vao();

	void BindVao(int);
	void StoreDataInAttributeList(float[], int, int);
	void BindIndicesBuffer(int[]);
	void UnBindVao(int);
private:
	unsigned int m_ID;
};

