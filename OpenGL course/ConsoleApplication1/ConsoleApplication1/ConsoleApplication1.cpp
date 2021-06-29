#pragma once
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
//#include<GL/glew.h>
#include <iostream>
#include<stdio.h>
#include "Floor.h"
#include "Tree.h"
#include "Camera.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

//#include "Window.h"
using namespace std;

//window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;

//GLuint shader, shader2, VAO3;

unsigned int texture2;
Floor chao;
Tree arvore;
//Window janela;

const unsigned int width = 800;
const unsigned int height = 600;


//void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
//{
//	GLuint theShader = glCreateShader(shaderType);
//
//	const GLchar* theCode[1];
//	theCode[0] = shaderCode;
//
//	GLint  codeLength[1];
//	codeLength[0] = strlen(shaderCode);
//
//	glShaderSource(theShader, 1, theCode, codeLength);
//	glCompileShader(theShader);
//
//	GLint result = 0;
//	GLchar eLog[1024] = { 0 };
//
//	
//	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
//		cout << "Erron compiling the shader " << endl << shaderType << eLog;
//		return;
//	}
//
//	glAttachShader(theProgram, theShader);
//
//}

//void compileShaders() {
//	shader = glCreateProgram();
//	shader2 = glCreateProgram();
//	if (!shader)
//	{
//		cout << "error creating shader program" << endl;
//		return;
//	}
//
//	AddShader(shader, vShader, GL_VERTEX_SHADER);
//	AddShader(shader, fShader, GL_FRAGMENT_SHADER);
//
//	AddShader(shader2, fShader2, GL_FRAGMENT_SHADER);
//	AddShader(shader2, vShader2, GL_VERTEX_SHADER);
//
//	GLint result = 0;
//	GLchar eLog[1024] = { 0 };
//
//	glLinkProgram(shader);
//	glGetProgramiv(shader, GL_LINK_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		cout << "Erron linking program" << endl << eLog;
//		return;
//	}
//
//	glValidateProgram(shader);
//	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		cout << "Erron validating program" << endl << eLog;
//		return;
//	}
//
//
//	glLinkProgram(shader2);
//	glGetProgramiv(shader2, GL_LINK_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader2, sizeof(eLog), NULL, eLog);
//		cout << "Erron linking program" << endl << eLog;
//		return;
//	}
//
//	glValidateProgram(shader2);
//	glGetProgramiv(shader2, GL_VALIDATE_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader2, sizeof(eLog), NULL, eLog);
//		cout << "Erron validating program" << endl << eLog;
//		return;
//	}
//
//}

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

int main()
{

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "Sombra", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	////initialize GLFW (pra fazer window)
	//janela = Window(600, 800);
	//janela.Init();

	Shader shaderProgram("default.vert", "default.frag");

	//alocar memoria de UM VAO e dar o bind nele
	VAO vao;
	vao.Bind();

	chao.CreateTriangle1(vao);
	chao.GenTexture();


	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);
	//loop until window closed

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	while (!glfwWindowShouldClose(window))
	{
		// get and handle user input events
		glfwPollEvents();


		//clear window
		glClearColor(0.5f,0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");
		vao.Bind();

		//bind ta texture
		glBindTexture(GL_TEXTURE_2D, chao.getTexture());
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);


		//glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();


    std::cout << "Hello World!\n";
	return 0;
}

