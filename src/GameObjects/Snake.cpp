#include "Snake.h"
#include<iostream>
Snake::Snake(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 windowSize, glm::vec2 position):
	m_pShaderProgram(pShaderProgram),
	m_windowSize(windowSize),
	m_headSnake(pShaderProgram, windowSize,position),
	m_directionSnake(DirectionSnake::Up)
{
	m_piecesSnake.push_back(m_headSnake);
	addPieceSnake(pShaderProgram, m_windowSize,position);
}

void Snake::render()
{
	for (size_t i = 0; i < m_piecesSnake.size(); i++)
	{
		m_piecesSnake[i].render();
	}
}
void Snake::update(double delta, DirectionSnake direction)
{
	m_time1s += delta;
	if (m_time1s >= 500.0)
	{
		setDirection(direction);
		m_piecesSnake[0].setPosition(m_headSnake.getPosition());
		for (size_t i = m_piecesSnake.size()-1; i > 0; i--)
		{
			m_piecesSnake[i].setPosition(m_piecesSnake[i - 1].getPosition());
		}
		switch (m_directionSnake)
		{
		case DirectionSnake::Left:
			m_headSnake.setPosition(glm::vec2(m_headSnake.getPosition().x - m_headSnake.getSize().x,
									m_headSnake.getPosition().y));
			break;
		case DirectionSnake::Right:
			m_headSnake.setPosition(glm::vec2(m_headSnake.getPosition().x + m_headSnake.getSize().x,
				m_headSnake.getPosition().y));
			break;
		case DirectionSnake::Up:
			m_headSnake.setPosition(glm::vec2(m_headSnake.getPosition().x,
									m_headSnake.getPosition().y + m_headSnake.getSize().y));
			break;
		case DirectionSnake::Down:
			m_headSnake.setPosition(glm::vec2(m_headSnake.getPosition().x,
				m_headSnake.getPosition().y - m_headSnake.getSize().y));
			break;
		}
		checkColision();
		m_time1s = 0.0;
	}
}
void Snake::setDirection(DirectionSnake direction)
{
	if (m_directionSnake == DirectionSnake::Left && direction == DirectionSnake::Right)
	{
		return;
	}
	if (m_directionSnake == DirectionSnake::Right && direction == DirectionSnake::Left)
	{
		return;
	}
	if (m_directionSnake == DirectionSnake::Up && direction == DirectionSnake::Down)
	{
		return;
	}
	if (m_directionSnake == DirectionSnake::Down && direction == DirectionSnake::Up)
	{
		return;
	}
	m_directionSnake = direction;
}
void Snake::addPieceSnake(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 size, glm::vec2 position)
{
	PieceSnake pieceSnake(pShaderProgram, size, position);
	m_piecesSnake.push_back(pieceSnake);
}
void Snake::checkColision()
{
	if ((m_headSnake.getPosition().y- 10.f)<0.0f|| (m_headSnake.getPosition().x - 10.f)<0.0f)
	{
		destroySnake();
	}
	else if ((m_headSnake.getPosition().y + 10.f) > m_windowSize.y || (m_headSnake.getPosition().x + 10.f) > m_windowSize.x)
	{
		destroySnake();
	}
	for (size_t i = 1; i < m_piecesSnake.size()-1; i++)
	{
		if (m_headSnake.getPosition()==m_piecesSnake[i].getPosition())
		{
			destroySnake();
		}
	}
}
void Snake::checkColisionWithApple(Apple& apple)
{
	glm::vec2 bottomLeft = apple.getPosition() - apple.getSize();
	glm::vec2 topRight = apple.getPosition() + apple.getSize();
	//Check colision with apple
	if ((topRight.x >= m_headSnake.getPosition().x && topRight.y >= m_headSnake.getPosition().y)&&(bottomLeft.x <= m_headSnake.getPosition().x && bottomLeft.y <= m_headSnake.getPosition().y))
	{
		addPieceSnake(m_pShaderProgram, m_windowSize,m_headSnake.getPosition());
		apple.setPosition(apple.getRandomPosition());
	}
}
void Snake::destroySnake()
{
	m_piecesSnake.clear();
	m_headSnake.setPosition(m_windowSize / 2.f);
	m_piecesSnake.push_back(m_headSnake);
	addPieceSnake(m_pShaderProgram, m_windowSize, m_headSnake.getPosition());
}