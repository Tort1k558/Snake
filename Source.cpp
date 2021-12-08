#include<glad/glad.h>
#include<GLFW/glfw3.h>



#include<iostream>
#include<memory>
#include<chrono>

#include"src/Renderer/ShaderProgram.h"
#include"src/Renderer/Texture.h"
#include"src/Renderer/Sprite.h"

#include"src/GameObjects/Snake.h"
#include"src/GameObjects/Apple.h"
#include<glm/vec2.hpp>

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void glfwWindowSizeCallback(GLFWwindow* pwindow, int widht, int height);

glm::ivec2 g_windowSize(600,600);

DirectionSnake dirSnake;

int main(int argc, char* argv[])
{
	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* pWindow = glfwCreateWindow(g_windowSize.x, g_windowSize.y, "My OpenGL program", nullptr, nullptr);
	glfwMakeContextCurrent(pWindow);
	glfwSetKeyCallback(pWindow, keyCallBack);
	glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "FAILED INITIALIZE GLAD!" << std::endl;
	}
	glViewport(0, 0, g_windowSize.x, g_windowSize.y);
	
	std::shared_ptr<ShaderProgram> pShaderProgram = std::make_shared<ShaderProgram>("res\\Shaders\\vShader.vs", "res\\Shaders\\fShader.fs");
	
	Snake snake(pShaderProgram, g_windowSize, glm::vec2(g_windowSize.x / 2, g_windowSize.y / 2));
	Apple apple(pShaderProgram, g_windowSize);

	glm::mat4 projection = glm::ortho(0.f, static_cast<float>(g_windowSize.x), 0.f, static_cast<float>(g_windowSize.y), -100.f, 100.f);
	pShaderProgram->setUniformMatrix4(projection, "projection");


	auto lastTime = std::chrono::high_resolution_clock::now();
	while (!glfwWindowShouldClose(pWindow))
	{
		glClearColor(0.3f, 0.7f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		auto currentTime = std::chrono::high_resolution_clock::now();
		double duration = std::chrono::duration<double, std::milli>(currentTime - lastTime).count();
		lastTime = currentTime;

		apple.render();
		snake.checkColisionWithApple(apple);
		snake.update(duration,dirSnake);
		snake.render();

		glfwPollEvents();
		glfwSwapBuffers(pWindow);
	}
	glfwTerminate();
	return 0;
}
void keyCallBack(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(pWindow, true);
		}
		break;
	case GLFW_KEY_DOWN:
		if (action == GLFW_PRESS)
		{
			dirSnake=DirectionSnake::Down;
		}
		break;
	case GLFW_KEY_UP:
		if (action == GLFW_PRESS)
		{
			dirSnake = DirectionSnake::Up;
		}
		break;
	case GLFW_KEY_LEFT:
		if (action == GLFW_PRESS)
		{
			dirSnake = DirectionSnake::Left;
		}
		break;
	case GLFW_KEY_RIGHT:
		if (action == GLFW_PRESS)
		{
			dirSnake = DirectionSnake::Right;
		}
		break;
	}
}
void glfwWindowSizeCallback(GLFWwindow* pwindow, int width, int height)
{
	g_windowSize.x = width;
	g_windowSize.y = height;

	glViewport(0, 0, g_windowSize.x, g_windowSize.y);
}