#pragma once
#include <iostream>

class ShaderProgram
{
public:
	ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	~ShaderProgram();

	void Start();
	void Stop();

private:
	unsigned int m_ProgramID, m_VertexShader, m_FragmentShader;
private:
	unsigned int CreateShader(const std::string& file, unsigned int type);
};

