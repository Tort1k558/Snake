#pragma once
#include<vector>
#include"PieceSnake.h"
#include"Apple.h"
#include"../Renderer/Sprite.h"

class Apple;
enum class DirectionSnake {
	Left =0,
	Right,
	Up,
	Down
};

class Snake {
public:
	Snake(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 windowSize, glm::vec2 position);

	void render();
	void update(double delta, DirectionSnake direction);
	void setDirection(DirectionSnake direction);
	void checkColisionWithApple(Apple &apple);
private:
	void addPieceSnake(std::shared_ptr<ShaderProgram> pShaderProgram, glm::vec2 size, glm::vec2 position);
	void checkColision();
	void destroySnake();
	std::vector<PieceSnake> m_piecesSnake;
	PieceSnake m_headSnake;
	DirectionSnake m_directionSnake;

	std::shared_ptr<ShaderProgram> m_pShaderProgram;
	glm::vec2 m_windowSize;
	double m_time1s = 0.0;
};