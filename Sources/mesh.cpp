#include "mesh.h"

Mesh:: Mesh(Vertex *vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;	//Num of vertices we want to draw

	glGenVertexArrays(1, &m_vertexArrayObject);															//Generate A vertex array: size, where
	glBindVertexArray(m_vertexArrayObject);																// Bind so that changes to array happens to this array


	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec2> textures;


	positions.reserve(numVertices);
	colors.reserve(numVertices);
	textures.reserve(numVertices);

	for(unsigned int i = 0; i < numVertices; i++)
	{
		positions.push_back(*vertices[i].getPos());
		colors.push_back(*vertices[i].getColor());
		textures.push_back(*vertices[i].getTexture());
	}	

	// std::cout<<positions<<std::endl;
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);													//Create a block of mem: of size, where
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);									//Bind this buffer so changes happens: type, where
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);  		//Put it in Buffer memory: what data, size, pointer to start, 
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
																					
 	
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);													
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[COLOR_VB]);									
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(colors[0]), &colors[0], GL_STATIC_DRAW);  		
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0,  0);
	glEnableVertexAttribArray(1);				
	
		

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);									
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXT_VB]);									
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(textures[0]), &textures[0], GL_STATIC_DRAW);  		
	glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, 0,  0);
	glEnableVertexAttribArray(2);				
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