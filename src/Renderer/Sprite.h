#pragma once
#include<string>
#include<memory>

#include<glad/glad.h>

#include"ShaderProgram.h"
#include"VBO.h"
#include"VAO.h"
#include"Texture.h"

#include<glm/mat4x4.hpp>
#include<glm/vec2.hpp>
#include<glm/gtc/matrix_transform.hpp>
class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> pTexture,std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 size, glm::vec2 position);
	Sprite() = delete;

	void render();

	void setPosition(const glm::vec2& position);
	void setSize(const glm::vec2& size);
private:
	std::shared_ptr<Texture> m_pTexture;
	std::shared_ptr<ShaderProgram> m_pShaderProgram;
	glm::vec2 m_size;
	glm::vec2 m_position;
	VAO m_VAO;
	VBO m_VBO;
	GLuint m_EBO[6] =
	{
		0,1,2,
		1,2,3
	};
};

