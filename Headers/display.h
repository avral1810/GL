#ifndef DISPLAY_H
#define DISPLAY_H


// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>

#include <iostream>
#include <string>

class Display
{
	GLFWwindow * m_window;
	int screenHeight, screenWidth;

public:
	Display(const std::string& name, GLuint, GLuint height);
	void clear(float r, float g, float b, float a);
	void swapBuffers();
	void kill();
	bool alive();
	int getScreenWidth();
	int getScreenHeight();
	virtual ~Display();

};

#endif