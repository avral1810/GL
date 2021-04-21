#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>


#include <iostream>
#include <string>

class Texture
{

	GLuint m_texture;

public:
	Texture(const std::string& filename);
	void bind(unsigned int uint);
	virtual ~Texture();
};

#endif