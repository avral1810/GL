#include "mesh.h"

Mesh:: Mesh(Vertex *vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;	//Num of vertices we want to draw

	glGenVertexArrays(1, &m_vertexArrayObject);															//Generate A vertex array: size, where
	glBindVertexArray(m_vertexArrayObject);																// Bind so that changes to array happens to this array

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);													//Create a block of mem: of size, where
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);									//Bind this buffer so changes happens: type, where

	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);  		//Put it in Buffer memory: what data, size, pointer to start, 
																										//Where to put it

	glEnableVertexAttribArray(0);																		//Intrepet data,
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //Start, How many, type, normalize, skips for next one, begining
	glBindVertexArray(0);																				//Remove all ref to Vertex array, detach
}

void Mesh:: draw()
{
	glBindVertexArray(m_vertexArrayObject);									
	glDrawArrays(GL_TRIANGLES,0, m_drawCount);													//Draw: Start, and how far away
	glBindVertexArray(0);									//Unbind									
}


Mesh:: ~Mesh()
{
	glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}