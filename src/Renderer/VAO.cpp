#include"VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &m_id);
}
VAO::~VAO()
{
	glDeleteVertexArrays(1, &m_id);
}
void VAO::addBuffer(VBO& vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
	bind();
	vbo.bind();
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
	unbind();
}
void VAO::bind()
{
	glBindVertexArray(m_id);
}
void VAO::unbind()
{
	glBindVertexArray(0);
}