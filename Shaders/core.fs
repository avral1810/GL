#version 330 core

varying vec3 ourColor;

void main()
{
	color = vec4(ourColor, 1.0f);
}
