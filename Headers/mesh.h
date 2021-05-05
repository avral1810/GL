#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>
#include <glm/glm.hpp>


#include <iostream>
#include <string>
#include <vector>

class Index
{
	unsigned int index;
public:
	Index(const unsigned int& index)
	{
		this->index = index;
	}
	inline unsigned int * getIndex(){ return &this->index; }
};

class Vertex
{
	glm::vec3 pos;
	glm::vec2 texture;
	glm::vec3 color;
public:
	Vertex(const glm::vec3 &pos, const glm::vec3 &color, const glm::vec2 &texture)
	{
		this->pos = pos;
		this->color = color;
		this->texture = texture;
		// std:: cout << "colors \n"<<this->color[0]<<" "<<this->color[1]<<" " << this->color[2] << "\n\n";
	}

	Vertex(const glm::vec3 &pos, const glm::vec3 &color)
	{
		this->pos = pos;
		this->color = color;
		this->texture[0] = -1;
		this->texture[1] = -1;
		// std:: cout << "colors \n"<<this->color[0]<<" "<<this->color[1]<<" " << this->color[2] << "\n\n";
	}
	
	inline glm::vec3 * getPos(){ return &this->pos; }
	inline glm::vec3 * getColor(){ return &this->color; }
	inline glm::vec2 * getTexture(){ return &this->texture; }
};


class Mesh
{

	enum MeshBufferPositions
	{
		POSITION_VB,
		COLOR_VB,
		TEXT_VB,

		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	GLuint m_elementBufferObject;
	unsigned int m_drawCount;
	
public:
	Mesh(Vertex *vertices, std::vector<Index> indicies, unsigned int numVertices);
	void draw();
	virtual ~Mesh();

};
#endif