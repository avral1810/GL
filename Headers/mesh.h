#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>
#include <glm/glm.hpp>


#include <iostream>
#include <string>


class Vertex
{
	glm::vec3 pos;
public:
	Vertex(const glm::vec3 &pos)
	{
		this->pos = pos;
	}

};


class Mesh
{

	enum MeshBufferPositions
	{
		POSITION_VB,

		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
	
public:
	Mesh(Vertex *vertices, unsigned int numVertices);
	void draw();
	virtual ~Mesh();

};
#endif