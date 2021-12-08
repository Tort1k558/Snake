#include "PieceSnake.h"
#include<memory>
PieceSnake::PieceSnake(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 windowSize, glm::vec2 position):
	m_position(position),
	m_size(windowSize / 25.0f)
{
	std::shared_ptr<Texture> pTexture = std::make_shared<Texture>("snake.jpeg");
	m_pSprite = std::make_shared<Sprite>(pTexture, pShaderProgram, m_size, position);
}
void PieceSnake::render()
{
	m_pSprite->render();
}
void PieceSnake::update(double delta)
{

}
void PieceSnake::setPosition(const glm::vec2& position)
{
	m_position = position;
	m_pSprite->setPosition(m_position);
}