#include "Apple.h"
#include "../Renderer/Texture.h"

#include<ctime>
Apple::Apple(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 windowSize)
	:
	m_size(m_windowSize / 20.0f),
	m_windowSize(windowSize)
{
	std::shared_ptr<Texture> pTexture = std::make_shared<Texture>("Apple.jpg");
	m_position = getRandomPosition();
	m_pSprite = std::make_shared<Sprite>(pTexture, pShaderProgram,m_size, m_position);
}
void Apple::render()
{
	m_pSprite->render();
}

void Apple::setPosition(const glm::vec2& position)
{
	m_position = position;
	m_pSprite->setPosition(position);
}
glm::vec2 Apple::getRandomPosition()
{
	srand(static_cast<unsigned int>(time(0)));
	glm::vec2 randVecPosition(rand() % static_cast<int>(m_windowSize.x-20), rand() % static_cast<int>(m_windowSize.y-20));
	if (randVecPosition.x < 30.0f)
	{
		randVecPosition.x += 30.0f;
	}
	else if (randVecPosition.y < 30.0f)
	{
		randVecPosition.y += 30.0f;
	}
	return randVecPosition;
}
