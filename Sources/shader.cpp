#include "shader.h"

Shader:: Shader(const std::string &filename)
{
	m_program = glCreateProgram();														//Create Shader program
	
	m_shaders[0] = createShader(loadShader(filename + ".vs"), GL_VERTEX_SHADER);		//Vertex Shader
	m_shaders[1] = createShader(loadShader(filename + ".fs"), GL_FRAGMENT_SHADER);		//Fragment Shader
	
	for(unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);										//Attach shader to program
	// glBindAttribLocation(m_program, 0, "position");
	// glBindAttribLocation(m_program, 1, "color");
   	glLinkProgram(m_program);															//Link Program to create shader
   	checkShaderError(m_program, GL_LINK_STATUS, true, "Error linking shader program");

   	glValidateProgram(m_program);														//Validate if shader is valid
   	checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Error validating shader program");
}

Shader:: Shader(const std::string &vs,const std::string &fs, bool file = true)
{
	m_program = glCreateProgram();												//Create Shader program
	if (file)
	{
		m_shaders[0] = createShader(loadShader(vs), GL_VERTEX_SHADER);	
		m_shaders[1] = createShader(loadShader(fs), GL_FRAGMENT_SHADER);
	}
	else
	{
		m_shaders[0] = createShader(vs, GL_VERTEX_SHADER);
		m_shaders[1] = createShader(fs, GL_FRAGMENT_SHADER);
	}
	for(unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);										//Attach shader to program

   	glLinkProgram(m_program);															//Link Program to create shader
   	checkShaderError(m_program, GL_LINK_STATUS, true, "Error linking shader program");

   	glValidateProgram(m_program);														//Validate if shader is valid
   	checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Error validating shader program");

}

std:: string Shader::loadShader(const std::string &filename)						//File to read Shader
{
	std::ifstream file;
	file.open((filename).c_str());
	std::string output, line;
	if(file.is_open())
	{
		while(file.good())
		{
			getline(file, line);
			output.append(line + '\n');
		}
	}
	else
	{
		std::cerr<<"Unable to load shader file"<<std::endl;
	}
	return output;
}

void Shader:: bind()															//Bind Shader program to main
{
	glUseProgram(m_program);
}

void Shader:: checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024];
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);
	if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }

}

GLuint Shader:: createShader(const std::string& text, unsigned int type)
{
	 GLuint shader = glCreateShader(type);
	 if (shader == 0)
	 {
	 	std::cerr << "Error creating shader type " << type << std::endl;
	 }
	 const GLchar* p[1];
	 p[0] = text.c_str();
  	 glShaderSource(shader, 1, p, NULL);																//Take shader source file as IP
  	 glCompileShader(shader);																			//Compile Shader source code
  	 checkShaderError(shader, GL_COMPILE_STATUS, false, "Error Compiling Shader!");
  	 return shader;

}

Shader:: ~Shader()
{
	for(unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(m_program, m_shaders[i]);														//Detach and Delete
        glDeleteShader(m_shaders[i]);
    }
	glDeleteProgram(m_program);
}