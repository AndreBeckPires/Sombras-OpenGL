
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include<stdio.h>
#include "Floor.h"
#include "Tree.h"
#include "Window.h"
using namespace std;

//window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;

GLuint shader, shader2, VAO3;

unsigned int texture2;
Floor chao;
Tree arvore;
Window janela;




void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint theShader = glCreateShader(shaderType);

	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint  codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(theShader, 1, theCode, codeLength);
	glCompileShader(theShader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
		cout << "Erron compiling the shader " << endl << shaderType << eLog;
		return;
	}

	glAttachShader(theProgram, theShader);

}

void compileShaders() {
	shader = glCreateProgram();
	shader2 = glCreateProgram();
	if (!shader)
	{
		cout << "error creating shader program" << endl;
		return;
	}

	AddShader(shader, vShader, GL_VERTEX_SHADER);
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);

	AddShader(shader2, fShader2, GL_FRAGMENT_SHADER);
	AddShader(shader2, vShader2, GL_VERTEX_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(shader);
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		cout << "Erron linking program" << endl << eLog;
		return;
	}

	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		cout << "Erron validating program" << endl << eLog;
		return;
	}


	glLinkProgram(shader2);
	glGetProgramiv(shader2, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader2, sizeof(eLog), NULL, eLog);
		cout << "Erron linking program" << endl << eLog;
		return;
	}

	glValidateProgram(shader2);
	glGetProgramiv(shader2, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader2, sizeof(eLog), NULL, eLog);
		cout << "Erron validating program" << endl << eLog;
		return;
	}

}


int main()
{
	//initialize GLFW (pra fazer window)
	janela = Window(600, 800);
	janela.Init();
	chao.CreateTriangle1();
	arvore.CreateTriangle1();


	chao.GenTexture();
	arvore.GenTexture();
	compileShaders();


	//loop until window closed
	while (!janela.shouldClose())
	{
		// get and handle user input events
		glfwPollEvents();


		//clear window
		glClearColor(0.0f,0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);
		//bind ta texture
		glBindTexture(GL_TEXTURE_2D, chao.getTexture());
		glBindVertexArray(chao.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		glUseProgram(0);

		glUseProgram(shader2);


		//bind ta texture
		glUseProgram(shader2);
		glBindTexture(GL_TEXTURE_2D, arvore.getTexture());
		glBindVertexArray(arvore.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);






		glUseProgram(0);

		janela.swapBuffers();
	}


    std::cout << "Hello World!\n";
	return 0;
}

