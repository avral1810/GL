#include "texture.h"

Texture:: Texture(const std::string& filename)
{
	int width, height, numComponents;
	unsigned char *imageData = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);

	if(imageData == NULL)
		std::cerr << "Unable to load texture: " << filename << std::endl;


	glGenTextures(1, &m_texture);												//generate
	glBindTexture(GL_TEXTURE_2D, m_texture);									//put in memory

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);				//Texture wrapping, location outside, go back or what (width)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);				// (height)

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);			//What to do when, size doesn't match, minimize filter, fewer, linear zoom
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);			//magnify filter, fewer, linear zoom (what type)

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData); 
    			//which, level (Which mag image to use when), individual (store) format, w, h, border(0/1) +2 to w and h, how to send data, (store how), what image


	stbi_image_free(imageData);
}

void Texture:: bind(unsigned int num)
{
	assert (num >=0 && num <= 31);
	glActiveTexture(GL_TEXTURE0 + num);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}

Texture:: ~Texture()
{
	glDeleteTextures(1, &m_texture);
}