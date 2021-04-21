#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>

#include <iostream>
#include <string>
#include <fstream>


class Shader
{

	static const unsigned int NUM_SHADERS = 2;
	static const unsigned int NUM_UNIFORMS = 3;
	
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

	std:: string loadShader(const std::string &filename);
	GLuint createShader(const std::string& text, unsigned int type);
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

public:
	Shader(const std::string &filename);
	Shader(const std::string &vs, const std::string &fs, bool file);
	void bind();
	virtual ~Shader();
};

#endif