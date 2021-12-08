#pragma once
#include<glad/glad.h>
class VBO
{
public:
	VBO();
	~VBO();
	void init(const void* data, const unsigned int size);
	void update(const void* data, const unsigned int size);
	void bind();
	void unbind();

private:
	GLuint m_id;
};

