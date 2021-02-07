#include "ShaderProgram.h"

#include <glad/glad.h>
#include <fstream>
#include <string>

ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	m_ProgramID = glCreateProgram();
	m_VertexShader = CreateShader(vertexShaderFile, GL_VERTEX_SHADER);
	m_FragmentShader = CreateShader(fragmentShaderFile, GL_FRAGMENT_SHADER);

	glAttachShader(m_ProgramID, m_VertexShader);
	glAttachShader(m_ProgramID, m_FragmentShader);
	glLinkProgram(m_ProgramID);
	glValidateProgram(m_ProgramID);

	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragmentShader);
}

ShaderProgram::~ShaderProgram()
{
	Stop();
}

void ShaderProgram::Start()
{
	glUseProgram(m_ProgramID);
}

void ShaderProgram::Stop()
{
	glUseProgram(0);
}

unsigned int ShaderProgram::CreateShader(const std::string& file, unsigned int type)
{
	std::fstream infile;

	infile.open(file, std::fstream::in);
	std::string sourceCode;
	for (std::string line; std::getline(infile, line);)
	{
		sourceCode = sourceCode + line + "\n";
	}
	infile.close();

	const char* src = sourceCode.c_str();
	unsigned int id = glCreateShader(type);
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
		
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) 
	{
		int length; 
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char message[1024];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "FAILED TO COMPILE " << 
			(type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " SHADER!" << std::endl;
		std::cout << message << std::endl;
		exit(EXIT_FAILURE);
	}

	return id;
}
