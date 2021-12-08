#include<iostream>

#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include"../../Libs/stb_image.h"
Texture::Texture(std::string nameTexture)
{
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);

	int width, height, nrChannels;
	std::string pathTexture = "res\\textures\\" + nameTexture;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(pathTexture.c_str(), &width, &height, &nrChannels, 0);
	if (!data)
	{
		std::cerr<<"ERROR::FAILED TO LOAD TEXTURE!"<<std::endl;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
}
void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}