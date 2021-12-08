#pragma once
#include<string>
#include<glad/glad.h>

#include<glm/mat4x4.hpp>
class ShaderProgram
{
public:
	ShaderProgram(std::string vertexPath, std::string fragmentPath);
	
	void use() const;
	void setUniformMatrix4(glm::mat4 &matrix, std::string name) const;
private:
	GLuint m_id;
};