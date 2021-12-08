#include"ShaderProgram.h"

#include<fstream>
#include<sstream>
#include<iostream>

#include<glm/gtc/type_ptr.hpp>
ShaderProgram::ShaderProgram(std::string vertexPath, std::string fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);

    std::stringstream vShaderStream,fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    
    vShaderFile.close();
    fShaderFile.close();
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
    
	const char* vertexShaderCode = vertexCode.c_str();
	const char* fragmentShaderCode = fragmentCode.c_str();
	GLuint vertexShader, fragmentShader;
	int success;
	char infoLog[512];
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::VERTEX::SHADER::COMPILATION_FAILED!\n" << infoLog << std::endl;
	}
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::FRAGMENT::SHADER::COMPILATION_FAILED!\n" << infoLog << std::endl;
	}
	m_id = glCreateProgram();
	glAttachShader(m_id, vertexShader);
	glAttachShader(m_id, fragmentShader);
	glLinkProgram(m_id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::use() const
{
	glUseProgram(m_id);
}
void ShaderProgram::setUniformMatrix4(glm::mat4& matrix,std::string name) const
{
	use();
	glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE,glm::value_ptr(matrix));
}