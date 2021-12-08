#pragma once
#include<GLAD/glad.h>
#include<string>
class Texture
{
public:
	Texture(std::string nameTexture);
	Texture() = delete;

	void bind() const;
private:
	GLuint m_id;
};

