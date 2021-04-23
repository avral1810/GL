#include <iostream>
#include <string>
#include <vector>

// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include<GLUT/GLUT.h>

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"

void colorChanginDisplay(Display& window)
{
	std::vector<float> colors(4, 0.1f);
	long counter = 0;
	float mul = 0.1f;
	while(window.alive())
	{
		if (counter % 10 == 0)
		{
			for(int i = 0; i < 4; i++)
			{
				colors[i] =  colors[i] + mul;

				if (colors[i] > 1.0f || colors[i] < 0.0f)
				{
					mul *= -1;
					
				}
				std::cout<<colors[i]<<" ";
			}
			std::cout<<std::endl;
			counter = 0;
		}
		window.clear(colors[0], colors[1], colors[2], colors[3]);
		window.swapBuffers();
		counter++;
	}
    window.kill();
}


void triangle(Display& window, Shader& shader)
{
	GLfloat vertices[] =
    {
        // Positions         // Colors
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Left
        0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top
    };
    GLuint VBO, VAO;
    glGenVertexArrays( 1, &VAO );
    glGenBuffers( 1, &VBO );
    glBindVertexArray( VAO );
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    glBindVertexArray( 0 );
 	while (window.alive())
	{
		window.clear(0.1, 0.1, 0.1, 1.0);
		shader.bind();
		glBindVertexArray( VAO );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray( 0 );
		window.swapBuffers();
	}
	glDeleteVertexArrays( 1, &VAO );
    glDeleteBuffers( 1, &VBO );
}

int main()
{
	int width, height;
	Display display("Aviral", 800, 600);
	Shader shader("Shaders/core1.vs", "Shaders/core1.fs", true); 
	Vertex vertices[] =
    {
        //Positions          					// Colors           				// Texture Coords
        Vertex(	//top
        	glm::vec3(0.0f,  -0.5f, 0.0f),			
        	glm::vec3(1.0f, 0.0f, 0.0f),
        	glm::vec2(0.0f, 0.0f)), 
        Vertex(//bottom left
        	glm::vec3(-1.0f, -1.0f, 1.0f),
        	glm::vec3(0.0f, 1.0f, 0.0f),
        	glm::vec2(1.0f, 0.0f)), 
        Vertex(//bottom right
        	glm::vec3(1.0f, -1.0f, 0.0f),
        	glm::vec3(0.0f, 0.0f, 1.0f),
        	glm::vec2(0.0f, 0.0f))
    };
 	Texture texture("Texture-Images/bricks.png");
	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
	while(display.alive())
	{
		display.clear(1.0, 1.0, 1.0, 0.5);
		shader.bind();
		texture.bind(0);
		mesh.draw();
		display.swapBuffers();
	}
	
}