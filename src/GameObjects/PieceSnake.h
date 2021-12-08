#pragma once
#include<memory>
#include"../Renderer/Sprite.h"

class PieceSnake
{
public:
	PieceSnake(std::shared_ptr<ShaderProgram> pShaderProgram,glm::vec2 windowSize, glm::vec2 position);

	void render();
	void update(double delta);

	void setPosition(const glm::vec2& position);
	glm::vec2 getPosition()const { return m_position;}
	glm::vec2 getSize()const { return m_size; }

private:
	std::shared_ptr<Sprite> m_pSprite;
	glm::vec2 m_size;
	glm::vec2 m_position;
};

