#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> pTexture, std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 size, glm::vec2 position)
	: m_pTexture(pTexture),
	m_pShaderProgram(pShaderProgram),
	m_size(size),
	m_position(position)
{
	GLfloat verticles[] =
	{
		 //Vertex		 //TexCoords
		-0.5f,-0.5f,0.f, 0.0f,0.0f,
		-0.5f, 0.5f,0.f, 0.0f,1.0f,
		 0.5f,-0.5f,0.f, 1.0f,0.0f,
		 0.5f, 0.5f,0.f, 1.0f,1.0f
	};

	
	m_VBO.init(verticles, sizeof(verticles));
	m_VAO.addBuffer(m_VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), nullptr);
	m_VAO.addBuffer(m_VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
}
void Sprite::render()
{
	glActiveTexture(GL_TEXTURE0);
	m_pTexture->bind();
	m_pShaderProgram->use();
	m_VAO.bind();

	glm::mat4 model(1.f);
	model = glm::translate(model, glm::vec3(m_position, 0.f));
	model = glm::translate(model, glm::vec3(0.5 * m_size.x, 0.5 * m_size.y, 0.f));
	model = glm::translate(model, glm::vec3(-0.5 * m_size.x, -0.5 * m_size.y, 0.f));
	model = glm::scale(model, glm::vec3(m_size, 1.f));
	m_pShaderProgram->setUniformMatrix4(model, "model");

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_EBO);
}


void Sprite::setPosition(const glm::vec2& position)
{
	m_position = position;
}
void Sprite::setSize(const glm::vec2& size)
{
	m_size = size;
}