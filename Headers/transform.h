#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include<GLUT/GLUT.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <iostream>
#include <string>
#include <fstream>

class Transform
{
	glm::vec3 m_translate, m_scale, m_rot;

public:
	Transform(const glm::vec3 &translate = glm::vec3(), const glm::vec3 &rot = glm::vec3(), const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f)):
	m_translate(translate),
	m_rot(rot),
	m_scale(scale) {}

	inline glm::vec3 getTranslate()	{ return m_translate; }
	inline glm::vec3 getRot()	{ return m_rot; }
	inline glm::vec3 getScale()	{ return m_scale; }

	inline void setTranslate(glm::vec3 &translate) { this->m_translate = translate; }
	inline void setRot(glm::vec3 &rot) { this->m_rot = rot; }
	inline void setScale(glm::vec3 &scale) { this->m_scale = scale; }

	inline glm::mat4 getModel() const
	{
		glm::mat4 translateMatrix = glm::translate(m_translate);
		glm::mat4 scaleMatrix = glm::scale(m_scale);
		glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0.0f, 0.0f, 1.0f));

		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return translateMatrix * rotMatrix * scaleMatrix;
	}

};
