#pragma once

#include<glm/vec2.hpp>

#include"../Renderer/Sprite.h"
#include"Snake.h"
class Apple
{
public:
	Apple(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 windowSize);
	void render();

	void setPosition(const glm::vec2& position);
	glm::vec2 getPosition() { return m_position; }
	glm::vec2 getSize() { return m_size; }
	glm::vec2 getRandomPosition();
private:
	glm::vec2 m_position;
	glm::vec2 m_windowSize;
	glm::vec2 m_size;
	std::shared_ptr<Sprite> m_pSprite;
};

