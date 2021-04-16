#include <iostream>
#include <string>


// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>

using namespace std;

class Screen
{
public:
	int height, width;
};

class GlWindow
{
	GLuint width, height;
	GLFWwindow *window;
	string name;
	Screen screen;
	int left, right;
	int versionMin, versionMaj;

public:
	GlWindow(string name, GLuint width = 800, GLuint height = 600, int vMj = 3, int vMn = 3, int left = 0, int right = 0)
	{
		this->width = width;
		this->height = height;
		this->name = name;
		this->left = left;
		this->right = right;
		this->versionMaj = vMj;
		this->versionMin = vMn;
		
	}
	void setupGLFW(int vMj, int vMn)
	{
		glfwInit();
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, vMj );
    	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, vMn );
    	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    	glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
    	this->window = glfwCreateWindow( this->width, this->height, this->name.c_str(), nullptr, nullptr );
    	glfwGetFramebufferSize(this->window, &this->screen.width, &this->screen.height);
	}

	bool checkAndRun()
	{
		setupGLFW(versionMaj, versionMin);
		if(!validCheck())
			return false;
		setContext();
	 	glewExperimental = GL_TRUE;
	 	if(GLEW_OK != glewInit())
	    {
	    	cout << "Failed to Init GLEW" << std::endl;
	        return false;
	    }
	    return true;

	}

	Screen getWindowSize()
	{
		return this->screen;
	}

	bool validCheck()
	{
		if(this->window == nullptr)
		{
		  	glfwTerminate( );
		  	return false;
		}
		return true;
	}

	void setContext()
	{
		glfwMakeContextCurrent(this->window);	
	}

	void setViewport()
	{
		glViewport(this->left, this->right, this->screen.width, this->screen.height);
	}
	bool alive()
	{
		return !glfwWindowShouldClose(this->window);
	}
	GLFWwindow * getWindow()
	{
		return this->window;
	}

	void setColor(float r, float g, float b, float a)
	{
		glfwPollEvents();
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	void kill()
	{
		glfwTerminate();
	}

};




int main()
{
	GlWindow window("Aviral");
	window.checkAndRun();
	while(window.alive())
	{
		
		window.setColor(0.1f, 0.1f, 0.1f, 1.0);
	}
    window.kill();
}