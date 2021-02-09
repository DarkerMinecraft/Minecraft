#pragma once

#include <glm/glm.hpp>
class Vertex
{
public:
	Vertex(float x, float y, float z, float u, float v)
		: m_X(x), m_Y(y), m_Z(z), m_U(u), m_V(v) {}
	Vertex(glm::vec3 position, glm::vec2 textureCoords)
		: m_X(position.x), m_Y(position.y), m_Z(position.z), m_U(textureCoords.x), m_V(textureCoords.y) {}
	glm::vec3 GetVertexPosition() { return glm::vec3(m_X, m_Y, m_Z); }
	glm::vec2 GetTexturePosition() { return glm::vec2(m_U, m_V); }
private:
	float m_X, m_Y, m_Z;
	float m_U, m_V;
};

