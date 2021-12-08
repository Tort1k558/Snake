#include "VBO.h"

VBO::VBO():
	m_id(0)
{
}
VBO::~VBO()
{
	glDeleteBuffers(1, &m_id);
}
void VBO::init(const void* data,const unsigned int size)
{
	glGenBuffers(1, &m_id);
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	unbind();
}
void VBO::update(const void* data, const unsigned int size)
{
	bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	unbind();
}
void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}
void VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
