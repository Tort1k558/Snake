#pragma once
#include<glad/glad.h>
#include"VBO.h"
class VAO
{
public:
	VAO();
	~VAO();
	
	void addBuffer(VBO& vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	void bind();
	void unbind();

private:
	GLuint m_id;
};

