#include "display.h"

Display::Display(const std::string& name, GLuint width, GLuint height)
{
	glfwInit();
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
	m_window = glfwCreateWindow( width, height, name.c_str(), nullptr, nullptr );
	glfwGetFramebufferSize(m_window, &screenWidth, &screenHeight);
	if(m_window == nullptr)
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
	  	kill();
	}
	glfwMakeContextCurrent(m_window);	
	glewExperimental = GL_TRUE;
	 if ( GLEW_OK != glewInit())
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        kill();
    }
	glViewport(0, 0, screenWidth, screenHeight);

}

void Display:: clear(float r, float g, float b, float a)
{
	glfwPollEvents();
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
	swapBuffers();
}

void Display:: swapBuffers()
{
	glfwSwapBuffers(m_window);
}

void Display:: kill()
{
	glfwTerminate();
}

bool Display:: alive()
{
	return !glfwWindowShouldClose(m_window);
}

int Display:: getScreenHeight()
{
	return screenHeight;
}

int Display:: getScreenWidth()
{
	return screenWidth;
}

Display::~Display()
{
	kill();
}